"""Context for exe functions: name/state, callers, callees, vtable slots, and strings referenced.
   usage: xref.py <va> [va ...]     (needs build/callgraph.json, build/rtti.csv; run callgraph.py/rtti.py once)"""
import sys, os, json, re, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common
from fnsize import fn_size

def main(vas):
    cg = json.load(open(os.path.join(common.REPO, 'build', 'callgraph.json')))
    callers = {}
    for src, dsts in cg['edges'].items():
        for d in dsts: callers.setdefault(d, []).append(src)
    names = {v: k for k, v in common.symbols().items()}
    mapped = {va for va, _ in common.functions().values()}
    vt = {}
    rt = os.path.join(common.REPO, 'build', 'rtti.csv')
    for line in open(rt) if os.path.exists(rt) else ():
        f = line.rstrip('\n').split(',')
        if len(f) >= 6 and f[5]:
            for i, s in enumerate(f[5].split(';')): vt.setdefault(int(s, 16), []).append('%s[%d]' % (f[0], i))
    p = common.pe(); base = p.OPTIONAL_HEADER.ImageBase
    rd = [s for s in p.sections if s.Name.rstrip(b'\0') == b'.rdata'][0]
    lo, hi = base + rd.VirtualAddress, base + rd.VirtualAddress + rd.Misc_VirtualSize
    def label(a):
        return '%#x %s%s' % (a, names.get(a, '?'), ' [mapped]' if a in mapped else '')
    for va in vas:
        size = fn_size(va)
        print('== %s size %#x' % (label(va), size))
        if va in vt: print('  vtable slot: ' + ', '.join(vt[va]))
        print('  callers: ' + ', '.join(label(int(c, 16)) for c in callers.get('%x' % va, [])[:25]))
        print('  callees: ' + ', '.join(label(int(c, 16)) for c in cg['edges'].get('%x' % va, [])[:40]))
        strs = []
        for ins in common.disasm(common.read_va(va, size), va):
            for m in re.finditer(r'0x([0-9a-f]{6,8})', ins.op_str):
                a = int(m.group(1), 16)
                if lo <= a < hi:
                    b = common.read_va(a, 120).split(b'\0')[0]
                    if len(b) >= 3 and all(32 <= c < 127 for c in b): strs.append('%#x "%s"' % (a, b.decode()))
        if strs: print('  strings: ' + '; '.join(dict.fromkeys(strs)))

if __name__ == '__main__':
    main([int(a, 16) for a in sys.argv[1:]])
