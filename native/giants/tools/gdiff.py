"""Compare a reconstruction of a (giant) function against the exe, beyond try.sh's first 40 lines.
   usage: gdiff.py <ltcg outdir> 'Name=0xVA' [--all] [--sem]
     (build the outdir once with: .venv/bin/python tools/ltcg.py <outdir> file.cpp ...)
   default: lverify-style byte compare, ALL differing lines (--all) or first 200;
   --sem:   semantic check for non-matching reconstructions:
            * ordered callee sequence (exe vs ours, our names paired to exe VAs where known),
              aligned with difflib: missing / extra / reordered calls are listed;
            * multisets of string literals and float constants;
            * similarity ratio of the normalised instruction stream (mnemonic + operand kind).
   Exit 0 when byte-identical (default mode) or when the call sequences agree (--sem)."""
import sys, os, re, difflib, collections, struct
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', '..', 'tools')); sys.path.insert(0, HERE)
import pefile, capstone, common, lverify
from capstone import x86

def images(d):
    lverify.DLL, lverify.MAP = os.path.join(d, 'match.dll'), os.path.join(d, 'match.map')
    mp = lverify.load_map()
    ours = lverify.Image(pefile.PE(lverify.DLL), lverify.map_names(mp))
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names())
    return mp, ours, theirs, lverify.code_names(mp, ours)

def extent(img, va, limit):
    """recursive-descent extent of a function in an image"""
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    seen, work, ins = set(), [va], {}
    while work:
        a = work.pop()
        while a not in seen and va <= a < va + limit:
            seen.add(a)
            i = next(md.disasm(img.read(a, 16), a)); ins[a] = i
            m = i.mnemonic
            if m in ('ret', 'retn'): break
            if m.startswith('j'):
                op = i.operands[0]
                if op.type == x86.X86_OP_IMM:
                    work.append(op.imm & 0xffffffff)
                    if m == 'jmp': break
                elif op.type == x86.X86_OP_MEM and op.mem.scale == 4 and not op.mem.base:
                    t = op.mem.disp & 0xffffffff
                    while True:
                        v = struct.unpack('<I', img.read(t, 4))[0]
                        if not (va <= v < va + limit): break
                        work.append(v); t += 4
                    break
                else: break
            a += i.size
    return [ins[a] for a in sorted(ins)]

def callname(img, i, names_pref):
    op = i.operands[0]
    if op.type == x86.X86_OP_IMM: t = op.imm & 0xffffffff
    elif op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index: t = op.mem.disp & 0xffffffff
    else: return 'indirect:' + re.sub(r'0x[0-9a-f]+', 'N', i.op_str)
    n = img.resolve(t)
    if not n: return '%#x' % t
    return names_pref(n, t)

def call_targets(img, ins):
    """[(target VA or None, names set or None, text)] for every call"""
    out = []
    for i in ins:
        if i.mnemonic != 'call': continue
        op = i.operands[0]
        if op.type == x86.X86_OP_IMM: t = op.imm & 0xffffffff
        elif op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index: t = op.mem.disp & 0xffffffff
        else:
            out.append((None, None, 'indirect:' + re.sub(r'0x[0-9a-f]+', 'N', i.op_str))); continue
        out.append((t, img.resolve(t), None))
    return out

_SYMS = None
MAXDIFF = 40
def exe_va_of(names):
    """exe VA named by any of our symbol names (csv names, or an address embedded in a placeholder name)"""
    global _SYMS
    if _SYMS is None:
        _SYMS = {}
        for n, v in common.symbols().items():
            _SYMS.setdefault(n, v); _SYMS.setdefault(common.demangle(n), v)
    ordered = sorted(names or (), key=lambda n: (not n.startswith(('?', '_')), len(n)))
    for n in ordered:
        if n.startswith(('?', '_')) and n in _SYMS: return _SYMS[n]
    for n in ordered:
        if not n.startswith(('?', '_')) and n in _SYMS: return _SYMS[n]
    for n in names or ():
        m = re.search(r'(?:unknown|_|Fn|fn)([0-9a-f]{6})(?![0-9a-f])', n)
        if m and 0x401000 <= int(m.group(1), 16) < 0xb61000: return int(m.group(1), 16)
    return None

