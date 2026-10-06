"""Guess function extents for /Od code: VA -> size (up to the ret followed by int3 pad / next prologue).
   usage: fnsize.py 0x406be0 [more VAs]"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common

def fn_size(va, limit=0x4000):
    """Extent = next indexed function start minus int3 padding (keeps switch jump tables)."""
    import funcindex, bisect
    st = funcindex.starts(); i = bisect.bisect_right(st, va)
    if i < len(st) and st[i - 1] == va:
        code = common.read_va(va, st[i] - va)
        return len(code.rstrip(b'\xcc'))
    return fn_size_ret(va, limit)

def fn_size_ret(va, limit=0x4000):
    code = common.read_va(va, limit)
    for ins in common.disasm(code, va):
        if ins.mnemonic in ('ret', 'retn'):
            end = ins.address + ins.size
            nxt = code[end - va:end - va + 3]
            if nxt[:1] == b'\xcc' or nxt == b'\x55\x8b\xec':
                return end - va
    raise SystemExit("no end found for %#x" % va)

if __name__ == '__main__':
    for a in sys.argv[1:]: print("%#x %#x" % (int(a, 16), fn_size(int(a, 16))))
