"""Serialized VS2010 SP1 matching build on native Windows (no Wine).

Run with .venv\\Scripts\\python tools/fullbuild_windows.py --setup --jobs 4.
The kit is private and remains outside version control. See docs/WINDOWS.md.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parent.parent
COMPILE_ROOT = Path(r'C:\_\_RL\COGMIND\_cogmind')
PROTO_ROOT = Path(r'C:\_\_RL\Protobuffer\protobuf-3.5.1')


def historical_paths():
    """Preserve diagnostic __FILE__ literals without changing matching sources."""
    for alias, target in ((COMPILE_ROOT, ROOT),
                          (PROTO_ROOT, ROOT / '3rdparty/protobuf-3.5.1')):
        if alias.exists():
            if not alias.samefile(target):
                raise RuntimeError('Historical compiler path belongs to another checkout: ' + str(alias))
            continue
        if alias.is_symlink():
            raise RuntimeError('Broken historical compiler path: ' + str(alias))
        alias.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(['cmd.exe', '/c', 'mklink', '/J', str(alias), str(target)], check=True)


def setup():
    kit = ROOT / 'cogmind-kit/repo'
    destination = ROOT / 'build/toolchain'
    destination.mkdir(parents=True, exist_ok=True)
    for name, installer, marker in (
        ('vc', 'sp1/vc_stdx86.msi', 'Program Files/Microsoft Visual Studio 10.0/VC/bin/cl.exe'),
        ('sdk', 'sdk71/WinSDKBuild/WinSDKBuild_x86.msi', 'Program Files/Microsoft SDKs/Windows/v7.1/Include/Windows.h'),
    ):
        target = destination / name
        if (target / marker).exists():
            continue
        subprocess.run(['msiexec.exe', '/a', str(kit / 'dls' / installer), '/qn',
                        'TARGETDIR=' + str(target), '/l*v', str(destination / (name + '-extract.log'))], check=True)
        if not (target / marker).exists():
            raise RuntimeError('Incomplete toolchain extraction: ' + str(target))
    retail = ROOT / 'resources/COGMIND.exe'
    if not retail.exists():
        import shutil
        retail.parent.mkdir(exist_ok=True)
        shutil.copy2(kit / 'resources/COGMIND.exe', retail)


def environment():
    home = ROOT / 'build/toolchain'
    vc = Path(os.environ.get('COGMIND_VC', home / 'vc/Program Files/Microsoft Visual Studio 10.0/VC'))
    sdk = Path(os.environ.get('COGMIND_SDK', home / 'sdk/Program Files/Microsoft SDKs/Windows/v7.1'))
    env = os.environ.copy()
    env['PATH'] = ';'.join([str(vc / 'bin'), str(vc.parent / 'Common7/IDE'), env['PATH']])
    env['INCLUDE'] = ';'.join([str(vc / 'include'), str(sdk / 'Include'), str(ROOT / 'include/compat')])
    env['LIB'] = ';'.join([str(vc / 'lib'), str(sdk / 'Lib')])
    env['TMP'] = env['TEMP'] = str(ROOT / 'build/toolchain/tmp')
    Path(env['TMP']).mkdir(exist_ok=True)
    return env


def run(argv, env):
    import shutil
    executable = shutil.which(argv[0], path=env['PATH'])
    if executable is None:
        raise RuntimeError('Tool not found: ' + argv[0])
    argv = [executable] + argv[1:]
    result = subprocess.run(argv, cwd=COMPILE_ROOT, env=env, capture_output=True, text=True, errors='replace')
    return result.returncode, result.stdout + result.stderr


def build(out, jobs, env):
    import common
    import stubobj
    if hashlib.sha256(Path(common.EXE).read_bytes()).hexdigest() != common.EXE_SHA256:
        raise RuntimeError('Wrong retail reference executable')
    out.mkdir(parents=True, exist_ok=True)
    sources = list(dict.fromkeys(s.replace('\\', '/') for s in
        subprocess.check_output([sys.executable, str(ROOT / 'tools/sources.py')], cwd=ROOT, text=True).split()))
    source_hashes = {s: hashlib.sha256((ROOT / s).read_bytes()).hexdigest() for s in sources}
    # Keep unique historical basenames (stubs.obj is recognized by lverify).
    # Duplicate source basenames need path-derived names to avoid races.
    from collections import Counter
    counts = Counter(Path(s).stem.lower() for s in sources)
    def object_name(source):
        return (Path(source).stem if counts[Path(source).stem.lower()] == 1
                else source.replace('/', '_').replace('\\', '_')[:-4])
    flags = ['/nologo', '/c', '/Od', '/Oi', '/GS', '/EHsc', '/MD', '/GL', '/W3',
             '/Iinclude', '/Isrc', '/I' + str(PROTO_ROOT / 'src')]
    def compile_one(source):
        obj = out / (object_name(source) + '.obj')
        rc, log = run(['cl.exe'] + flags + ['/Fo' + str(obj), source.replace('/', '\\')], env)
        (out / (object_name(source) + '.log')).write_text(log)
        return source, obj, rc
    objects, failures = [], []
    print('Compiling %d translation units with %d workers' % (len(sources), jobs), flush=True)
    with ThreadPoolExecutor(jobs) as pool:
        for i, (source, obj, rc) in enumerate(pool.map(compile_one, sources), 1):
            objects.append(obj)
            if rc or not obj.exists():
                failures.append(source)
                print('FAIL ' + source, flush=True)
            if i % 100 == 0:
                print('Compiled %d/%d' % (i, len(sources)), flush=True)
    if failures:
        raise RuntimeError('Compilation failed: ' + ', '.join(failures))
    libs = ['msvcprt.lib', 'msvcrt.lib', 'kernel32.lib', 'user32.lib', 'ole32.lib',
            'imm32.lib', 'wininet.lib', 'rpcrt4.lib']
    system = {'kernel32.dll', 'user32.dll', 'ole32.dll', 'imm32.dll', 'wininet.dll',
              'rpcrt4.dll', 'msvcr100.dll', 'msvcp100.dll'}
    for entry in common.pe().DIRECTORY_ENTRY_IMPORT:
        dll = entry.dll.decode()
        if dll.lower() in system:
            continue
        definition, lib = out / (Path(dll).stem + '.def'), out / (Path(dll).stem + '.lib')
        definition.write_text('LIBRARY "' + dll + '"\nEXPORTS\n' +
                              ''.join('  ' + imp.name.decode() + '\n' for imp in entry.imports if imp.name))
        rc, log = run(['lib.exe', '/nologo', '/machine:x86', '/def:' + str(definition), '/out:' + str(lib)], env)
        if rc:
            raise RuntimeError(log)
        libs.append(str(lib))
    args = ['/nologo', '/DLL', '/LTCG', '/NOENTRY', '/OPT:NOREF', '/OPT:NOICF',
            '/MAP:' + str(out / 'match.map'), '/OUT:' + str(out / 'match.dll')]
    args += [str(o) for o in objects] + libs
    stub = out / 'stubs.obj'
    for attempt in range(2):
        response = out / 'link.rsp'
        response.write_text(subprocess.list2cmdline(args) + '\n')
        print('LTCG link (attempt %d)' % (attempt + 1), flush=True)
        rc, log = run(['link.exe', '@' + str(response)], env)
        (out / ('link%d.log' % attempt)).write_text(log)
        if not rc and (out / 'match.dll').exists() and (out / 'match.map').exists():
            break
        missing = set()
        for line in log.splitlines():
            match = re.search(r'unresolved external symbol (?:"[^\"]*" \((\S+?)\)|(\S+))', line)
            if match:
                missing.add(match.group(1) or match.group(2))
        if not missing or attempt:
            raise RuntimeError(log[-12000:])
        stubobj.write(stub, missing)
        args.append(str(stub))
        print('%d verification-only dependency stubs' % len(missing), flush=True)
    changed = [s for s in sources if hashlib.sha256((ROOT / s).read_bytes()).hexdigest() != source_hashes[s]]
    if changed:
        raise RuntimeError('Sources changed during full build; rerun before verification: ' + ', '.join(changed))
    manifest = {'sources': source_hashes,
                'flags': flags, 'compile_cwd': str(COMPILE_ROOT), 'compiler': run(['cl.exe'], env)[1],
                'dll_sha256': hashlib.sha256((out / 'match.dll').read_bytes()).hexdigest()}
    (out / 'build.json').write_text(json.dumps(manifest, indent=2))
    print('Matching DLL ready: ' + str(out / 'match.dll'), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--setup', action='store_true')
    parser.add_argument('--jobs', type=int, default=4)
    parser.add_argument('--out', type=Path, default=ROOT / 'build/full_windows')
    parser.add_argument('--min-free-gb', type=float, default=12)
    args = parser.parse_args()
    if os.name != 'nt':
        parser.error('Use tools/fullbuild.sh on non-Windows hosts')
    if args.setup:
        setup()
    # Same lock directory as the existing integration build; never silently remove a lock.
    lock = ROOT / 'build/.fullbuild.lock'
    lock.parent.mkdir(exist_ok=True)
    while True:
        try:
            lock.mkdir()
            break
        except FileExistsError:
            print('Waiting for full-build lock', flush=True)
            time.sleep(15)
    try:
        (lock / 'pid').write_text(str(os.getpid()))
        (lock / 'who').write_text('Windows native fullbuild')
        import ctypes
        class Memory(ctypes.Structure):
            _fields_ = [('length', ctypes.c_uint32), ('load', ctypes.c_uint32)] + [
                (n, ctypes.c_uint64) for n in ('total', 'available', 'page_total', 'page_available',
                                              'virtual_total', 'virtual_available', 'extended')]
        mem = Memory()
        mem.length = ctypes.sizeof(mem)
        while True:
            if not ctypes.windll.kernel32.GlobalMemoryStatusEx(ctypes.byref(mem)):
                raise ctypes.WinError()
            if mem.available >= args.min_free_gb * 2**30:
                break
            print('Waiting for %.1f GB available memory (%.1f GB now)' %
                  (args.min_free_gb, mem.available / 2**30), flush=True)
            time.sleep(15)
        historical_paths()
        build(args.out.resolve(), args.jobs, environment())
    finally:
        for name in ('pid', 'who'):
            (lock / name).unlink(missing_ok=True)
        lock.rmdir()


if __name__ == '__main__':
    main()
