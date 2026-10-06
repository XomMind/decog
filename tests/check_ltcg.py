"""A successful shell status must never accept a missing/stale linker output."""
import contextlib
import io
from pathlib import Path
import sys
import tempfile
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import ltcg

with tempfile.TemporaryDirectory(dir=Path(ltcg.common.REPO) / 'build') as scratch:
    output = Path(scratch)
    (output / 'match.dll').write_bytes(b'stale')
    (output / 'match.map').write_text('stale')
    commands = []
    def fake_run(command):
        commands.append(command)
        if command.startswith('cl '):
            obj = command.split('/Fo', 1)[1].split()[0]
            (Path(ltcg.common.REPO) / obj.replace('\\', '/')).write_bytes(b'object')
            return 0, ''
        assert command.startswith('link @') and len(command) < 200
        return 0, 'File name is too long.'
    ltcg.run = fake_run
    ltcg.implibs.ensure = lambda: scratch
    with contextlib.redirect_stdout(io.StringIO()):
        result = ltcg.main(scratch, ['src/game/unused%d.cpp' % i for i in range(300)])
    assert result == 1
    assert not (output / 'match.dll').exists() and not (output / 'match.map').exists()
    assert len(commands) == 301
    assert 'unused299.obj' in (output / 'link.rsp').read_text()
print('Build verifier PASS: short commands/response file; silent link failure rejects stale outputs')
