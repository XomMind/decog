"""Audit: rows that MATCH only because an operand of ours points INSIDE a stub slot (see stubobj.py).
   usage: stubaudit.py <ltcg dir> [name-substring ...]
   An access like [sym+0x30] to a stubbed extern lands at a non-zero offset in the stub's slot (or, with the
   default 16-byte slots, on another stub). lverify then either pairs the wrong stub or compares stub zeros with
   exe data, which can pass by luck. Build with STUB_SLOT=1024 to see field offsets as interior offsets.
   Prints every MATCHing row with such an operand: name, instruction offset, stub, offset into the stub."""
import sys, os, re, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import capstone, lverify

def stub_table(mapfile):
    starts = []
    for line in open(mapfile, encoding='latin1'):
        m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s.*stubs\.obj\s*$', line)
        if m: starts.append((int(m.group(2), 16), m.group(1)))
    starts.sort()
    slot = min((b[0] - a[0] for a, b in zip(starts, starts[1:])), default=16)
    return starts, slot

def main(argv):
    d = argv[0]; flt = argv[1:]
    lverify.DLL, lverify.MAP = os.path.join(d, 'match.dll'), os.path.join(d, 'match.map')
    starts, slot = stub_table(lverify.MAP)
    vas = [s[0] for s in starts]
    lo, hi = (vas[0], vas[-1] + slot) if vas else (0, 0)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    hits = {}
    orig = lverify._compare
    def wrapped(name, theirs, tva, ours, ova, size, verbose):
        ok = orig(name, theirs, tva, ours, ova, size, verbose)
        if ok:
            for ins in md.disasm(ours.read(ova, size), ova):
                for off, sz, v, rel in lverify.operand_fields(ins):
                    if rel or not (lo <= v < hi): continue
                    i = bisect.bisect_right(vas, v) - 1
                    k = v - vas[i]
                    if k: hits.setdefault(name, []).append((ins.address - ova, starts[i][1], k))
        return ok
    lverify._compare = wrapped
    import io, contextlib
    with contextlib.redirect_stdout(io.StringIO()):
        res = lverify.verify_all(flt)
    print('# stub slot %d bytes, %d stubs; %d matching rows touch a stub at a non-zero offset' % (slot, len(starts), len(hits)))
    for n in sorted(hits):
        print('%s\t%s' % (n, '; '.join('+%x %s+%#x' % h for h in hits[n][:6])))
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
