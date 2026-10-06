"""Field-offset knowledge base from the matched reconstructions in src/: which member names other workers
gave to <Class>+<offset>, so a giant's raw offsets can be named consistently.
   usage: fields.py Class [0xOFF ...]        (no offsets: dump all known members of Class)
Parsing: every `class|struct X ... { ... };` body in src/**/*.cpp; offsets come from 32-bit layout padding
(`char padNN[0xEND - 0xNN]` puts the next member at 0xEND) and from walking members of known size after it
(int/float/pointers 4, bool/char 1, double 8, string 28, vector 16, list 8, Point 8, handles 4...);
tracking stops at a member of unknown size until the next pad. Base-class layout is not inherited, so a
class whose first pad starts at 0x6c (Console derived) is still correct from that pad on.
`// +0xNN` / `// 0xNN` trailing comments on a member line override the computed offset."""
import sys, os, re, glob, collections
REPO = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')
SIZES = {'int': 4, 'unsigned': 4, 'unsigned int': 4, 'long': 4, 'unsigned long': 4, 'float': 4, 'bool': 1, 'char': 1,
         'unsigned char': 1, 'signed char': 1, 'short': 2, 'unsigned short': 2, 'double': 8, 'string': 28, 'std::string': 28,
         'Point': 8, 'Pos': 8, 'HEntity': 4, 'HItem': 4, 'HProp': 4, 'ID': 4, 'entityID': 4, 'itemID': 4, 'propID': 4,
         'cellID': 4, 'XColor': 3, 'Rect': 16, '__int64': 8, 'DWORD': 4, 'Uint32': 4, 'Uint8': 1, 'Sint32': 4,
         'stringstream': 0x74 + 0x0}  # stringstream: unknown, treated as stop below
STOP = {'stringstream'}

def type_size(t):
    t = t.replace('const ', '').replace('mutable ', '').replace('static ', '').strip()
    if t.endswith('*'): return 4
    if t.startswith(('vector<', 'std::vector<')): return 16
    if t.startswith(('list<', 'std::list<')): return 8
    if t.startswith(('map<', 'std::map<', 'set<', 'std::set<', 'multimap<')): return 8
    if t.startswith(('deque<', 'std::deque<')): return 20
    if t.startswith(('pair<', 'std::pair<')): return None
    if t.startswith('enum ') or t.endswith('Type'): return 4
    if t in STOP: return None
    return SIZES.get(t)

CLASS_RE = re.compile(r'^(?:class|struct)\s+(\w+)\b[^;{]*\n?\{', re.M)
PAD_RE = re.compile(r'char\s+\w+\[\s*(0x[0-9a-fA-F]+|\d+)\s*-\s*(0x[0-9a-fA-F]+|\d+)\s*\]')
MEM_RE = re.compile(r'^\s*((?:const |unsigned |signed |mutable |enum )*[\w:<>, *]+?[\s*&]+)(\w+)(\[(0x[0-9a-fA-F]+|\d+)\])?\s*;(.*)$')
OFF_COMMENT = re.compile(r'//.*?\+?(0x[0-9a-fA-F]+)\b')

def bodies(text):
    for m in CLASS_RE.finditer(text):
        i = m.end(); depth = 1; j = i
        while j < len(text) and depth:
            if text[j] == '{': depth += 1
            elif text[j] == '}': depth -= 1
            j += 1
        yield m.group(1), text[i:j - 1]

def parse_body(body):
    out = []
    off = None
    depth = 0
    for line in body.splitlines():
        s = line.strip()
        if depth: depth += s.count('{') - s.count('}'); continue
        if '(' in s and s.endswith('{'): depth = 1; continue
        if '{' in s and '}' not in s and '(' in s: depth = s.count('{') - s.count('}'); continue
        pm = PAD_RE.search(s)
        if pm:
            off = int(pm.group(1), 0); continue
        if '(' in s or s.startswith(('//', 'public', 'private', 'protected', 'friend', 'typedef', 'static', 'virtual', 'enum', 'using', '#')):
            continue
        mm = MEM_RE.match(line)
        if not mm: continue
        t, n, _, arr, rest = mm.groups()
        t = t.strip()
        cm = OFF_COMMENT.search(rest or '')
        if cm and ('+0x' in rest or re.search(r'//\s*0x', rest)):
            try:
                v = int(cm.group(1), 16)
                if v < 0x10000: off = v
            except ValueError: pass
        if off is not None:
            out.append((off, n, t))
        sz = type_size(t)
        if sz is None or off is None: off = None; continue
        if arr: sz *= int(arr, 0)
        al = min(sz, 4) if sz in (1, 2, 4, 8) and not t.endswith('*') else 4
        if t in ('bool', 'char', 'unsigned char', 'signed char') and not arr: al = 1
        if t in ('short', 'unsigned short'): al = 2
        if t == 'XColor': al = 1
        if t == 'double' or t == '__int64': al = 8
        off = (off + al - 1) // al * al if out[-1][0] == off else off
        off += sz
    return out

def db():
    d = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    for f in glob.glob(os.path.join(REPO, 'src', '**', '*.cpp'), recursive=True):
        try: text = open(f, errors='replace').read()
        except OSError: continue
        rel = os.path.relpath(f, REPO)
        for cls, body in bodies(text):
            for off, n, t in parse_body(body):
                if n.startswith('pad'): continue
                d[cls][off][(n, t)] += 1
    return d

if __name__ == '__main__':
    d = db()
    cls = sys.argv[1]
    offs = [int(a, 16) for a in sys.argv[2:]]
    for off in sorted(d[cls]):
        if offs and off not in offs: continue
        names = ', '.join('%s %s x%d' % (t, n, c) for (n, t), c in d[cls][off].most_common(6))
        print('%s+%#x: %s' % (cls, off, names))
