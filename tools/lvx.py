"""lverify with extra or removed mapping rows, without editing config/ (try candidate rows here first).
   usage: lvx.py <build dir> <extra.csv> [exact-name-to-drop ...]"""
import sys, runpy
sys.path.insert(0, 'tools')
import common
d, extra, drops = sys.argv[1], sys.argv[2], sys.argv[3:]
_orig = common.mapping_rows
def rows():
    out = [r for r in _orig() if not any(x == r[0] for x in drops)]
    for l in open(extra):
        l = l.strip()
        if l and not l.startswith('#'): out.append(l.rsplit(',', 2))
    return out
common.mapping_rows = rows
sys.argv = ['tools/lverify.py', '--dir', d, '-v']
runpy.run_path('tools/lverify.py', run_name='__main__')
