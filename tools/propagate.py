"""Auto-match a build against COGMIND.exe by vtable seeding + call-graph propagation.
   usage: propagate.py <ltcg outdir> <mapping.d name> [--class-prefix P]
   1. For every vtable present in both (same RTTI class name), pair slot i with slot i.
   2. Compare each pair; on MATCH, every callee/data pairing learned inside it is queued
      (if that callee is a real function in our build) and compared in turn.
   Writes config/mapping.d/<name>.csv (matched, mangled names) and prints a summary.
   Learned names for callees we don't build (library code) go to build/learned_<name>.csv."""
import sys, os, struct, collections, pefile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common, lverify
from fnsize import fn_size

def main(outdir, area, prefix=None):
    lverify.DLL, lverify.MAP = os.path.join(outdir, 'match.dll'), os.path.join(outdir, 'match.map')
    mp = lverify.load_map()
    dll = pefile.PE(lverify.DLL)
    ours = lverify.Image(dll, lverify.map_names(mp))
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names(), common.symbols())
    obase = dll.OPTIONAL_HEADER.ImageBase
    text = [s for s in dll.sections if s.Name.rstrip(b'\0') == b'.text'][0]
    t0, t1 = obase + text.VirtualAddress, obase + text.VirtualAddress + text.Misc_VirtualSize
    is_code = lambda va: t0 <= va < t1
    va2name = {}
    for n, va in mp.items():
        if is_code(va): va2name.setdefault(va, set()).add(n)
    name2va = {n: va for n, va in mp.items()}
    # exe vtables by class
    exe_vt = {}
    for line in open(os.path.join(common.REPO, 'build', 'rtti.csv')):
        f = line.rstrip('\n').split(',')
        if f[2] == '0': exe_vt.setdefault(f[0], [int(x, 16) for x in f[5].split(';') if x])
    queue = collections.deque(); seen = set()
    for n, va in mp.items():
        if not n.startswith('??_7'): continue
        cls = common.demangle(n).rsplit('::', 1)[0]
        if prefix and not cls.startswith(prefix): continue
        if cls not in exe_vt: continue
        for i, tva in enumerate(exe_vt[cls]):
            ova = struct.unpack('<I', ours.read(va + 4 * i, 4))[0]
            if is_code(ova): queue.append((ova, tva))
    matched, failed = {}, {}
    while queue:
        ova, tva = queue.popleft()
        if (ova, tva) in seen or ova not in va2name: continue
        seen.add((ova, tva))
        name = lverify.sym_key(va2name[ova])
        try: size = fn_size(tva)
        except SystemExit: continue
        import io, contextlib
        with contextlib.redirect_stdout(io.StringIO()):
            ok = lverify.compare(name, theirs, tva, ours, ova, size, False)
        if ok:
            matched[name] = (tva, size)
            for bv, av in lverify.LAST_PAIRS:
                if is_code(bv): queue.append((bv, av))
        else:
            failed[name] = tva
    failed = {k: v for k, v in failed.items() if k not in matched}
    os.makedirs(os.path.join(common.REPO, 'config', 'mapping.d'), exist_ok=True)
    with open(os.path.join(common.REPO, 'config', 'mapping.d', area + '.csv'), 'w') as f:
        f.write('# auto-matched by tools/propagate.py (vtable seed + call-graph propagation)\n')
        for n, (va, sz) in sorted(matched.items(), key=lambda x: x[1][0]): f.write('%s,%#x,%#x\n' % (n, va, sz))
    built = set(n for n, va in mp.items() if is_code(va))
    with open(os.path.join(common.REPO, 'build', 'learned_%s.csv' % area), 'w') as f:
        for k, v in sorted(lverify.LEARN_FWD.items(), key=lambda x: x[1]):
            if k not in built: f.write('%s,%#x\n' % (k, v))
    with open(os.path.join(common.REPO, 'build', 'failed_%s.csv' % area), 'w') as f:
        for k, v in sorted(failed.items(), key=lambda x: x[1]): f.write('%s,%#x\n' % (k, v))
    print('matched %d (%s bytes), failed %d, learned external names %d' % (
        len(matched), f"{sum(s for _, s in matched.values()):,}", len(failed),
        sum(1 for k in lverify.LEARN_FWD if k not in built)))

if __name__ == '__main__':
    a = sys.argv[1:]
    pre = None
    if '--class-prefix' in a: i = a.index('--class-prefix'); pre = a[i + 1]; del a[i:i + 2]
    main(a[0], a[1], pre)
