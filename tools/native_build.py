"""Native (macOS arm64) build probe: compile every src/**/*.cpp with the host clang, then link the objects into a
   dylib to see what is missing. Nothing here touches the MSVC/LTCG matching build.
   usage: native_build.py [-j N] [--no-link]
   Output (build/native/):
     obj/*.o            objects of files that compile
     status.json        per file: ok | stl (only explicit STL instantiations fail: not needed natively) | fail + first error
     link.txt           raw ld output
     missing.txt        undefined symbols (demangled), one per line; `unknownXXXXXX` names carry the exe VA
     duplicates.txt     symbols defined by more than one object
   Flags: -fms-extensions (taking the address of temporaries), Itanium ABI, LP64. Struct layouts written for the
   32-bit exe (char pad[0x74 - sizeof(Console)]) are NOT valid here: those files show up as failures."""
import sys, os, re, json, subprocess, concurrent.futures as cf, glob, collections
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(REPO, 'build', 'native')
CXX = os.environ.get('CXX', 'c++')
FLAGS = ['-std=c++11', '-arch', 'arm64', '-O0', '-fms-extensions', '-Wno-error=address-of-temporary', '-w',
         '-Iinclude', '-Isrc', '-I3rdparty/protobuf-3.5.1/src', '-I3rdparty/physfs-2.0.3']
STL_ONLY = re.compile(r'explicit instantiation|variable cannot be defined in an explicit instantiation')

def compile_one(src):
    o = os.path.join(OUT, 'obj', src.replace('/', '_')[:-4] + '.o')
    r = subprocess.run([CXX] + FLAGS + ['-c', src, '-o', o], cwd=REPO, capture_output=True, text=True)
    if r.returncode == 0: return src, dict(status='ok', obj=os.path.relpath(o, REPO))
    errs = re.findall(r'(.*?error: .*)', r.stderr)
    if errs and all(STL_ONLY.search(e) for e in errs): return src, dict(status='stl', first=errs[0][:200])
    return src, dict(status='fail', first=(errs or [r.stderr.strip()[:200]])[0][:300])

def demangle(names):
    if not names: return []
    r = subprocess.run(['c++filt', '-n'], input='\n'.join(n[1:] if n.startswith('_') else n for n in names), capture_output=True, text=True)
    return r.stdout.split('\n')[:len(names)]

def main(argv):
    jobs = int(argv[argv.index('-j') + 1]) if '-j' in argv else os.cpu_count()
    os.makedirs(os.path.join(OUT, 'obj'), exist_ok=True)
    for f in glob.glob(os.path.join(OUT, 'obj', '*.o')): os.remove(f)
    srcs = sorted(glob.glob(os.path.join(REPO, 'src', '**', '*.cpp'), recursive=True))
    srcs = [os.path.relpath(s, REPO) for s in srcs]
    with cf.ThreadPoolExecutor(jobs) as ex: status = dict(ex.map(compile_one, srcs))
    json.dump(status, open(os.path.join(OUT, 'status.json'), 'w'), indent=1, sort_keys=True)
    c = collections.Counter(v['status'] for v in status.values())
    print('compile: %d ok, %d stl-instantiation-only (skipped), %d fail of %d files' % (c['ok'], c['stl'], c['fail'], len(srcs)))
    if '--no-link' in argv: return
    objs = sorted(v['obj'] for v in status.values() if v['status'] == 'ok')
    r = subprocess.run([CXX, '-arch', 'arm64', '-dynamiclib', '-o', os.path.join(OUT, 'libcogmind_native.dylib')] + objs +
                       ['-Wl,-undefined,error', '-Wl,-multiply_defined,error', '-Wl,-fatal_warnings'], cwd=REPO, capture_output=True, text=True)
    open(os.path.join(OUT, 'link.txt'), 'w').write(r.stderr)
    und = sorted(set(re.findall(r'^\s+"([^"]+)", referenced from', r.stderr, re.M)))
    dup = sorted(set(re.findall(r"^duplicate symbol '([^']+)' in", r.stderr, re.M)))
    open(os.path.join(OUT, 'missing.txt'), 'w').write('\n'.join(demangle(und)) + '\n')
    open(os.path.join(OUT, 'duplicates.txt'), 'w').write('\n'.join(demangle(dup)) + '\n')
    va = [n for n in demangle(und) if re.search(r'unknown[0-9a-f]{6}\b', n)]
    print('link: %d undefined symbols (%d named unknownXXXXXX, i.e. unreconstructed exe functions), %d duplicate definitions' % (len(und), len(va), len(dup)))

if __name__ == '__main__': main(sys.argv[1:])
