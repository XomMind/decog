"""Claim functions in config/claims.txt on origin/main (the shared "I'm working on this" list).
   usage: tools/claim.py claim <va> <owner> <what...>    claim one function (fails if mapped or claimed by someone else)
          tools/claim.py release <va> [<va> ...]          drop claims (done or abandoned)
          tools/claim.py release-mapped <owner-prefix>    drop that owner's claims whose VA is now mapped on origin
          tools/claim.py list                             show current claims
   Each change is committed directly on top of the latest origin/main (only claims.txt changes; local work is never
   included) and pushed immediately, retrying if someone else pushed in between. The local checkout picks the
   change up through the integration loop's origin sync."""
import subprocess, sys, os, tempfile, time, re
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
PATH = 'config/claims.txt'
HEADER = ('# Functions someone is actively reconstructing. Pull, add a line, commit and push BEFORE starting;\n'
          '# remove the line in the commit that maps the function (or when abandoning it).\n'
          '# va        size    name / what                       owner   date\n')

def git(*a, check=True, env=None, inp=None):
    r = subprocess.run(('git',) + a, capture_output=True, text=True, env=env, input=inp)
    if check and r.returncode: raise RuntimeError('git %s: %s' % (' '.join(a), r.stderr.strip()))
    return r.stdout

def norm(va): return '0x%x' % int(va, 16)

def mapped_vas():
    out = git('grep', '-h', '-o', r',0x[0-9a-fA-F]*,', 'origin/main', '--', 'config/mapping.d', check=False)
    return {norm(l.strip(',')) for l in out.split() if l.strip(',')}

def current():
    r = subprocess.run(['git', 'show', 'origin/main:' + PATH], capture_output=True, text=True)
    return r.stdout if r.returncode == 0 else HEADER

def entries(text):
    return [(norm(l.split()[0]), l) for l in text.splitlines() if l.strip() and not l.startswith('#') and re.match(r'0x[0-9a-fA-F]+', l)]

def push(edit, msg):
    """edit(text) -> new text or None (no change). Commits on origin/main and pushes, retrying on races."""
    for attempt in range(8):
        git('fetch', '-q', 'origin')
        text = current()
        new = edit(text)
        if new is None: return False
        idx = tempfile.mktemp(); env = dict(os.environ, GIT_INDEX_FILE=idx)
        try:
            git('read-tree', 'origin/main', env=env)
            blob = git('hash-object', '-w', '--stdin', inp=new).strip()
            git('update-index', '--add', '--cacheinfo', '100644,%s,%s' % (blob, PATH), env=env)
            tree = git('write-tree', env=env).strip()
        finally:
            if os.path.exists(idx): os.remove(idx)
        c = git('commit-tree', tree, '-p', 'origin/main', '-m', msg).strip()
        r = subprocess.run(['git', 'push', '-q', 'origin', c + ':refs/heads/main'], capture_output=True, text=True)
        if r.returncode == 0: return True
        time.sleep(2 + attempt * 2)
    raise RuntimeError('push kept failing (someone pushing constantly?)')

def size_of(va):
    try:
        sys.path.insert(0, 'tools'); import fnsize
        return '0x%x' % fnsize.fn_size(int(va, 16))
    except Exception: return '?'

cmd = sys.argv[1] if len(sys.argv) > 1 else 'list'
if cmd == 'list':
    git('fetch', '-q', 'origin'); print(current(), end='')
elif cmd == 'claim':
    va, owner, what = norm(sys.argv[2]), sys.argv[3], ' '.join(sys.argv[4:]) or '?'
    def edit(text):
        if va in mapped_vas(): sys.exit('%s is already mapped on origin/main: pick another' % va)
        for v, l in entries(text):
            if v == va:
                if l.split()[-2] == owner: print('already yours:', l); return None
                sys.exit('%s is claimed: %s' % (va, l))
        line = '%-11s %-7s %-33s %-7s %s\n' % (va, size_of(va), what, owner, time.strftime('%Y-%m-%d'))
        return (text if text.endswith('\n') else text + '\n') + line
    if push(edit, 'Claim %s (%s)' % (va, owner)): print('claimed', va)
elif cmd in ('release', 'release-mapped'):
    if cmd == 'release': vas = {norm(v) for v in sys.argv[2:]}; pref = None
    else: pref = sys.argv[2]; vas = None
    gone = []
    def edit(text):
        del gone[:]
        mv = mapped_vas() if pref else None
        keep = []
        for l in text.splitlines(True):
            e = entries(l)
            if e:
                v = e[0][0]; owner = l.split()[-2]
                if (vas is not None and v in vas) or (pref and owner.startswith(pref) and v in mv): gone.append(v); continue
            keep.append(l)
        return ''.join(keep) if gone else None
    if push(edit, 'Release claims: %s' % ' '.join(sorted(vas or [])) if vas else 'Release claims for matched functions'):
        print('released', ' '.join(gone))
else:
    sys.exit(__doc__)
