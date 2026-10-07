"""Verify functions from the LTCG-linked build/match.dll against COGMIND.exe.
   Instruction bytes must be identical except address operands, which must resolve
   to the same thing on both sides:
     - named function/global (exe: config/mapping.csv + globals.csv, ours: build/match.map)
     - same import (IAT slot name)
     - jump within the function to the same relative offset
     - otherwise, unnamed data: the bytes at both addresses must be equal
   usage: lverify.py [-v] [name-substring ...]"""
import sys, os, re, struct, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import pefile, capstone, common
from common import demangle

DLL = os.path.join(common.REPO, "build", "full", "match.dll")
MAP = os.path.join(common.REPO, "build", "full", "match.map")

class Image:
    def __init__(self, pe, names):
        self.pe, self.names = pe, names            # names: VA -> demangled name
        self.base = pe.OPTIONAL_HEADER.ImageBase
        self.lo, self.hi = self.base, self.base + pe.OPTIONAL_HEADER.SizeOfImage
        pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
        self.imps = {}
        for e in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
            for i in e.imports:
                if i.name: self.imps[i.address] = '__imp_' + i.name.decode()
        # Suffix pooling can put a literal operand inside a named constant.
        # Recognize only compiler string storage, never arbitrary zero-filled data.
        literals = {}
        for va, aliases in names.items():
            for name in aliases:
                if name.startswith('??_C@_0'):
                    literals[va] = max(literals.get(va, 0), const_len(name, self, va))
        self.literal_starts = sorted(literals)
        self.literal_ends = {va: va + n for va, n in literals.items()}
    def read(self, va, n):
        # Past a section's raw data (.bss tail) the loader zero-fills: read zeros, not b''.
        b = self.pe.get_data(va - self.base, n)
        if len(b) < n and self.lo <= va < self.hi: b += b'\0' * (n - len(b))
        return b
    def resolve(self, va):
        """set of names for the address (mangled + demangled where known), or None"""
        if va in self.imps: return {self.imps[va]}
        if va in self.names: return self.names[va]
        i = bisect.bisect_right(self.literal_starts, va) - 1
        if i >= 0 and va < self.literal_ends[self.literal_starts[i]]:
            return {'??_C@_0_pooled_suffix'}
        return None

MAP_ALL = []   # every (name, VA) in the last loaded map: TU-local statics (time.inl inlines, static helpers) recur

def load_map():
    out = {}; del MAP_ALL[:]
    for line in open(MAP, encoding='latin1'):
        m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', line)
        if m and int(m.group(2), 16):
            out[m.group(1)] = int(m.group(2), 16); MAP_ALL.append((m.group(1), int(m.group(2), 16)))
    return out

def const_len(name, img, va):
    """Byte length to compare for compiler-generated constants (floats, string literals)."""
    if not name: return 0
    if name.startswith('__real@'): return (len(name) - 7) // 2
    if name.startswith('__xmm@'): return 16
    if name.startswith('??_C@'):
        b = img.read(va, 4096); w = 2 if name.startswith('??_C@_1') else 1
        end = next(i for i in range(0, len(b), w) if b[i:i + w] == b'\0' * w)
        return end + w
    return 0

# ours symbol name <-> exe VA learned from otherwise-unnamed call/data targets. Must stay a
# bijection across the whole run; a conflict counts as a mismatch.
# (Many ours -> one exe VA is allowed: the game was linked with ICF, which folds identical
# functions; our build uses /OPT:NOICF.) Pairs are staged per function, committed on MATCH.
LEARN_FWD, STAGE = {}, {}
PAIRS, LAST_PAIRS = [], []   # (our target VA, exe target VA) for every operand that matched
LIT_STAGE, LITERALS, ALL_PAIRS = [], set(), set()   # (exe VA, length) of verified typed constants; all committed (our VA, exe VA) pairs
CTX = {}                     # last verify_all: (map, ours image, exe image)

