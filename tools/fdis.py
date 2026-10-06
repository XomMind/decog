"""Disassemble COGMIND.exe function by function, labelling known names and imports.
   usage: fdis.py <start_va> [count=1]     (count = number of consecutive functions)"""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common
from fnsize import fn_size

def main(start, count):
    names = {v: k for k, v in common.symbols().items()}
    imps = common.imports()
    va = start
    for _ in range(count):
        size = fn_size(va)
        print("\n%08x  %s  (size %#x)" % (va, names.get(va, ''), size))
        for ins in common.disasm(common.read_va(va, size), va):
            op = ins.op_str
            def lab(m):
                a = int(m.group(0), 16)
                if a in imps: return '<%s>' % common.demangle(imps[a])
                if a in names: return '<%s>' % names[a]
                if ins.mnemonic[0] == 'j' and va <= a < va + size: return '+%#x' % (a - va)
                return m.group(0)
            op = re.sub(r'0x[0-9a-f]{6,8}', lab, op)
            print("  %04x  %-6s %s" % (ins.address - va, ins.mnemonic, op))
        va += size
        code = common.read_va(va, 64)
        va += len(code) - len(code.lstrip(b'\xcc'))

if __name__ == '__main__':
    main(int(sys.argv[1], 16), int(sys.argv[2]) if len(sys.argv) > 2 else 1)
