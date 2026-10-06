"""Index of /Od function starts in COGMIND.exe: 16-byte aligned `push ebp; mov ebp, esp`
   preceded by int3 padding, a ret, or the previous function's switch jump table. Cached in build/funcstarts.txt.
   usage: funcindex.py            -> rebuild the cache and print the count
          funcindex.py <va>       -> start of the function containing va"""
import sys, os, bisect, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common

CACHE = os.path.join(common.REPO, "build", "funcstarts.txt")

def build():
    p = common.pe(); base = p.OPTIONAL_HEADER.ImageBase
    text = [s for s in p.sections if s.Name.rstrip(b'\0') == b'.text'][0]
    d = text.get_data(); va0 = base + text.VirtualAddress
    out = []
    for i in range(0, len(d) - 3, 16):
        if d[i:i+3] != b'\x55\x8b\xec': continue
        prev = d[max(0, i-3):i]
        if i == 0 or prev[-1:] in (b'\xcc', b'\xc3') or prev[:1] == b'\xc2':
            out.append(va0 + i)
        elif i >= 4 and va0 + i - 0x8000 <= struct.unpack('<I', d[i-4:i])[0] < va0 + i:
            out.append(va0 + i)   # right after the previous function's switch jump table
    os.makedirs(os.path.dirname(CACHE), exist_ok=True)
    open(CACHE, 'w').write('\n'.join('%x' % a for a in out))
    return out

def starts():
    """Prologue-scan starts plus every mapped function address (EH funclets and other
    functions without a push-ebp prologue are only known from config mappings)."""
    st = build() if not os.path.exists(CACHE) else [int(x, 16) for x in open(CACHE).read().split()]
    known = set(st)
    for va, _ in common.functions().values(): known.add(va)
    return sorted(known)

def containing(va, st=None):
    st = st or starts()
    i = bisect.bisect_right(st, va) - 1
    return st[i] if i >= 0 else None

if __name__ == '__main__':
    if len(sys.argv) > 1: print('%#x' % containing(int(sys.argv[1], 16)))
    else: print(len(build()), "function starts")
