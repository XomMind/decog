"""Import libraries for the game's third-party DLLs, generated from COGMIND.exe's own
   import table (so exactly the functions the game uses). Cached in build/implib/."""
import sys, os, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common

SYSTEM = {'KERNEL32.dll', 'USER32.dll', 'ole32.dll', 'IMM32.dll', 'WININET.dll', 'RPCRT4.dll',
          'MSVCR100.dll', 'MSVCP100.dll'}

def ensure():
    out = os.path.join(common.REPO, 'build', 'implib')
    if os.path.isdir(out) and any(f.endswith('.lib') for f in os.listdir(out)): return out
    os.makedirs(out, exist_ok=True)
    cmds = []
    for e in common.pe().DIRECTORY_ENTRY_IMPORT:
        dll = e.dll.decode()
        if dll in SYSTEM: continue
        base = os.path.splitext(dll)[0]
        with open(os.path.join(out, base + '.def'), 'w') as f:
            f.write('LIBRARY "%s"\nEXPORTS\n' % dll)
            for i in e.imports:
                if i.name: f.write('  %s\n' % i.name.decode())
        rel = os.path.relpath(out, common.REPO).replace('/', '\\')
        cmds.append('lib /nologo /def:%s\\%s.def /machine:x86 /out:%s\\%s.lib' % (rel, base, rel, base))
    subprocess.run([os.path.join(common.REPO, 'tools', 'cl.sh'), 'cmd', '/c', ' && '.join(cmds)],
                   cwd=common.REPO, capture_output=True)
    return out

if __name__ == '__main__':
    print(ensure()); print(sorted(os.listdir(ensure())))
