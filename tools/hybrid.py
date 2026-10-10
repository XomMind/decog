"""Experimental optimized hybrid executable: eligible matched game bodies are compiled /Ox and
appended to retail COGMIND.exe, with retail entry points jumping to the optimized bodies.

Retail supplies PE scaffolding, CRT/vendor code and all global data. Optimized code references
retail data/functions using strict /Od pairs and separately corroborated runtime identities.

  hybrid.py symtab <od build dir> <out.csv>        derive strict symbol -> retail VA pairs
  hybrid.py compile <outdir> <symtab.csv>          prepare stand-ins and compile /Ox IL objects
  fullbuild.sh --run python hybrid.py link <outdir> <symtab.csv>   serialized full LTCG link
  hybrid.py patch <outdir> <symtab.csv> <out.exe>   retarget references, add sections, hook entries

Source preparation only writes generated copies under <outdir>/prepared, never src/ or config/.
Selected unproved bodies, including empty constructor stand-ins, are forwarded to strict retail
pairs BEFORE optimization can inline or erase their semantics. tools/hybrid_forwarding.json is
an explicit signature-specific manifest with bounded ABI checks, not complete proof; suffixes/comments are not VAs.
The same manifest resolves selected formerly unpaired externs with explicit identity/ABI evidence;
other unresolved externs remain distinct traps. Bound identity never proves an unreviewed body.

/fp:precise x87 is not proof of bit-exact /Od floating-point behavior: optimized expressions can
lose spill/double-rounding boundaries. A hybrid is experimental until its float policy and
bounded gameplay differential have been validated."""

# Compile/link diagnostics persist in compile-logs/ and link.log; *-status.json records actual exits.
import sys, os, re, struct, bisect, csv, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common
from common import demangle

OPT_CFLAGS = ('/nologo /c /Ox /Ob2 /Oi /Ot /Oy /GF /Gy /GS- /fp:precise /EHsc /MD /GL /W3 '
              '/Iinclude /Isrc /IC:\\_\\_RL\\Protobuffer\\protobuf-3.5.1\\src')


def import_names(theirs_pe):
    """export name -> retail IAT slot VA"""
    out = {}
    for e in theirs_pe.DIRECTORY_ENTRY_IMPORT:
        for i in e.imports:
            if i.name: out[i.name.decode()] = i.address
    return out


def imp_target(name, imps):
    """retail IAT slot for our `__imp_<decorated>` symbol, or None. C names carry one leading
    underscore (cdecl `_exit` is export `exit`; `__exit` is `_exit`), stdcall adds `@N`."""
    d = name[len('__imp_'):]
    if d.startswith('_'): d = re.sub(r'@\d+$', '', d[1:])
    return imps.get(d)