def sym_key(names):
    mangled = [n for n in names if n.startswith(('?', '_'))]
    return sorted(mangled or names, key=len)[0]

def learn(oname_set, tva):
    """True if pairing our symbol with an unnamed exe address is consistent so far."""
    if not oname_set: return False
    key = sym_key(oname_set)
    if key.startswith(('__real@', '??_C@', '__xmm@')): return False
    prev = STAGE.get(key, LEARN_FWD.get(key))
    if prev is not None and prev != tva: return False
    STAGE[key] = tva
    return True

STRING_TYPE = 'basic_string@DU?$char_traits@D@std@@'

def string_constructor_argument(insns, index, image):
    """Recognize a literal that is the const char* argument of the next call, when that call is
    string(const char*), or any other std::string function taking const char* (operator+,
    operator==, assign...). The pushed pointer then names a C string and compares through its NUL,
    so a short literal pooled next to unrelated data (the exe pools "" and ")" that way) matches."""
    if insns[index].mnemonic != 'push': return False
    for ins in insns[index + 1:index + 7]:
        if ins.mnemonic != 'call':
            continue
        if ins.operands[0].type != capstone.x86.X86_OP_IMM: return False
        names = image.resolve(ins.operands[0].imm & 0xffffffff) or ()
        return any(STRING_TYPE in n and 'PBD' in n for n in names)
    return False

def operand_fields(ins):
    """(offset, size, value, is_rel) of every operand field that could be an address."""
    f = []
    if ins.disp_size == 4: f.append((ins.disp_offset, 4, ins.disp & 0xffffffff, False))
    if ins.imm_size == 4:
        for op in ins.operands:
            if op.type == capstone.x86.X86_OP_IMM:
                rel = capstone.x86.X86_GRP_JUMP in ins.groups or capstone.x86.X86_GRP_CALL in ins.groups
                f.append((ins.imm_offset, 4, op.imm & 0xffffffff, rel))
    return f

def compare(name, theirs, tva, ours, ova, size, verbose):
    STAGE.clear(); del PAIRS[:]; del LIT_STAGE[:]
    ok = _compare(name, theirs, tva, ours, ova, size, verbose)
    if ok: LEARN_FWD.update(STAGE); ALL_PAIRS.update(PAIRS); LITERALS.update(LIT_STAGE)
    LAST_PAIRS[:] = PAIRS if ok else []
    return ok

def inline_table_offset(insns, va, size):
    """Trailing /Od switch tables: dword jump tables addressed by jmp [index*4 + table], each
    optionally followed by the byte index table of a sparse switch (movzx reg, byte [index + bytes]).
    Several switches put their tables back to back. Returns [(offset, end, is_dword)] covering
    everything from the first table to the end of the function, or None."""
    jumps, bytes_ = set(), set()
    for ins in insns:
        if ins.address >= va + size: break
        if ins.mnemonic not in ('jmp', 'movzx'): continue
        for op in ins.operands:
            if op.type != capstone.x86.X86_OP_MEM: continue
            mem = op.mem
            off = (mem.disp & 0xffffffff) - va
            if not (ins.address + ins.size <= va + off < va + size): continue
            if ins.mnemonic == 'jmp' and not mem.base and mem.index and mem.scale == 4: jumps.add(off)
            if ins.mnemonic == 'movzx' and op.size == 1 and bool(mem.base) != bool(mem.index) and mem.scale == 1: bytes_.add(off)
    if not jumps: return None
    starts = sorted(jumps | {o for o in bytes_ if o > min(jumps)})
    if starts[0] not in jumps: return None
    tables = []
    for k, off in enumerate(starts):
        end = starts[k + 1] if k + 1 < len(starts) else size
        if off in jumps and (end - off) % 4: return None
        tables.append((off, end, off in jumps))
    return tables

