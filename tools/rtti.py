"""Extract MSVC RTTI: every vtable (via its CompleteObjectLocator) -> class, bases, slots.
   Writes build/rtti.csv: class,vtable_va,nslots,bases,slot0;slot1;...
   Game classes = everything outside std::, google::, Concurrency::, and CRT internals."""
import sys, os, struct, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common, funcindex

def main():
    p = common.pe(); base = p.OPTIONAL_HEADER.ImageBase
    secs = {s.Name.rstrip(b'\0'): s for s in p.sections}
    rd = secs[b'.rdata']; rdd = rd.get_data(); rd0 = base + rd.VirtualAddress
    tx = secs[b'.text']; tx0 = base + tx.VirtualAddress; tx1 = tx0 + tx.Misc_VirtualSize
    def u32(va): return struct.unpack('<I', common.read_va(va, 4))[0]
    def cstr(va):
        b = common.read_va(va, 512); return b[:b.index(b'\0')].decode('latin1')
    def in_rd(va): return rd0 <= va < rd0 + len(rdd)
    rows = []
    for off in range(0, len(rdd) - 8, 4):
        col = struct.unpack_from('<I', rdd, off)[0]
        if not in_rd(col): continue
        try:
            sig, voff, cdoff, td, chd = struct.unpack('<5I', common.read_va(col, 20))
        except Exception: continue
        if sig != 0 or not (base < td < base + 0x1000000) or not in_rd(chd): continue
        try: name = cstr(td + 8)
        except Exception: continue
        if not name.startswith('.?A'): continue
        vt = rd0 + off + 4
        slots = []
        while True:
            f = struct.unpack_from('<I', rdd, vt - rd0 + 4 * len(slots))[0] if vt - rd0 + 4 * len(slots) + 4 <= len(rdd) else 0
            if not (tx0 <= f < tx1) or (slots and in_rd(struct.unpack_from('<I', rdd, vt - rd0 + 4 * len(slots) - 4)[0]) and False): break
            slots.append(f)
            nxt = vt - rd0 + 4 * len(slots)
            if nxt + 4 <= len(rdd) and in_rd(struct.unpack_from('<I', rdd, nxt)[0]): break  # next vtable's COL
        try:
            n = u32(chd + 8); arr = u32(chd + 12)
            bases = [cstr(u32(u32(arr + 4 * i)) + 8) for i in range(n)][1:]
        except Exception: bases = []
        cls = name[4:].rstrip('@')
        rows.append((cls, vt, voff, bases, slots))
    def pretty(m):  # .?AVFoo@Bar@@ -> Bar::Foo (good enough)
        return '::'.join(reversed(m.split('@'))) if '?$' not in m else m
    out = os.path.join(common.REPO, 'build', 'rtti.csv')
    game = 0
    with open(out, 'w') as f:
        for cls, vt, voff, bases, slots in sorted(rows, key=lambda r: r[1]):
            pc = pretty(cls)
            lib = bool(re.search(r'(^|::)(std|google|Concurrency|details|type_info)\b|^\?\$|^_', pc))
            game += not lib
            f.write('%s,%#x,%d,%d,%s,%s,%s\n' % (pc, vt, voff, len(slots), ' '.join(pretty(b[4:].rstrip('@')) for b in bases),
                                             ';'.join('%#x' % s for s in slots), 'lib' if lib else 'game'))
    print(len(rows), 'vtables,', game, 'game classes ->', out)

if __name__ == '__main__':
    main()