def sem(theirs, tva, ours, ova):
    ti = extent(theirs, tva, 0x80000); oi = extent(ours, ova, 0x80000)
    tcs = call_targets(theirs, ti); ocs = call_targets(ours, oi)
    def label_t(t, n, txt):
        if txt: return txt
        return ('%s' % sorted(n, key=len)[0]) if n else '%#x' % t
    # exe side: one token per target VA (named for display); ours: map to an exe VA via names, else pair
    # unresolved names consistently (first come) with the exe VA at the same aligned position later.
    tok_t = [('va', t) if t is not None else ('x', txt) for t, n, txt in tcs]
    tok_o = []
    unresolved = {}
    for t, n, txt in ocs:
        if txt: tok_o.append(('x', txt)); continue
        v = exe_va_of(n)
        if v is None:
            key = sorted(n, key=len)[0] if n else '%#x' % t
            if 'security_check_cookie' in key: v = 0xaa0d0f
            elif key in ('chkstk', '__chkstk', '__alloca_probe'): v = 0xaa1300
            if v is None: tok_o.append(('name', key)); unresolved.setdefault(key, None); continue
        tok_o.append(('va', v))
    # pair unresolved names with exe VAs by a first alignment pass
    sm = difflib.SequenceMatcher(None, tok_t, tok_o, autojunk=False)
    for op, a1, a2, b1, b2 in sm.get_opcodes():
        if op == 'replace' and a2 - a1 == b2 - b1:
            for k in range(a2 - a1):
                if tok_o[b1 + k][0] == 'name' and tok_t[a1 + k][0] == 'va' and unresolved.get(tok_o[b1 + k][1]) is None:
                    unresolved[tok_o[b1 + k][1]] = tok_t[a1 + k][1]
    tok_o = [('va', unresolved[x[1]]) if x[0] == 'name' and unresolved.get(x[1]) is not None else x for x in tok_o]
    sm = difflib.SequenceMatcher(None, tok_t, tok_o, autojunk=False)
    names = {v: k for k, v in common.symbols().items()}
    def show(tok):
        if tok[0] == 'va': return common.demangle(names[tok[1]]) if tok[1] in names else '%#x' % tok[1]
        return tok[1]
    print('calls: exe %d, ours %d, ratio %.4f' % (len(tok_t), len(tok_o), sm.ratio()))
    diffs = [o for o in sm.get_opcodes() if o[0] != 'equal']
    for op, a1, a2, b1, b2 in diffs[:MAXDIFF]:
        print('  %-7s exe[%d:%d] %s | ours[%d:%d] %s' % (op, a1, a2, [show(x) for x in tok_t[a1:a2][:5]], b1, b2, [show(x) for x in tok_o[b1:b2][:5]]))
    if len(diffs) > MAXDIFF: print('  ... %d more differing regions' % (len(diffs) - MAXDIFF))
    tcn, ocn = tok_t, tok_o
    def lits(img, ins):
        c = collections.Counter()
        for i in ins:
            for op in i.operands:
                v = None
                if op.type == x86.X86_OP_IMM: v = op.imm & 0xffffffff
                elif op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index: v = op.mem.disp & 0xffffffff
                if v is None or not (img.lo <= v < img.hi) or i.mnemonic == 'call' or i.mnemonic.startswith('j'): continue
                b = img.read(v, 256); e = b.find(b'\0')
                if i.mnemonic.startswith('f') and op.type == x86.X86_OP_MEM:
                    c['float %r' % (struct.unpack('<f', b[:4])[0] if op.size == 4 else struct.unpack('<d', b[:8])[0])] += 1
                elif i.mnemonic == 'push' and e >= 0 and all(32 <= x < 127 or x in (9, 10) for x in b[:e]):
                    c['str %r' % b[:e].decode('latin1')] += 1
        return c
    lt, lo = lits(theirs, ti), lits(ours, oi)
    for k in sorted(set(lt) | set(lo)):
        if lt[k] != lo[k]: print('  literal %s: exe %d ours %d' % (k, lt[k], lo[k]))
    def shape(i):
        ops = []
        for op in i.operands:
            ops.append({x86.X86_OP_REG: 'r', x86.X86_OP_IMM: 'i', x86.X86_OP_MEM: 'm'}[op.type])
        return i.mnemonic + ' ' + ''.join(ops)
    ism = difflib.SequenceMatcher(None, [shape(i) for i in ti], [shape(i) for i in oi], autojunk=False)
    print('instructions: exe %d, ours %d, shape ratio %.4f' % (len(ti), len(oi), ism.ratio()))
    return tcn == ocn

def main(argv):
    d = argv[0]; name, va = argv[1].rsplit('=', 1); va = int(va, 16)
    mp, ours, theirs, by = images(d)
    if name not in by: print('%s not in our map' % name); return 1
    if '--sem' in argv: return 0 if sem(theirs, va, ours, by[name]) else 1
    from fnsize import fn_size
    lines = []
    ok = _compare_all(theirs, va, ours, by[name], fn_size(va), lines)
    print('%s %s (%d lines differ)' % (name, 'MATCH' if ok else 'DIFF', len(lines)))
    for l in lines[: (None if '--all' in argv else 200)]: print('  ' + l)
    return 0 if ok else 1

def _compare_all(theirs, tva, ours, ova, size, out):
    """lverify._compare without its 40-problem print cap (executed from lverify's own source)"""
    code = open(lverify.__file__).read()
    start = code.index('def _compare(')
    end = code.index('\ndef ', start + 10)
    ns = dict(vars(lverify))
    exec(code[start:end].replace('problems[:40]', 'problems'), ns)
    printed = []
    ns['print'] = lambda *a, **k: printed.append(' '.join(str(x) for x in a))
    ok = ns['_compare']('x', theirs, tva, ours, ova, size, False)
    out.extend(l.strip() for l in printed[1:])
    return ok

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
