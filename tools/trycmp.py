"""Compare named functions of an ltcg.py output dir against COGMIND.exe addresses.
   usage: trycmp.py <dir> 'Name=0xVA' ...  (size comes from the function index)"""
import sys, os, pefile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lverify, common
from fnsize import fn_size

def main(d, pairs):
    lverify.DLL, lverify.MAP = os.path.join(d, 'match.dll'), os.path.join(d, 'match.map')
    mp = lverify.load_map()
    ours = lverify.Image(pefile.PE(lverify.DLL), lverify.map_names(mp))
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names())
    by = lverify.code_names(mp, ours)
    ok = True
    for arg in pairs:
        name, va = arg.rsplit('=', 1); va = int(va, 16)
        if name not in by:
            print("%s: not in our map. Ours: %s" % (name, ', '.join(sorted(set(common.demangle(n) for n in mp if not n.startswith(('_', '__real', '??_C'))))[:40])))
            ok = False; continue
        ok &= lverify.compare(name, theirs, va, ours, by[name], fn_size(va), True)
    return 0 if ok else 1

if __name__ == '__main__':
    sys.exit(main(sys.argv[1], sys.argv[2:]))