def cmd_symtab(od_dir, out_csv):
    import lverify, pefile
    lverify.DLL, lverify.MAP = os.path.join(od_dir, 'match.dll'), os.path.join(od_dir, 'match.map')
    res = lverify.verify_all(quiet=True)
    mp, ours, theirs = lverify.CTX['v']
    lverify.data_stats()
    print('%d/%d functions MATCH in %s' % (sum(res.values()), len(res), od_dir), file=sys.stderr)
    at = collections.defaultdict(list)                 # our VA -> map names (exact symbol starts)
    for n, va in lverify.MAP_ALL: at[va].append(n)
    found = collections.defaultdict(set)               # our symbol -> {(retail VA, evidence)}
    def add(n, tva, why): found[n].add((tva, why))
    by_name = lverify.code_names(mp, ours)
    for name, (tva, size) in common.functions().items():
        if res.get(name):
            for n in at[by_name[name]]: add(n, tva, 'function')
    stubs = dict((n, va) for va, n in lverify.STUBS)
    for ova, tva in lverify.ALL_PAIRS:
        if ova in at:
            for n in at[ova]:
                if not n.startswith(('??_C@', '__real@', '__xmm@')): add(n, tva, 'pair')
        else:
            s = lverify.stub_interior(ova)
            if s: add(s[0], tva - s[1], 'stub+k')
    for key, tva in lverify.LEARN_FWD.items(): add(key, tva, 'learned')
    ident = theirs.identities
    demangled = collections.Counter(demangle(n) for n in mp)
    for n in mp:
        if n.startswith('__imp_'): continue           # identities key imports by export name; see imp_target
        if n in ident and len(ident[n]) == 1: add(n, next(iter(ident[n])), 'configured')
        elif n.startswith('?') and demangled[demangle(n)] == 1 and len(ident.get(demangle(n), ())) == 1:
            add(n, next(iter(ident[demangle(n)])), 'configured-demangled')
    imps = import_names(theirs.pe)
    for n in mp:
        if n.startswith('__imp_'):
            t = imp_target(n, imps)
            if t: add(n, t, 'import')
    # vtables: our ??_7 slot contents, translated to retail functions, must equal exactly one retail vtable
    fn = {}
    for n, s in found.items():
        vas = {v for v, _ in s}
        if len(vas) == 1: fn[mp.get(n)] = next(iter(vas))
    exe_vt = collections.defaultdict(list)
    for line in open(os.path.join(common.REPO, 'build', 'rtti.csv')):
        f = line.rstrip('\n').split(',')
        if len(f) >= 6 and f[5]: exe_vt[tuple(int(x, 16) for x in f[5].split(';'))].append(int(f[1], 16))
    for n, va in mp.items():
        if not n.startswith('??_7'): continue
        for nslots in sorted({len(k) for k in exe_vt}, reverse=True):
            slots = tuple(fn.get(struct.unpack('<I', ours.read(va + 4 * i, 4))[0]) for i in range(nslots))
            if None not in slots and len(exe_vt.get(slots, ())) == 1:
                add(n, exe_vt[slots][0], 'vtable'); break
    statics, publics, origin = set(), set(), {}
    mapped = read_map(lverify.MAP)
    for n, va, f, org, static in mapped:
        (statics if static else publics).add(n); origin.setdefault(n, org)
    # extent of each defined object in the /Od image: distance to the next symbol (upper bound, incl. padding)
    starts = sorted({va for n, va, f, org, static in mapped if org != '<absolute>'})
    extent = {}
    for n, va, f, org, static in mapped:
        i = bisect.bisect_right(starts, va)
        if i < len(starts): extent.setdefault(n, starts[i] - va)
    etext = [s for s in theirs.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
    elo = theirs.base + etext.VirtualAddress; ehi = elo + etext.Misc_VirtualSize
    text = [s for s in ours.pe.sections if s.Name.rstrip(b'\0') == b'.text'][0]
    tlo = ours.base + text.VirtualAddress; thi = tlo + text.Misc_VirtualSize
    conflicts = 0
    with open(out_csv, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['name', 'va', 'evidence', 'kind', 'stub', 'static', 'origin', 'extent'])
        for n in sorted(x for x in found if x in origin):   # lverify display-name keys are not linker symbols
            vas = {v for v, _ in found[n]}
            if len(vas) != 1:
                conflicts += 1
                print('conflict: %s -> %s' % (n, ' '.join('%#x/%s' % x for x in sorted(found[n]))), file=sys.stderr)
                continue
            ova, tva = mp.get(n), next(iter(vas))
            stub = n in stubs
            if n.startswith('__imp_'): kind = 'import'
            elif stub: kind = 'code' if elo <= tva < ehi else 'data'
            else: kind = 'code' if ova and tlo <= ova < thi else 'data'
            w.writerow([n, '%#x' % tva, '+'.join(sorted({y for _, y in found[n]})), kind,
                        int(stub), int(n in statics and n not in publics), origin[n], extent.get(n, '')])
    print('%d symbols, %d conflicts excluded' % (len(found) - conflicts, conflicts), file=sys.stderr)
    unpaired = sorted(n for n in stubs if n not in found)
    with open(out_csv + '.unpaired', 'w') as f: f.write(''.join(n + '\n' for n in unpaired))
    print('%d of %d stubs have no retail address (unreferenced by matched code)' % (len(unpaired), len(stubs)),
          file=sys.stderr)
    return 0


def load_symtab(path):
    """Strict /Od pairs plus explicit corroborated identities for otherwise unpaired stubs."""
    out = {}
    for r in csv.DictReader(open(path)):
        r['va'] = int(r['va'], 16); r['stub'] = r['stub'] == '1'; r['static'] = r['static'] == '1'
        out[r['name']] = r
    import json
    manifest = os.path.join(common.REPO, 'tools', 'hybrid_forwarding.json')
    for binding in json.load(open(manifest))['bindings']:
        n, va, kind = binding['name'], int(binding['va'], 16), binding['kind']
        if n in out:
            if out[n]['va'] != va or out[n]['kind'] != kind:
                raise ValueError('corroborated identity conflicts with strict symbol pair: %s' % n)
            continue
        out[n] = {'name': n, 'va': va, 'kind': kind, 'stub': True, 'static': False,
                  'evidence': 'corroborated-retail-identity', 'origin': 'stubs.obj', 'extent': ''}
    return out



def write_abs_obj(path, symbols):
    """COFF object defining each (name, value) as an external ABSOLUTE symbol (section -1)."""
    strtab = bytearray(b'\0\0\0\0'); syms = bytearray()
    for name, value in sorted(symbols):
        b = name.encode('latin1')
        field = b.ljust(8, b'\0') if len(b) <= 8 else struct.pack('<II', 0, len(strtab))
        if len(b) > 8: strtab += b + b'\0'
        syms += field + struct.pack('<IhHBB', value & 0xffffffff, -1, 0, 2, 0)
    struct.pack_into('<I', strtab, 0, len(strtab))
    hdr = struct.pack('<HHIIIHH', 0x14c, 0, 0, 20, len(symbols), 0, 0)
    with open(path, 'wb') as f: f.write(hdr + bytes(syms) + bytes(strtab))


def prepare_sources(outdir, srcs, st):
    """Generate selected opaque-retail forwards; report other unproved defined pairs."""
    import json
    manifest = os.path.join(common.REPO, 'tools', 'hybrid_forwarding.json')
    groups = collections.defaultdict(list)
    for entry in json.load(open(manifest))['forwarding']:
        groups[entry['source']].append(entry)
    missing = set(groups) - set(srcs)
    if missing:
        raise ValueError('forwarding manifest references missing sources: %s' % ', '.join(sorted(missing)))
    prepared, audit = {}, []
    for source, entries in groups.items():
        original = os.path.join(common.REPO, source)
        text = open(original).read()
        for entry in entries:
            rows = [st.get(n) for n in entry['symbols']]
            if any(r is None or r['kind'] != 'code' or r['stub'] or 'function' in r['evidence'] for r in rows):
                raise ValueError('forwarded alias must have a strict, defined, unmatched code pair: %s' % entry['symbols'])
            targets = {r['va'] for r in rows}
            if len(targets) != 1:
                raise ValueError('forwarded aliases have different retail targets: %s' % entry['symbols'])
            target = next(iter(targets))
            if text.count(entry['before']) != 1:
                raise ValueError('forwarded definition changed or is ambiguous in %s: %s' % (source, entry['before']))
            if entry.get('external'):
                if any(not n.startswith('??0') for n in entry['symbols']):
                    raise ValueError('external definition removal is limited to reviewed constructors')
                signature = entry['before'].split('{', 1)[0].strip()
                # Out-of-class definitions already have declarations; inline definitions need one.
                replacement = '' if '::' in signature.split('(', 1)[0] else signature + ';'
            else:
                replacement = entry['after'].replace('{target}', '%#x' % target)
            text = text.replace(entry['before'], replacement, 1)
            audit.append({'source': source, 'symbols': entry['symbols'], 'target': '%#x' % target,
                          'external': bool(entry.get('external'))})
        dest = os.path.join(outdir, 'prepared', source)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        if not os.path.exists(dest) or open(dest).read() != text:
            with open(dest, 'w') as f: f.write(text)
        prepared[source] = dest
    forwarded = {n for entry in audit for n in entry['symbols']}
    unhandled = [{'symbol': n, 'target': '%#x' % r['va'], 'origin': r['origin'], 'evidence': r['evidence']}
                 for n, r in sorted(st.items()) if r['kind'] == 'code' and not r['stub'] and not r['static']
                 and 'function' not in r['evidence'] and r['origin'].endswith('.obj')
                 and ':' not in r['origin'] and n not in forwarded]
    with open(os.path.join(outdir, 'forwarding.json'), 'w') as f:
        json.dump({'forwarded': audit, 'bindings': json.load(open(manifest))['bindings'],
                   'unhandled_defined_pairs': unhandled}, f, indent=2)
    return prepared


def compile_inputs(symtab_path):
    """Fingerprint sources, generated-forwarding inputs, and compiler/header trees."""
    import hashlib
    home = os.environ.get('COGMIND_WINE_HOME', os.path.expanduser('~/.cogmind-wine'))
    roots = [os.path.join(common.REPO, p) for p in ('src', 'harness', 'include')]
    roots += [os.path.join(home, 'msvc'),
              os.path.join(home, 'prefix', 'drive_c', '_', '_RL', 'Protobuffer', 'protobuf-3.5.1', 'src')]
    files = {os.path.abspath(symtab_path), os.path.abspath(symtab_path + '.unpaired')}
    files.update(os.path.join(common.REPO, 'tools', p) for p in
                 ('hybrid.py', 'hybrid_opaque.py', 'hybrid_float.py', 'hybrid_forwarding.json', 'sources.py', 'cl.sh', 'cogmindrun.bat'))
    for root in roots:
        for directory, _, names in os.walk(root):
            for name in names:
                if root == os.path.join(home, 'msvc') or os.path.splitext(name)[1].lower() in ('.cpp', '.c', '.h', '.hpp', '.hxx', '.inl', '.inc'):
                    files.add(os.path.join(directory, name))
    digest = hashlib.sha256()
    for path in sorted(files):
        digest.update(path.encode('utf-8') + b'\0')
        with open(path, 'rb') as f:
            digest.update(hashlib.file_digest(f, 'sha256').digest())
    return {'sha256': digest.hexdigest(), 'files': len(files)}


def cmd_compile(outdir, symtab_path):
    """Compile selected opaque-retail source forwards with OPT_CFLAGS into <outdir>/obj."""
    import subprocess, ltcg, json, time
    from concurrent.futures import ThreadPoolExecutor
    outdir = os.path.abspath(outdir)
    objdir = os.path.join(outdir, 'obj'); os.makedirs(objdir, exist_ok=True)
    logdir = os.path.join(outdir, 'compile-logs'); os.makedirs(logdir, exist_ok=True)
    objects_path = os.path.join(outdir, 'objs.txt')
    if os.path.exists(objects_path): os.remove(objects_path)
    srcs = subprocess.run([sys.executable, os.path.join(common.REPO, 'tools', 'sources.py')],
                          capture_output=True, text=True, check=True).stdout.split()
    stems = [os.path.splitext(os.path.basename(s))[0] for s in srcs]
    if len(set(stems)) != len(stems):
        raise ValueError('source basenames collide in hybrid object directory')
    status_path = os.path.join(outdir, 'compile-status.json')
    status = {'state': 'running', 'started_at': time.time(), 'flags': OPT_CFLAGS,
              'symtab': os.path.abspath(symtab_path), 'sources': len(srcs),
              'inputs': compile_inputs(symtab_path)}
    with open(status_path, 'w') as f: json.dump(status, f, indent=2)
    prepared = prepare_sources(outdir, srcs, load_symtab(symtab_path))
    import hybrid_opaque
    from pathlib import Path
    sdk_dir = os.path.join(outdir, 'opaque-sdk')
    sdk_source = os.path.join(outdir, 'opaque-sdk.cpp')
    sdk_preprocessed = os.path.join(outdir, 'opaque-sdk.i')
    Path(sdk_source).write_text(''.join('#include <%s>\n' % h for h in hybrid_opaque.STL_HEADERS))
    rc, output = run_logged('cl /nologo /P /MD /Fi%s %s' %
                            (ltcg.win(sdk_preprocessed), ltcg.win(sdk_source)),
                            os.path.join(logdir, 'opaque-sdk-preprocess.log'))
    if rc:
        raise RuntimeError('Opaque SDK preprocessing failed:\n' + output)
    home = os.environ.get('COGMIND_WINE_HOME', os.path.expanduser('~/.cogmind-wine'))
    sdk_report = hybrid_opaque.prepare_stl_headers(sdk_dir, home, sdk_preprocessed)
    Path(os.path.join(outdir, 'opaque-sdk-report.json')).write_text(json.dumps(sdk_report, indent=2))
    status['opaque_sdk'] = {'headers': len(sdk_report['headers']),
                            'declarations': sum(h['functions'] for h in sdk_report['headers']),
                            'skipped': len(sdk_report['skipped'])}
    with open(status_path, 'w') as f: json.dump(status, f, indent=2)
    def one(s):
        original = os.path.join(common.REPO, s)
        source = prepared.get(s, original)
        obj = os.path.join(objdir, os.path.splitext(os.path.basename(s))[0] + '.obj')
        # Generated copies retain relative quoted-header lookup in the original source directory.
        args = 'cl /I%s %s /I%s /Fo%s %s' % (ltcg.win(sdk_dir), OPT_CFLAGS,
                                            ltcg.win(os.path.dirname(original)),
                                            ltcg.win(obj), ltcg.win(source))
        if os.path.exists(obj): os.remove(obj)
        rc, out = run_logged(args, os.path.join(logdir, os.path.splitext(os.path.basename(s))[0] + '.log'))
        return s, (rc or not os.path.exists(obj) or os.path.getsize(obj) == 0), out
    # Always rebuild: mtime/content-only caches miss transitive MSVC/vendor/source headers.
    failed = []
    with ThreadPoolExecutor(max_workers=int(os.environ.get('JOBS', 4))) as pool:
        for s, bad, out in pool.map(one, srcs):
            shown = [l for l in out.splitlines() if l.strip() and not ltcg.NOISE.match(l.strip())
                     and 'warning' not in l]
            if shown: print('\n'.join(shown), flush=True)
            if bad: failed.append(s)
    inputs_after = compile_inputs(symtab_path)
    if inputs_after != status['inputs']:
        failed.append('<compile inputs changed>')
    if not failed:
        with open(objects_path, 'w') as f:
            f.write('\n'.join(os.path.join(objdir, stem + '.obj') for stem in stems))
    forwarding = json.load(open(os.path.join(outdir, 'forwarding.json')))
    status.update(state='finished', finished_at=time.time(), failed=failed, complete=not failed,
                  forwarded=len(forwarding['forwarded']), bindings=len(forwarding['bindings']),
                  unhandled_defined_pairs=len(forwarding['unhandled_defined_pairs']))
    with open(status_path, 'w') as f: json.dump(status, f, indent=2)
    print('%d sources, %d forwarded bodies, %d unhandled defined pairs, %d failed %s' %
          (len(srcs), len(forwarding['forwarded']), len(forwarding['unhandled_defined_pairs']),
           len(failed), ' '.join(failed)))
    return 1 if failed else 0


HYBRID_BASE = 0xD40000           # our image base: first section RVA 0x1000 lands right after retail SizeOfImage
TRAP_LO, TRAP_STEP = 0x1000, 4   # unpaired stubs: distinct addresses in the never-mapped first 64 KiB


def def_name(n):
    """name as written in a .def EXPORTS line for decorated symbol n"""
    return n[1:] if n.startswith('_') and not n.startswith('__') else n


def run_logged(command, path):
    """Use the existing compiler launcher, but persist diagnostics without capture-pipe EOF waits."""
    import subprocess
    with open(path, 'wb') as log:
        result = subprocess.run([os.path.join(common.REPO, 'tools', 'cl.sh'), 'cmd', '/c', command],
                                cwd=common.REPO, stdout=log, stderr=subprocess.STDOUT)
    with open(path, encoding='utf-8', errors='replace') as log:
        return result.returncode, log.read().replace('\r', '')


def cmd_link(outdir, symtab_path):
    import ltcg, implibs, json, time, hashlib
    outdir = os.path.abspath(outdir)
    compile_status = json.load(open(os.path.join(outdir, 'compile-status.json')))
    if (compile_status.get('state') != 'finished' or not compile_status.get('complete')
            or compile_status.get('flags') != OPT_CFLAGS
            or compile_status.get('symtab') != os.path.abspath(symtab_path)):
        raise ValueError('hybrid link requires a completed current full compile')
    if compile_status.get('inputs') != compile_inputs(symtab_path):
        raise ValueError('hybrid compile inputs changed or lack pre-build fingerprints; recompile')
    st = load_symtab(symtab_path)
    objs = open(os.path.join(outdir, 'objs.txt')).read().split()
    if len(objs) != compile_status['sources']:
        raise ValueError('hybrid object list differs from completed full compile')
    unpaired = [n for n in open(symtab_path + '.unpaired').read().split() if n not in st]
    traps = [(n, TRAP_LO + TRAP_STEP * i) for i, n in enumerate(unpaired)]
    forwarding = json.load(open(os.path.join(outdir, 'forwarding.json')))['forwarded']
    external = {n for entry in forwarding if entry.get('external') for n in entry['symbols']}
    assert traps[-1][1] < 0x10000 if traps else True
    absyms = [(n, r['va']) for n, r in st.items() if r['stub'] or n in external] + traps
    with open(os.path.join(outdir, 'traps.csv'), 'w') as f:
        f.write(''.join('%s,%#x\n' % t for t in traps))
    absobj = os.path.join(outdir, 'abs.obj'); write_abs_obj(absobj, absyms)
    # Export every defined symbol retail code/data can reach: keeps the standard calling convention
    # (LTCG may otherwise give internal-only functions custom ones) and stops LTCG from treating
    # globals as closed (constant-folding initial values retail's own initializers replace).
    exports = sorted(n for n, r in st.items() if not r['stub'] and not r['static'] and n not in external
                     and r['kind'] in ('code', 'data')
                     and r['origin'].endswith('.obj') and ':' not in r['origin'])
    with open(os.path.join(outdir, 'hybrid.def'), 'w') as f:
        f.write('EXPORTS\n')
        for n in exports:
            f.write('  %s%s\n' % (def_name(n), ' DATA' if st[n]['kind'] == 'data' else ''))
    libdir = implibs.ensure()
    extra = ' '.join(ltcg.win(os.path.join(libdir, f)) for f in sorted(os.listdir(libdir)) if f.endswith('.lib'))
    w = lambda p: ltcg.win(os.path.join(outdir, p))
    args = ('/nologo /DLL /NOENTRY /LTCG /OPT:REF /OPT:ICF /BASE:%#x /MAP:%s /DEF:%s /OUT:%s %s %s %s %s'
            % (HYBRID_BASE, w('hybrid.map'), w('hybrid.def'), w('hybrid.dll'),
               ' '.join(ltcg.win(o) for o in objs), ltcg.win(absobj), ltcg.LIBS, extra))
    with open(os.path.join(outdir, 'link.rsp'), 'w') as f: f.write(args + '\n')
    for p in ('hybrid.dll', 'hybrid.map'):
        if os.path.exists(os.path.join(outdir, p)): os.remove(os.path.join(outdir, p))
    status_path = os.path.join(outdir, 'link-status.json')
    status = {'state': 'running', 'started_at': time.time(), 'command': 'link @%s' % w('link.rsp')}
    with open(status_path, 'w') as f: json.dump(status, f, indent=2)
    rc, out = run_logged(status['command'], os.path.join(outdir, 'link.log'))
    errs = [l for l in out.splitlines() if 'error' in l.lower()]
    status.update(state='finished', finished_at=time.time(), returncode=rc, errors=len(errs))
    complete = rc == 0
    for name in ('hybrid.dll', 'hybrid.map'):
        path = os.path.join(outdir, name)
        size = os.path.getsize(path) if os.path.exists(path) else 0
        status[name] = {'bytes': size}
        complete = complete and size > 0
        if size:
            with open(path, 'rb') as f: status[name]['sha256'] = hashlib.file_digest(f, 'sha256').hexdigest()
    status['complete'] = complete
    with open(status_path, 'w') as f: json.dump(status, f, indent=2)
    print('\n'.join(errs[:60])); print('%d exports, %d absolute, %d traps; link rc=%d, %d error lines, complete=%s'
                                     % (len(exports), len(absyms) - len(traps), len(traps), rc, len(errs), complete))
    return 0 if complete else 1


MAP_LINE = re.compile(r'\s*([0-9a-f]{4}):([0-9a-f]{8})\s+(\S+)\s+([0-9a-f]{8})\s+(f\s+)?(?:i\s+)?(\S.*)?$')


def read_map(path):
    """[(name, va, is_func, origin, static)] for every symbol line of a link map"""
    out, static = [], False
    for line in open(path, encoding='latin1'):
        if line.strip() == 'Static symbols': static = True
        m = MAP_LINE.match(line)
        if m: out.append((m.group(3), int(m.group(4), 16), bool(m.group(5)), (m.group(6) or '').strip(), static))
    return out


def cmd_patch(outdir, symtab_path, out_exe):
    import pefile, json
    outdir = os.path.abspath(outdir)
    st = load_symtab(symtab_path)
    dll = pefile.PE(os.path.join(outdir, 'hybrid.dll'))
    exe = pefile.PE(common.EXE)
    base, soi = dll.OPTIONAL_HEADER.ImageBase, dll.OPTIONAL_HEADER.SizeOfImage
    assert base == HYBRID_BASE and exe.OPTIONAL_HEADER.ImageBase + exe.OPTIONAL_HEADER.SizeOfImage == base
    syms = read_map(os.path.join(outdir, 'hybrid.map'))
    img = bytearray(soi)                                           # our image, laid out by VA - base
    secs = [s for s in dll.sections if s.Name.rstrip(b'\0') != b'.reloc']
    for s in secs:
        d = s.get_data()[:max(s.Misc_VirtualSize, 0) or s.SizeOfRawData]
        img[s.VirtualAddress:s.VirtualAddress + len(d)] = d
    def rd(va): return struct.unpack_from('<I', img, va - base)[0]
    def wr(va, v): struct.pack_into('<I', img, va - base, v & 0xffffffff)
    def inside(va): return base <= va < base + soi
    absolute = {n: va for n, va, _, origin, _ in syms if origin == '<absolute>'}
    inimg = sorted((va, n, f, origin, static) for n, va, f, origin, static in syms if inside(va))
    starts = [x[0] for x in inimg]
    text = [s for s in secs if s.Name.rstrip(b'\0') == b'.text'][0]
    tlo, thi = base + text.VirtualAddress, base + text.VirtualAddress + text.Misc_VirtualSize
    imps = import_names(exe)
    report = collections.defaultdict(list)
    # 1. Linker-synthesized pointer slots for ABSOLUTE functions (LNK4049): value is wrongly based (+image
    #    base); fix it, and turn `call/jmp [slot]` into direct rel32 calls.
    slot_target = {}
    for n, va in absolute.items():
        r = st.get(n)
        if r and r['kind'] == 'code' and r['evidence'] == 'corroborated-retail-identity' and va != r['va']:
            if not 0 < va < exe.OPTIONAL_HEADER.ImageBase:
                raise ValueError('late binding would replace a non-trap symbol: %s' % n)
            absolute[n] = r['va']
            report['resolved_function_trap'].append(n)
    for va, n, f, origin, static in inimg:
        if origin == '<linker-defined>' and n.startswith('__imp_') and n[6:] in absolute:
            slot_target[va] = absolute[n[6:]]; wr(va, absolute[n[6:]])
    # 2. Our real import slots -> retail IAT; imports retail lacks get a new descriptor (step 6).
    iat, extra_imports = {}, collections.OrderedDict()
    for va, n, f, origin, static in inimg:
        if n.startswith('__imp_') and va not in slot_target:
            t = imp_target(n, imps)
            if t is not None: iat[va] = t; continue
            d = n[len('__imp_'):]
            export = re.sub(r'@\d+$', '', d[1:]) if d.startswith('_') else d
            extra_imports[va] = (origin.split(':', 1)[1], export)
    report['extra_imports'] = ['%s!%s' % x for x in extra_imports.values()]
    # 5 (first: fixes the layout). SafeSEH: retail table plus every SEH handler our code registers.
    lc = exe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    table = [exe.get_dword_at_rva(lc.SEHandlerTable - exe.OPTIONAL_HEADER.ImageBase + 4 * i) for i in range(lc.SEHandlerCount)]
    ours_h = [va - exe.OPTIONAL_HEADER.ImageBase for va, n, f, origin, static in inimg
              if n.startswith('__ehhandler$') or 'except_handler' in n]
    table = sorted(set(table) | set(ours_h))
    up = lambda x, a: (x + a - 1) // a * a
    salign, falign = exe.OPTIONAL_HEADER.SectionAlignment, exe.OPTIONAL_HEADER.FileAlignment
    delta = base - exe.OPTIONAL_HEADER.ImageBase
    end = up(max(delta + s.VirtualAddress + s.Misc_VirtualSize for s in secs), salign)
    sxd = struct.pack('<%dI' % len(table), *table)
    idata_rva = up(end + len(sxd), salign)
    # New import section: retail descriptors copied, plus one per DLL for the extra imports.
    exe_base = exe.OPTIONAL_HEADER.ImageBase
    old = exe.OPTIONAL_HEADER.DATA_DIRECTORY[1]
    old_desc = exe.get_data(old.VirtualAddress, old.Size)
    old_desc = old_desc[:(len(old_desc) // 20 - 1) * 20]                   # drop the null terminator
    by_dll = collections.OrderedDict()
    for va, (dll_name, export) in extra_imports.items(): by_dll.setdefault(dll_name, []).append((va, export))
    ndesc = len(old_desc) // 20 + len(by_dll) + 1
    idata = bytearray(ndesc * 20); new_desc = []
    new_iat = {}
    for dll_name, items in by_dll.items():
        name_rva = idata_rva + len(idata); idata += dll_name.encode() + b'\0'; idata += b'\0' * (len(idata) & 1)
        hints = []
        for va, export in items:
            hints.append(idata_rva + len(idata)); idata += b'\0\0' + export.encode() + b'\0'; idata += b'\0' * (len(idata) & 1)
        while len(idata) % 4: idata += b'\0'
        ilt = idata_rva + len(idata); idata += struct.pack('<%dI' % (len(hints) + 1), *hints, 0)
        iat_rva = idata_rva + len(idata); idata += struct.pack('<%dI' % (len(hints) + 1), *hints, 0)
        for i, (va, export) in enumerate(items): new_iat[va] = exe_base + iat_rva + 4 * i
        new_desc.append(struct.pack('<IIIII', ilt, 0, 0, name_rva, iat_rva))
    idata[:ndesc * 20] = old_desc + b''.join(new_desc) + b'\0' * 20
    iat.update(new_iat)
    # 3. Base relocations: every absolute address operand our image contains.
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    def insn_at(site):
        """the instruction whose 4-byte address operand is at site"""
        for back in range(1, 8):
            for ins in md.disasm(bytes(img[site - base - back:site - base + 8]), site - back, 1):
                if ins.size > back and (ins.disp_offset == back or ins.imm_offset == back): return ins
        return None
    names_at = collections.defaultdict(list)
    for va, n, f, origin, static in inimg: names_at[va].append((n, f))
    ustarts = sorted(names_at)
    def data_row(va):
        for n, f in names_at.get(va, ()):
            r = st.get(n)
            if r and r['kind'] == 'data' and not f: return n, r
        return None, None
    def ext(r): return int(r['extent']) if r and r.get('extent') else None
    dll.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_BASERELOC']])
    sites = [base + e.rva for b in dll.DIRECTORY_ENTRY_BASERELOC for e in b.entries if e.type == 3]
    retargeted = collections.Counter(); direct = 0
    for site in sites:
        v = rd(site)
        if not inside(v): continue                                  # retail address or trap: final already
        if v in slot_target:
            op = bytes(img[site - base - 2:site - base])
            if tlo <= site < thi and op in (b'\xff\x15', b'\xff\x25'):
                tgt = slot_target[v]
                img[site - base - 2] = 0xe8 if op == b'\xff\x15' else 0xe9
                wr(site - 1, tgt - (site + 3)); img[site - base + 3] = 0x90; direct += 1
            continue
        if v in iat: wr(site, iat[v]); retargeted['import'] += 1; continue
        i = bisect.bisect_right(ustarts, v) - 1
        if i < 0: report['unowned'].append('%#x' % site); continue
        cva = ustarts[i]
        code = [n for n, f in names_at[cva] if f or (st.get(n) or {}).get('kind') == 'code']
        if code:
            r = next((st[n] for n in code if n in st and st[n]['kind'] == 'code' and not st[n]['static']), None)
            if v == cva and r: wr(site, r['va']); retargeted['code'] += 1
            continue                                                # interior of code: switch labels etc.
        cname, row = data_row(cva)
        off = v - cva
        if cname and cname.startswith(('__TI', '__CT', '__CTA')):
            continue  # Compiler metadata and following unnamed EH tables belong to this image.
        if row and (ext(row) is None or off < ext(row)):
            new = row['va'] + off
            wr(site, new); retargeted['data'] += 1; continue
        nname, nrow = data_row(ustarts[i + 1]) if i + 1 < len(ustarts) else (None, None)
        if nrow and ustarts[i + 1] - v <= 64:                        # sym-k: negative index base of the next object
            ins = insn_at(site)
            indexed = ins is not None and any(op.type == capstone.x86.X86_OP_MEM and op.mem.index
                                              for op in ins.operands)
            if row is None or not indexed:
                # Without an index register this is a plain address inside unnamed data of ours (LTCG drops
                # map names of function-local statics, e.g. protobuf once-flags): keep it.
                report['kept_unnamed'].append('%#x %s+%#x' % (site, names_at[cva][0][0], off))
                continue
            wr(site, nrow['va'] - (ustarts[i + 1] - v)); retargeted['data_neg'] += 1; continue
        if row: report['beyond_extent'].append('%#x %s+%#x (extent %s)' % (site, cname, off, ext(row)))
    # 4. Hook matched bodies, but never promote synthetic STL matching probes to runtime code.
    public = {n: va for va, n, f, origin, static in inimg if f and not static}
    by_va = collections.defaultdict(set)
    for n, r in st.items():
        if r['kind'] == 'code' and 'function' in r['evidence'] and n in public: by_va[r['va']].add(n)
    patched = {}
    forwarding = json.load(open(os.path.join(outdir, 'forwarding.json')))['forwarded']
    retail_targets = {int(entry['target'], 16) for entry in forwarding}
    probe_targets = {r['va'] for r in st.values() if r['kind'] == 'code'
                     and 'function' in r['evidence'] and r['origin'] in ('stl_a.obj', 'stl_b.obj')}
    sdk_targets = {r['va'] for symbol, r in st.items() if r['kind'] == 'code'
                   and 'function' in r['evidence']
                   and (demangle(symbol).startswith('std::') or '@std@' in symbol)}
    import hybrid_float
    float_excluded, float_summary = hybrid_float.retail_quarantine()
    for name, (tva, size) in common.functions().items():
        if tva in sdk_targets:
            report['unhooked_placeholder_stl_alias'].append(name)
            continue
        if tva in float_excluded:
            report['unhooked_float_or_unknown_boundary'].append(name)
            continue
        if tva == 0x425ae0:
            # The matching-only OpU1_FontInfo layout declares a map at +0x20;
            # the retail constructor initializes a vector there. Its optimized
            # destructor dereferences the empty vector as a map sentinel.
            report['unhooked_unproved_layout'].append(name)
            continue
        if tva in probe_targets:
            report['unhooked_synthetic_probe'].append(name)
            continue
        if tva in retail_targets:
            report['unhooked_retail_forward_target'].append(name)
            continue
        cands = sorted(by_va.get(tva, ()))
        if not cands: report['unhooked_no_public_body'].append(name); continue
        if size < 5: report['unhooked_short'].append(name); continue
        patched[tva] = public[cands[0]]
    # 4b. Reverse hooks: static CRT/STL objects the linker pulled into our image run retail's copy, so
    #     retail's initialized CRT state (atexit table, SSE2 flag, facet list) is the only one.
    reverse = []
    for va, n, f, origin, static in inimg:
        if f and origin.startswith(('msvcrt:', 'msvcprt:')) and not origin.lower().endswith('.dll') and \
                n in st and st[n]['kind'] == 'code':
            j = bisect.bisect_right(ustarts, va)
            if j < len(ustarts) and ustarts[j] - va < 5: report['reverse_too_short'].append(n); continue
            img[va - base] = 0xe9; struct.pack_into('<i', img, va - base + 1, st[n]['va'] - (va + 5))
            # A retail entry must not jump back to the CRT body we just redirected to it.
            patched.pop(st[n]['va'], None)
            reverse.append(n)
    # 6. Assemble: retail file + padding section + our sections + SafeSEH table + import section.
    data = bytearray(exe.__data__)
    new = [(b'.hpad', delta, 0x1000, b'', 0xC0000080)]
    for s in secs:
        vs = s.Misc_VirtualSize
        raw = bytes(img[s.VirtualAddress:s.VirtualAddress + min(vs, s.SizeOfRawData)])
        new.append((b'.h' + s.Name.rstrip(b'\0')[1:7], delta + s.VirtualAddress, vs, raw, s.Characteristics))
    new.append((b'.hsxd', end, len(sxd), sxd, 0x40000040))
    new.append((b'.hidata', idata_rva, len(idata), bytes(idata), 0xC0000040))
    nsec = exe.FILE_HEADER.NumberOfSections
    shdr = exe.sections[0].get_file_offset()
    if shdr + 40 * (nsec + len(new)) > exe.OPTIONAL_HEADER.SizeOfHeaders: raise SystemExit('no room for section headers')
    data += b'\0' * (up(len(data), falign) - len(data))
    for i, (name, rva, vs, raw, ch) in enumerate(new):
        ptr = len(data) if raw else 0
        rsz = up(len(raw), falign) if raw else 0
        data += raw + b'\0' * (rsz - len(raw))
        struct.pack_into('<8sIIIIIIHHI', data, shdr + 40 * (nsec + i), name.ljust(8, b'\0'), vs, rva, rsz, ptr, 0, 0, 0, 0, ch)
    def fo(va): return exe.get_offset_from_rva(va - exe_base)
    for tva, ova in patched.items():
        data[fo(tva)] = 0xe9; struct.pack_into('<i', data, fo(tva) + 1, ova - (tva + 5))
    struct.pack_into('<H', data, exe.FILE_HEADER.get_file_offset() + 2, nsec + len(new))
    oh = exe.OPTIONAL_HEADER.get_file_offset()
    struct.pack_into('<I', data, oh + 56, up(idata_rva + len(idata), salign))          # SizeOfImage
    struct.pack_into('<II', data, oh + 96 + 8 * 1, idata_rva, ndesc * 20)              # import directory
    lco = exe.get_offset_from_rva(exe.OPTIONAL_HEADER.DATA_DIRECTORY[10].VirtualAddress)
    struct.pack_into('<II', data, lco + 0x40, exe_base + end, len(table))              # SEHandlerTable, Count
    struct.pack_into('<I', data, oh + 64, 0)                                             # CheckSum
    out = pefile.PE(data=bytes(data)); out.OPTIONAL_HEADER.CheckSum = out.generate_checksum()
    out.write(out_exe)
    summary = {'hooked': len(patched), 'reverse_hooked': len(reverse), 'direct_calls': direct,
               'retargeted': dict(retargeted), 'seh_handlers_added': len(ours_h),
               **{k: len(v) for k, v in report.items()}}
    summary['float_quarantine'] = float_summary
    json.dump({'summary': summary, 'details': report, 'reverse_hooks': reverse}, open(out_exe + '.json', 'w'), indent=1)
    print(json.dumps(summary, indent=1))
    return 0


def main(argv):
    if len(argv) >= 3 and argv[0] == 'symtab': return cmd_symtab(argv[1], argv[2])
    if len(argv) >= 3 and argv[0] == 'compile': return cmd_compile(argv[1], argv[2])
    if len(argv) >= 3 and argv[0] == 'link': return cmd_link(argv[1], argv[2])
    if len(argv) >= 4 and argv[0] == 'patch': return cmd_patch(argv[1], argv[2], argv[3])
    print(__doc__); return 2


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
