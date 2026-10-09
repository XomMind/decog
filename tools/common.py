"""Shared config + helpers for the cogmind diff/verify tools."""
import os, csv, re, struct
import pefile, capstone

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(REPO, "resources", "COGMIND.exe")
EXE_SHA256 = "6c96192b9b7a81956416abdb11766933bca21fce8c2c0d57b97b172e13cd8184"

_pe = None
def pe():
    global _pe
    if _pe is None:
        _pe = pefile.PE(EXE, fast_load=True)
        _pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
    return _pe

def read_va(va, n):
    p = pe(); return p.get_data(va - p.OPTIONAL_HEADER.ImageBase, n)

def u32(va): return struct.unpack('<I', read_va(va, 4))[0]

def imports():
    """IAT slot VA -> '__imp_' + import name (mangled C++ names are kept as-is)."""
    out = {}
    for e in pe().DIRECTORY_ENTRY_IMPORT:
        for imp in e.imports:
            if imp.name: out[imp.address] = '__imp_' + imp.name.decode()
    return out

def load_csv(name):
    path = os.path.join(REPO, "config", name)
    if not os.path.exists(path): return []
    return [r for r in csv.reader(open(path)) if r and not r[0].startswith('#')]

def mapping_rows():
    """config/mapping.csv + config/mapping.d/*.csv (one file per work area)"""
    rows = list(load_csv("mapping.csv"))
    d = os.path.join(REPO, "config", "mapping.d")
    if os.path.isdir(d):
        for f in sorted(os.listdir(d)):
            if f.endswith('.csv'): rows += load_csv(os.path.join("mapping.d", f))
    return rows

def mapping_conflicts(rows=None):
    """{name: [va, ...]} for every name that mapping rows give two or more different VAs.
    functions() keys by name, so all but the last such row would silently never be verified.
    Exact duplicate rows (same name and VA) are harmless and not reported."""
    vas = {}
    for r in (mapping_rows() if rows is None else rows): vas.setdefault(r[0], set()).add(int(r[1], 16))
    return {n: sorted(v) for n, v in vas.items() if len(v) > 1}

def functions():
    """reconstructed functions: name, va, size  ->  {name: (va, size)}
    (a name mapped to several VAs keeps only its last row: lverify reports those as errors)"""
    return {r[0]: (int(r[1], 16), int(r[2], 16)) for r in mapping_rows()}

def symbols():
    """name -> VA for functions and globals"""
    m = {}
    for r in load_csv("names.csv"): m[r[1]] = int(r[0], 16)      # identified, not reconstructed
    m.update({k: v[0] for k, v in functions().items()})
    for r in load_csv("library.csv"): m[r[0]] = int(r[1], 16)
    for r in load_csv("globals.csv"): m[r[0]] = int(r[1], 16)
    return m

_SPECIAL = {'0': '{ctor}', '1': '{dtor}', '_G': "`scalar deleting destructor'",
            '_E': "`vector deleting destructor'", '_7': "`vftable'", 'R': 'operator()',
            '4': 'operator=', '2': 'operator new', '3': 'operator delete'}

def demangle(n):
    """MSVC mangled -> Class::member (good enough to key mapping.csv; no signatures)."""
    if n.startswith(('__imp_', '__real@', '__xmm@')): return n
    if n.startswith('??'):
        code = n[2:4] if n[2] == '_' else n[2]
        rest = n[2 + len(code):]
        scope = rest.split('@@')[0].split('@') if '@@' in rest else []
        if code not in _SPECIAL or not scope:
            return n
        cls = '::'.join(reversed(scope))
        mem = _SPECIAL[code]
        if mem == '{ctor}': mem = scope[0]
        elif mem == '{dtor}': mem = '~' + scope[0]
        return cls + '::' + mem
    if n.startswith('?'):
        toks = n[1:].split('@@')[0].split('@')
        return '::'.join(reversed(toks))
    n = re.sub(r'@\d+$', '', n)
    return n[1:] if n.startswith('_') else n

def disasm(code, addr):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return list(md.disasm(code, addr))
