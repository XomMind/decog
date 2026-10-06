"""Turn build/namestrings.csv into config/names.csv (va,name,size,source).
   One name per function: a function with several candidate names takes the one not used
   by any other function, then the one with the most references; a name claimed by several
   functions gets an _<va> suffix on each. Names in config/mapping.csv (reconstructed) win."""
import sys, os, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common
from fnsize import fn_size

def main():
    refs = collections.Counter()           # (func, name) -> number of string refs
    for line in open(os.path.join(common.REPO, 'build', 'namestrings.csv')):
        name, sva, n, fns = line.strip().split(',')
        for f in filter(None, fns.split(';')): refs[(int(f, 16), name[:-2])] += 1
    f2n = collections.defaultdict(dict); n2f = collections.defaultdict(set)
    for (f, n), c in refs.items(): f2n[f][n] = c; n2f[n].add(f)
    chosen = {}
    for f, cands in f2n.items():
        chosen[f] = sorted(cands, key=lambda n: (len(n2f[n]) != 1, -cands[n], n))[0]
    users = collections.Counter(chosen.values())
    done = {va for va, _ in common.functions().values()}
    out = []
    for f, n in sorted(chosen.items()):
        if f in done: continue
        alts = sorted(set(f2n[f]) - {n})
        out.append((f, n if users[n] == 1 else '%s_%x' % (n, f), fn_size(f),
                    'string' + (' (also: %s)' % ' '.join(alts) if alts else '')))
    with open(os.path.join(common.REPO, 'config', 'names.csv'), 'w') as fh:
        fh.write('# va,name,size,source -- identified but not yet reconstructed\n')
        for f, n, sz, src in out: fh.write('%#x,%s,%#x,%s\n' % (f, n, sz, src))
    print(len(out), 'named functions written')

if __name__ == '__main__':
    main()
