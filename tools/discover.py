"""Find functions our build already compiles identically to the exe but that no mapping row records.
   usage: discover.py <ltcg dir> [name-substring ...] [--write out.csv] [--all]
   For each code symbol of <dir>/match.dll that has no mapping row, try every exe function
   (not yet mapped) with the same instruction shape; report symbols with exactly one MATCH.
   Symbols that match several exe functions (identical tiny bodies) are listed as ambiguous."""
import sys, os, re, struct, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import pefile, capstone, common, lverify, funcindex
from fnsize import fn_size

def shape(code, base):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return tuple((i.mnemonic, i.size) for i in md.disasm(code, base))

def main(argv):
    d = argv[0]; flt = [a for a in argv[1:] if not a.startswith('--')]
    out = argv[argv.index('--write') + 1] if '--write' in argv else None
    if out: flt = [a for a in flt if a != out]
    lverify.DLL, lverify.MAP = os.path.join(d, 'match.dll'), os.path.join(d, 'match.map')
    mp = lverify.load_map()
    ours = lverify.Image(pefile.PE(lverify.DLL), lverify.map_names(mp))
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names())
    by = lverify.code_names(mp, ours)
    mapped_names = set(common.functions())
    mapped_vas = {va for va, _ in common.functions().values()}
    st = funcindex.starts()
    exe = collections.defaultdict(list)
    for i, va in enumerate(st[:-1]):
        if va in mapped_vas: continue
        size = len(common.read_va(va, st[i + 1] - va).rstrip(b'\xcc'))
        if size < 8: continue
        exe[shape(common.read_va(va, size), va)].append((va, size))
    t = [x for x in ours.pe.sections if x.Name.rstrip(b'\0') == b'.text'][0]
    lo = ours.base + t.VirtualAddress; hi = lo + t.Misc_VirtualSize
    syms = sorted((va, n) for n, va in mp.items() if lo <= va < hi and n.startswith('?') and not n.startswith('??_C'))
    starts = sorted({va for va, _ in syms})
    results, ambiguous, taken = [], [], set()
    for va, n in syms:
        if n in mapped_names or lverify.is_stub(ours, va): continue
        if flt and not any(f in n for f in flt): continue
        nxt = next((s for s in starts if s > va), hi)
        code = ours.read(va, min(nxt - va, 4096)).rstrip(b'\xcc')
        # the symbol's code ends at the first ret that is followed by padding or the next symbol
        key = shape(code, va)
        for cut in range(len(key), 0, -1):
            if key[cut - 1][0] == 'ret': key = key[:cut]; break
        cands = exe.get(key, [])
        m = re.search(r'_([0-9a-f]{6,7})(?:@@|$)', n)
        if m:   # placeholder global named after its exe address: only functions that embed it
            pat = struct.pack('<I', int(m.group(1), 16))
            cands = [c for c in cands if pat in common.read_va(c[0], c[1])]
        else: cands = cands[:200]
        hits = []
        for tva, size in cands:
            saved = dict(lverify.LEARN_FWD)
            ok = lverify.compare(n, theirs, tva, ours, va, size, False)
            if ok:
                # placeholder globals carry their exe address as a name suffix: pairings must agree
                for ov, ev in lverify.LAST_PAIRS:
                    if lo <= ov < hi: continue   # functions (e.g. ??__F...) embed the global's address too
                    for nm in ours.names.get(ov, ()):
                        m = re.search(r'_([0-9a-f]{6,7})(?:@@|$)', nm)
                        if m and int(m.group(1), 16) != ev: ok = False
            if ok: hits.append((tva, size))
            else:
                lverify.LEARN_FWD.clear(); lverify.LEARN_FWD.update(saved)
        if '--greedy' in argv and hits:
            free = [h for h in hits if h[0] not in taken]
            if free: taken.add(free[0][0]); results.append((n, free[0][0], free[0][1]))
            continue
        if len(hits) == 1: results.append((n, hits[0][0], hits[0][1]))
        elif hits: ambiguous.append((n, hits))
    for n, v, s in results: print("%s,0x%x,0x%x" % (n, v, s))
    print("# %d unique matches, %d ambiguous" % (len(results), len(ambiguous)), file=sys.stderr)
    if out:
        with open(out, 'w') as f:
            for n, v, s in results: f.write("%s,0x%x,0x%x\n" % (n, v, s))
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
