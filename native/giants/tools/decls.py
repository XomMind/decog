"""Find existing declarations (from src/) for the callees and globals of an exe function, so a reconstruction
reuses the repo's names and signatures.
   usage: decls.py 0xFUNC            (all direct callees + absolute data operands of the function)
          decls.py --va 0xA [0xB ..]  (specific addresses)
For each address: the csv names (mapping.d, names.csv, globals.csv) and up to 3 declaration lines from src/
that mention the name or the address (`0x5111e0`, `_5111e0`, `5111e0`)."""
import sys, os, re, glob, collections
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.join(HERE, '..', '..', '..')
sys.path.insert(0, os.path.join(REPO, 'tools')); sys.path.insert(0, HERE)
import common

_SRC = None
def src_lines():
    global _SRC
    if _SRC is None:
        _SRC = []
        for f in sorted(glob.glob(os.path.join(REPO, 'src', '**', '*.cpp'), recursive=True)):
            rel = os.path.relpath(f, REPO)
            for i, l in enumerate(open(f, errors='replace')):
                if ';' in l and '(' in l or 'extern' in l:
                    _SRC.append((rel, i + 1, l.rstrip()))
    return _SRC

def names_for(va):
    out = []
    for r in common.mapping_rows():
        try:
            if int(r[1], 16) == va: out.append(r[0])
        except (ValueError, IndexError): pass
    for r in common.load_csv('names.csv'):
        if int(r[0], 16) == va: out.append(r[1])
    for r in common.load_csv('globals.csv'):
        if int(r[1], 16) == va: out.append(r[0])
    return out

def find(va, names, limit=3):
    keys = {'%x' % va}
    for n in names:
        d = common.demangle(n)
        keys.add(d.split('::')[-1])
    hits = []
    hexkey = re.compile(r'(0x|_|\b)0*%x\b' % va)
    for rel, ln, l in src_lines():
        s = l.strip()
        if s.startswith('//'): continue
        ok = bool(hexkey.search(l))
        if not ok:
            for k in keys:
                if len(k) > 3 and re.search(r'\b%s\s*\(' % re.escape(k), l) and (s.endswith(';') or '//' in s) and not s.startswith(('return', 'if', 'for', 'while')) and '=' not in s.split('(')[0]:
                    ok = True; break
        if ok:
            hits.append('%s:%d: %s' % (rel, ln, s[:200]))
            if len(hits) >= limit: break
    return hits

def main(argv):
    if argv[0] == '--va':
        vas = [int(a, 16) for a in argv[1:]]
    else:
        import gdis, capstone
        from capstone import x86
        f = gdis.Fn(int(argv[0], 16))
        vas = []
        for a in f.order:
            i = f.ins[a]
            if i.mnemonic == 'call' and i.operands[0].type == x86.X86_OP_IMM:
                t = i.operands[0].imm & 0xffffffff
                if t not in vas: vas.append(t)
    for va in vas:
        ns = names_for(va)
        print('%#x %s%s' % (va, ' | '.join(ns[:4]) or '(unnamed)', trivial(va)))
        for h in find(va, ns): print('    ' + h)

def trivial(va):
    """Describe a tiny /Od body (ICF-folded getters/setters carry unrelated names): '  [= getter +0x28 dword]'."""
    import capstone
    from fnsize import fn_size
    try: size = fn_size(va)
    except SystemExit: return ''
    if size > 0x40: return '  [%#x bytes]' % size
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    body = [(i.mnemonic, i.op_str) for i in md.disasm(common.read_va(va, size), va)]
    core = [b for b in body if b not in (('push', 'ebp'), ('mov', 'ebp, esp'), ('push', 'ecx'), ('mov', 'dword ptr [ebp - 4], ecx'),
                                         ('mov', 'esp, ebp'), ('pop', 'ebp'))]
    txt = '; '.join('%s %s' % b for b in core if not b[0].startswith('ret'))
    ret = [b for b in body if b[0].startswith('ret')]
    return '  [= %s%s]' % (txt.replace('dword ptr [ebp - 4]', 'this').replace('dword ptr [ebp + 8]', 'arg1'), ' ; ' + ' '.join(ret[-1]) if ret else '')

if __name__ == '__main__':
    main(sys.argv[1:])
