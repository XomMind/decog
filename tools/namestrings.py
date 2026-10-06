"""Find functions named by embedded "Class::method()" strings.
   For each string: every code reference -> containing function. A string referenced from
   exactly one function is very likely that function's own name (error/profiling macro).
   Writes build/namestrings.csv: name,string_va,n_funcs,func_va[;func_va...]"""
import sys, os, re, struct, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common, funcindex

def main():
    p = common.pe(); base = p.OPTIONAL_HEADER.ImageBase
    secs = {s.Name.rstrip(b'\0'): s for s in p.sections}
    rd = secs[b'.rdata']; rdd = rd.get_data(); rdva = base + rd.VirtualAddress
    tx = secs[b'.text']; txd = tx.get_data(); txva = base + tx.VirtualAddress
    pat = re.compile(rb'(?<=\0)([A-Za-z_][A-Za-z0-9_]*::~?[A-Za-z_][A-Za-z0-9_]*\(\))\0')
    strs = {m.start(1) + rdva: m.group(1).decode() for m in pat.finditer(rdd)}
    st = funcindex.starts()
    refs = collections.defaultdict(list)
    want = {struct.pack('<I', va): va for va in strs}
    # scan every 4-byte window of .text for a string address
    for i in range(len(txd) - 3):
        k = txd[i:i+4]
        if k in want: refs[want[k]].append(txva + i)
    rows = []
    for va, name in sorted(strs.items(), key=lambda x: x[1]):
        fns = sorted(set(funcindex.containing(r, st) for r in refs[va]))
        rows.append((name, va, fns))
    with open(os.path.join(common.REPO, 'build', 'namestrings.csv'), 'w') as f:
        for name, va, fns in rows:
            f.write('%s,%#x,%d,%s\n' % (name, va, len(fns), ';'.join('%#x' % x for x in fns)))
    c = collections.Counter(len(f) for _, _, f in rows)
    print("strings:", len(rows), " by #referencing functions:", dict(sorted(c.items())))

if __name__ == '__main__':
    main()