def _compare(name, theirs, tva, ours, ova, size, verbose):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    ti = list(md.disasm(theirs.read(tva, size), tva))
    oi = list(md.disasm(ours.read(ova, size + 64), ova))
    problems = []
    table = inline_table_offset(ti, tva, size)
    code_size = size if table is None else table[0][0]
    if table is not None:
        tables, table = table, table[0][0]
        if inline_table_offset(oi, ova, size) != tables:
            problems.append("switch table offset differs")
        ti = [i for i in ti if i.address < tva + table]
        oi = [i for i in oi if i.address < ova + table]
        boundaries = {i.address - tva for i in ti}
        for start, end, is_dword in tables:
            if not is_dword and theirs.read(tva + start, end - start) != ours.read(ova + start, end - start):
                problems.append("switch index table differs at +%#x" % start)
        for off in (o for start, end, is_dword in tables if is_dword for o in range(start, end, 4)):
            ta = struct.unpack('<I', theirs.read(tva + off, 4))[0] - tva
            oa = struct.unpack('<I', ours.read(ova + off, 4))[0] - ova
            if ta != oa or ta not in boundaries:
                problems.append("switch target differs or is invalid at +%#x" % off)
    for k, a in enumerate(ti):
        if k >= len(oi): problems.append("ours is shorter"); break
        b = oi[k]
        line = "%04x  %-28s | %s" % (a.address - tva, a.mnemonic + ' ' + a.op_str, b.mnemonic + ' ' + b.op_str)
        if a.size != b.size or a.mnemonic != b.mnemonic:
            problems.append(line); continue
        ab, bb = bytearray(a.bytes), bytearray(b.bytes)
        for (off, sz, av, rel), (_, _, bv, _) in zip(operand_fields(a), operand_fields(b)):
            in_t = theirs.lo <= av < theirs.hi; in_o = ours.lo <= bv < ours.hi
            if tva <= av < tva + size and ova <= bv < ova + size:
                same = av - tva == bv - ova
            elif rel:
                if tva <= av < tva + size and ova <= bv < ova + size + 64:
                    same = av - tva == bv - ova
                else:
                    rt, ro = theirs.resolve(av), ours.resolve(bv)
                    same = bool((rt or set()) & (ro or set())) if rt else learn(ro, av)
                    # The exe was linked with ICF: one address serves every identical function, so
                    # naming one alias (XConsole::getParent) must not break callers that reach the same
                    # body under another name (Array2D::getHeight). When the names don't overlap, fall
                    # back to the same consistent-pairing rule used for unnamed targets.
                    if not same and rt and ro: same = learn(ro, av)
            elif in_t and in_o:
                rt, ro = theirs.resolve(av), ours.resolve(bv)
                n = max([const_len(x, ours, bv) for x in (ro or ())] or [0])
                # A named variable (e.g. a global std::string pushed before operator+) is not a literal.
                named = any(not x.startswith('??_C@') for x in (ro or ()))
                if not n and not named and string_constructor_argument(oi, k, ours):
                    n = const_len('??_C@_0_argument', ours, bv)
                if n:
                    same = theirs.read(av, n) == ours.read(bv, n)   # typed string/constant: compare contents
                    if same: LIT_STAGE.append((av, n))
                elif rt: same = bool(rt & (ro or set()))
                elif ro and not any(x.startswith('__real@') or x.startswith('??_C@') for x in ro): same = learn(ro, av)
                else:   # Compare the complete memory operand; pointer arguments need eight bytes.
                    width = next((op.size for op in a.operands if op.type == capstone.x86.X86_OP_MEM), 8)
                    same = theirs.read(av, width) == ours.read(bv, width)
                    if not same and not any(op.type == capstone.x86.X86_OP_MEM for op in a.operands):
                        # Unnamed pointer operand into .rdata on both sides that reads as text: a C string
                        # literal, which the linker pools next to unrelated data. Compare through its NUL.
                        tn, on = rdata_text_len(theirs, av), rdata_text_len(ours, bv)
                        if tn and tn == on and theirs.read(av, tn) == ours.read(bv, on):
                            same = True; LIT_STAGE.append((av, tn))
            else:
                same = av == bv
            if same:
                ab[off:off + sz] = bb[off:off + sz] = b'\0' * sz
                if in_t and in_o and not (tva <= av < tva + size): PAIRS.append((bv, av))
        if ab != bb: problems.append(line)
    else:
        if ti and oi[len(ti) - 1].address + oi[len(ti) - 1].size - ova != code_size:
            problems.append("size differs")
    ok = not problems
    print("%-52s %s" % (name, "MATCH" if ok else "DIFF  (%d insns differ)" % len(problems)))
    if verbose or not ok:
        for p in problems[:40]: print("      " + p)
    return ok

