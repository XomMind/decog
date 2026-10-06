"""Static call graph of COGMIND.exe and what is reachable from the entry point.
   Edges (over-approximation): direct call/jmp targets, any 32-bit immediate/displacement operand equal to a
   function start (callbacks, function-pointer tables), and any operand equal to a vtable address (all slots of
   that vtable, from build/rtti.csv). Unresolved indirect calls are not followed.
   usage: callgraph.py            -> build/callgraph.json (edges + reachable set) and a summary
          callgraph.py <va> ...   -> extra roots (e.g. 0x401000)"""
import sys, os, json, collections, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import capstone, common, funcindex
from fnsize import fn_size

OUT = os.path.join(common.REPO, 'build', 'callgraph.json')

def vtables():
    out = {}
    p = os.path.join(common.REPO, 'build', 'rtti.csv')
    for line in open(p):
        f = line.rstrip('\n').split(',')
        if len(f) >= 7 and f[5]: out[int(f[1], 16)] = [int(x, 16) for x in f[5].split(';') if x]
    return out

def build():
    starts = funcindex.starts()
    sset = set(starts)
    vt = vtables()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    text_lo, text_hi = starts[0], 0xb61000
    edges = {}
    for i, va in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else va + fn_size(va)
        code = common.read_va(va, end - va)
        tg = set()
        for ins in md.disasm(code, va):
            vals = []
            if ins.disp_size == 4: vals.append(ins.disp & 0xffffffff)
            if ins.imm_size == 4:
                for op in ins.operands:
                    if op.type == capstone.x86.X86_OP_IMM: vals.append(op.imm & 0xffffffff)
            for v in vals:
                if v in sset and v != va: tg.add(v)
                elif v in vt: tg.update(s for s in vt[v] if s in sset)
        if tg: edges[va] = sorted(tg)
    return starts, edges

def reach(edges, roots):
    seen, stack = set(roots), list(roots)
    while stack:
        for t in edges.get(stack.pop(), ()):
            if t not in seen: seen.add(t); stack.append(t)
    return seen

def classify():
    """va -> 'matched' | 'library' | 'named' | 'unknown' (same rule as progress.py, recorded rows only)"""
    matched = {va for va, _ in common.functions().values()}
    lib = {int(r[1], 16) for r in common.load_csv('library.csv')}
    ranges = [(int(r[0], 16), int(r[1], 16)) for r in common.load_csv('library_ranges.csv')]
    named = {int(r[0], 16) for r in common.load_csv('names.csv')}
    def c(va):
        if va in lib or any(lo <= va < hi for lo, hi in ranges): return 'library'
        return 'matched' if va in matched else 'named' if va in named else 'unknown'
    return c

def main(argv):
    starts, edges = build()
    p = common.pe(); entry = p.OPTIONAL_HEADER.ImageBase + p.OPTIONAL_HEADER.AddressOfEntryPoint
    roots = [entry] + [int(a, 16) for a in argv]
    # CRT startup calls WinMain through a direct call: follow it, it's just a library function from our point of view.
    r = reach(edges, roots)
    cls = classify()
    sz = {}
    for i, va in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else va + fn_size(va)
        sz[va] = len(common.read_va(va, end - va).rstrip(b'\xcc'))
    tot = collections.Counter(); cnt = collections.Counter(); rt = collections.Counter(); rc = collections.Counter()
    for va in starts:
        c = cls(va); tot[c] += sz[va]; cnt[c] += 1
        if va in r: rt[c] += sz[va]; rc[c] += 1
    json.dump(dict(entry=entry, edges={'%x' % k: ['%x' % x for x in v] for k, v in edges.items()},
                   reachable=sorted('%x' % x for x in r), sizes={'%x' % k: v for k, v in sz.items()}), open(OUT, 'w'))
    print('entry %#x, %d functions indexed, %d reachable' % (entry, len(starts), len(r)))
    print('%-9s %8s %10s | %8s %10s (reachable)' % ('class', 'funcs', 'bytes', 'funcs', 'bytes'))
    for c in ('matched', 'named', 'unknown', 'library'):
        print('%-9s %8d %10d | %8d %10d' % (c, cnt[c], tot[c], rc[c], rt[c]))

if __name__ == '__main__': main(sys.argv[1:])
