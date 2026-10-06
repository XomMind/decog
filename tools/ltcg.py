"""Compile sources the way Cogmind was built and LTCG-link them into <outdir>/match.dll.
   usage: ltcg.py <outdir> <src.cpp ...>
   Unresolved externals are satisfied with a generated stub object (see stubobj.py), so a
   function can be matched before its callees are reconstructed. Prints compiler/linker
   diagnostics; exit status 1 if compilation fails."""
import sys, os, re, subprocess
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common, stubobj, implibs

CFLAGS = '/nologo /c /Od /Oi /GS /EHsc /MD /GL /W3 /Iinclude /Isrc /IC:\\_\\_RL\\Protobuffer\\protobuf-3.5.1\\src'
LIBS = 'msvcprt.lib msvcrt.lib kernel32.lib user32.lib ole32.lib imm32.lib wininet.lib rpcrt4.lib'
NOISE = re.compile(r'^(Generating code|Finished generating code|[\w.-]+\.cpp|.*warning LNK4210.*|.*LNK4088.*)$')

def win(p): return os.path.relpath(p, common.REPO).replace('/', '\\')

def run(cmd):
    r = subprocess.run([os.path.join(common.REPO, 'tools', 'cl.sh'), 'cmd', '/c', cmd],
                       cwd=common.REPO, capture_output=True, text=True, errors='replace')
    return r.returncode, (r.stdout + r.stderr).replace('\r', '')

def main(outdir, srcs):
    outdir = os.path.abspath(outdir); os.makedirs(outdir, exist_ok=True)
    libdir = implibs.ensure()
    objs = []
    for s in srcs:
        objs.append(os.path.join(outdir, os.path.splitext(os.path.basename(s))[0] + '.obj'))
    # Each TU gets its own short command. Wine cmd can report an overlong command
    # without setting errorlevel, so also require every expected output to exist.
    for filename in ('match.dll', 'match.map'):
        path = os.path.join(outdir, filename)
        if os.path.exists(path): os.remove(path)
    for o in objs:
        if os.path.exists(o): os.remove(o)
    def compile_one(job):
        source, obj = job
        return source, obj, run('cl %s /Fo%s %s' % (CFLAGS, win(obj), win(source)))
    failed = []
    with ThreadPoolExecutor(max_workers=int(os.environ.get('JOBS', os.cpu_count() or 4))) as pool:
        for source, obj, (rc, out) in pool.map(compile_one, zip(srcs, objs)):
            shown = [l for l in out.splitlines() if l.strip() and not NOISE.match(l.strip())]
            if shown: print('\n'.join(shown), flush=True)
            if rc != 0 or not os.path.exists(obj): failed.append(source)
    if failed:
        print('Build failed; no partial link: ' + ' '.join(failed)); return 1
    stub = os.path.join(outdir, 'stubs.obj')
    if os.path.exists(stub): os.remove(stub)
    extra_libs = ' '.join(win(os.path.join(libdir, f)) for f in sorted(os.listdir(libdir)) if f.endswith('.lib'))
    response = os.path.join(outdir, 'link.rsp')
    link_args = ('/nologo /DLL /LTCG /NOENTRY /OPT:NOREF /OPT:NOICF /MAP:%s /OUT:%s %s %s %s'
                 % (win(os.path.join(outdir, 'match.map')), win(os.path.join(outdir, 'match.dll')),
                    ' '.join(win(o) for o in objs), LIBS, extra_libs))
    link = 'link @%s' % win(response)
    for attempt in range(2):
        with open(response, 'w') as f:
            f.write(link_args + (' ' + win(stub) if os.path.exists(stub) else '') + '\n')
        rc, out = run(link)
        missing = set()
        for l in out.splitlines():
            m = re.search(r'unresolved external symbol (?:"[^"]*" \((\S+?)\)|(\S+))', l)
            if m: missing.add(m.group(1) or m.group(2))
        if rc == 0 and all(os.path.exists(os.path.join(outdir, f)) for f in ('match.dll', 'match.map')): break
        if not missing or attempt:
            print('\n'.join(l for l in out.splitlines() if l.strip() and not NOISE.match(l.strip()))); return 1
        stubobj.write(stub, missing)
    if os.path.exists(stub):
        print('(%d unresolved symbols stubbed)' % len(stubobj_names(stub)))
    return 0

def stubobj_names(path):
    import coff_names
    return coff_names.names(path)

if __name__ == '__main__':
    sys.exit(main(sys.argv[1], sys.argv[2:]))