def rdata_text_len(img, va):
    """Length including the NUL if va is inside .rdata and starts a printable C string (<= 512 bytes), else 0."""
    if not any(s.Name.rstrip(b'\0') == b'.rdata' and img.base + s.VirtualAddress <= va < img.base + s.VirtualAddress + s.Misc_VirtualSize
               for s in getattr(img.pe, "sections", ())): return 0
    b = img.read(va, 512); end = b.find(b'\0')
    if end < 0 or any(not (32 <= c < 127 or c in (9, 10, 13)) for c in b[:end]): return 0
    return end + 1

def is_stub(img, va):
    """A name that exists in our link only as a generated stub (zero-filled data), not as code."""
    return img.read(va, 16) == b'\0' * 16

def code_names(mp, img):
    """name (mangled and demangled) -> VA, preferring real code over stubs/data with that name"""
    t = [x for x in img.pe.sections if x.Name.rstrip(b'\0') == b'.text'][0]
    lo = img.base + t.VirtualAddress; hi = lo + t.Misc_VirtualSize
    out = {}
    for n, va in sorted(mp.items(), key=lambda kv: not (lo <= kv[1] < hi)):
        out.setdefault(n, va); out.setdefault(demangle(n), va)
    return out

def map_names(mp):
    """VA -> {mangled, demangled} for our linked image"""
    out = {}
    for n, va in mp.items(): out.setdefault(va, set()).update((n, demangle(n)))
    for n, va in MAP_ALL:
        if mp.get(n) is not None and va not in out: out[va] = {n, demangle(n)}   # other copies of a TU-local static
    return out

def exe_names():
    """VA -> {name as written in config, demangled form if it is mangled}"""
    out = {}
    for n, va in common.symbols().items(): out.setdefault(va, set()).update((n, demangle(n)))
    return out

def verify_all(args=(), verbose=False, quiet=False):
    """{mapping name: matched?} for every mapping.csv function present in our build"""
    import io, contextlib
    mp = load_map()
    ours = Image(pefile.PE(DLL), map_names(mp))
    theirs = Image(pefile.PE(common.EXE, fast_load=True), exe_names())
    CTX['v'] = (mp, ours, theirs)
    by_name = code_names(mp, ours)
    results = {}
    for name, (tva, size) in sorted(common.functions().items(), key=lambda x: x[1][0]):
        if args and not any(a in name for a in args): continue
        if name not in by_name or is_stub(ours, by_name[name]): continue
        if quiet:
            with contextlib.redirect_stdout(io.StringIO()):
                results[name] = compare(name, theirs, tva, ours, by_name[name], size, False)
        else:
            results[name] = compare(name, theirs, tva, ours, by_name[name], size, verbose)
    return results

def _sections(img, names):
    return [(img.base + s.VirtualAddress, s.Misc_VirtualSize, s.SizeOfRawData) for s in img.pe.sections if s.Name.rstrip(b'\0') in names]

def _union(intervals):
    total, end = 0, 0
    for lo, hi in sorted(intervals):
        lo = max(lo, end)
        if hi > lo: total += hi - lo; end = hi
    return total

