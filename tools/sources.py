"""Print all build sources in link order (config/link_order.txt, then the rest sorted)."""
import os, glob
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(REPO)
allsrc = sorted(p for d in ('src', 'harness') for ext in ('cpp',) for p in glob.glob('%s/**/*.%s' % (d, ext), recursive=True))
out = []
for line in open('config/link_order.txt'):
    line = line.strip()
    if line and not line.startswith('#'):
        out += [p for p in sorted(glob.glob(line, recursive=True)) if p not in out]
out += [p for p in allsrc if p not in out]
print(' '.join(out))
