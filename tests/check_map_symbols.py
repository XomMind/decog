"""PUBLIC code must not be hidden by a same-named STATIC helper or data stub."""
from pathlib import Path
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lverify

mapping = ''' Publics by Value
 0001:00000000 ?wavelet@@YAXXZ 10001000 f public.obj
 0003:00000000 ?helper@@YAXXZ 30001000 stubs.obj
 0003:00001000 ?missing@@YAXXZ 30002000 stubs.obj
 0003:00002000 ?data@@3HA 30003000 f.obj
 Static symbols
 0001:00001000 ?wavelet@@YAXXZ 10002000 f local.obj
 0001:00002000 ?helper@@YAXXZ 10003000 f local.obj
 0001:00003000 ?local@@YAXXZ 10004000 f first.obj
 0001:00004000 ?local@@YAXXZ 10005000 f second.obj
 0003:00003000 ?data@@3HA 30004000 local.obj
'''

original_map = lverify.MAP
try:
    with tempfile.TemporaryDirectory() as directory:
        path = Path(directory) / 'match.map'
        path.write_text(mapping)
        lverify.MAP = str(path)
        symbols = lverify.load_map()
        assert symbols['?wavelet@@YAXXZ'] == 0x10001000
        assert symbols['?helper@@YAXXZ'] == 0x10003000
        assert symbols['?local@@YAXXZ'] == 0x10005000
        assert symbols['?data@@3HA'] == 0x30004000
        aliases = lverify.map_names(symbols)
        assert '?wavelet@@YAXXZ' in aliases[0x10001000]
        assert '?wavelet@@YAXXZ' in aliases[0x10002000]
        assert len(lverify.MAP_ALL) == 9
        assert len(lverify.STUBS) == 2 and lverify.STUB_SLOT[0] == 4096
finally:
    lverify.MAP = original_map

print('Map symbol precedence PASS: PUBLIC code, STATIC code over stubs, all copies retained')