def data_stats():
    """Data matched, from the last verify_all (call it first). Counted in exe .rdata/.data bytes, union of:
       - typed constants (string literals, floats) read by a MATCHED function, contents equal;
       - vtables whose every slot targets the same function as ours (same name, or consistently paired);
       - initialized globals paired by a MATCHED function, extent = distance to our next symbol, contents equal
         and non-zero (pointer-bearing objects differ by address, so they stay unmatched).
       Zero-initialized (.bss) globals are only counted as objects (zero_globals), never as bytes."""
    mp, ours, theirs = CTX['v']
    dsec = (b'.rdata', b'.data')
    tsec, osec = _sections(theirs, dsec), _sections(ours, dsec)
    def in_sec(secs, va): return any(lo <= va < lo + vs for lo, vs, _ in secs)
    def raw(secs, va): return any(lo <= va < lo + rs for lo, _, rs in secs)
    iv = {'literals': [], 'vtables': [], 'globals': []}
    for va, n in LITERALS:
        if in_sec(tsec, va): iv['literals'].append((va, va + n))
    # vtables: ours `X::`vftable'` <-> exe build/rtti.csv row with the same class and vtable offset 0
    ours_vt = {}
    for n, va in mp.items():
        if n.startswith('??_7') and n.endswith('6B@'): ours_vt.setdefault(demangle(n)[:-len("::`vftable'")], va)
    nvt = nvt_ok = 0
    rtti = os.path.join(common.REPO, 'build', 'rtti.csv')
    for line in open(rtti) if os.path.exists(rtti) else ():
        f = line.rstrip('\n').split(',')
        if len(f) < 7 or f[6] == 'lib' or f[2] != '0' or not f[5]: continue
        nvt += 1
        ova = ours_vt.get(f[0])
        if ova is None: continue
        slots = [int(x, 16) for x in f[5].split(';')]
        good, staged = True, {}
        for i, tva in enumerate(slots):
            ota = struct.unpack('<I', ours.read(ova + 4 * i, 4))[0]
            rt, ro = theirs.resolve(tva), ours.resolve(ota)
            if rt and ro and rt & ro: continue
            # same rule as call targets: the slot's symbol pairs consistently with this exe address (ICF aliases, unnamed exe functions)
            key = sym_key(ro) if ro else None
            if key is None or key.startswith(('__real@', '??_C@', '__xmm@')) or staged.get(key, LEARN_FWD.get(key, tva)) != tva: good = False; break
            staged[key] = tva
        if good:
            LEARN_FWD.update(staged)
            nvt_ok += 1; vt = int(f[1], 16); iv['vtables'].append((vt, vt + 4 * len(slots)))
    # globals paired by matched functions
    ovas = sorted({va for va in mp.values() if in_sec(osec, va)})
    zero = set()
    for ova, tva in ALL_PAIRS:
        if not (in_sec(osec, ova) and in_sec(tsec, tva)): continue
        i = bisect.bisect_right(ovas, ova)
        size = min((ovas[i] - ova) if i < len(ovas) else 4, 0x400)
        if size <= 0 or not (raw(osec, ova) and raw(tsec, tva)):
            zero.add(tva); continue
        a, b = ours.read(ova, size), theirs.read(tva, size)
        if a != b: continue
        if not any(a): zero.add(tva); continue
        iv['globals'].append((tva, tva + size))
    out = {k: _union(v) for k, v in iv.items()}
    out['total'] = _union([x for v in iv.values() for x in v])
    out['vtables_ok'], out['vtables_all'], out['zero_globals'] = nvt_ok, nvt, len(zero)
    return out

def main(args):
    global DLL, MAP
    verbose = '-v' in args; args = [a for a in args if a != '-v']
    if '--dir' in args:
        i = args.index('--dir'); d = args[i + 1]; del args[i:i + 2]
        DLL, MAP = os.path.join(d, 'match.dll'), os.path.join(d, 'match.map')
    results = verify_all(args, verbose)
    print("%d/%d match" % (sum(results.values()), len(results)))
    return 0 if results and all(results.values()) else 1

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
