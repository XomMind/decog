"""Pooled literals compare through NUL; binary data must not truncate at NUL."""
import contextlib
import io
from pathlib import Path
import struct
import sys
from types import SimpleNamespace
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lverify

class PE:
    def __init__(self, base, data):
        self.OPTIONAL_HEADER = SimpleNamespace(ImageBase=base, SizeOfImage=len(data))
        self.data = data
    def parse_data_directories(self, **kwargs): pass
    def get_data(self, rva, size): return self.data[rva:rva + size]

def fixture(base, storage, aliases=True):
    data = b'\x68' + struct.pack('<I', base + 11) + b'\xc3' + b'\xcc' * 2 + storage
    names = {base + 8: {'??_C@_0_test'}} if aliases else {}
    return lverify.Image(PE(base, data), names)

a = fixture(0x400000, b'prefix\0aaaaaaaa')
b = fixture(0x10000000, b'prefix\0bbbbbbbb')
assert b.resolve(b.base + 11) == {'??_C@_0_pooled_suffix'}
assert lverify.const_len('??_C@_0_pooled_suffix', b, b.base + 11) == 4
with contextlib.redirect_stdout(io.StringIO()):
    assert lverify.compare('suffix', a, a.base, b, b.base, 6, False)
    c = fixture(0x10000000, b'preXix\0bbbbbbbb')
    assert not lverify.compare('changed suffix', a, a.base, c, c.base, 6, False)
    a = fixture(0x400000, b'abc\0AAAAxxx', False)
    b = fixture(0x10000000, b'abc\0BBBBxxx', False)
    assert not lverify.compare('binary NUL', a, a.base, b, b.base, 6, False)
print('Literal verifier PASS: suffix relocation accepted; changed strings/binary data rejected')

CTOR = '??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@PBD@Z'
def argument_fixture(base, storage, constructor=True):
    code = b'\x68' + struct.pack('<I', base + 32) + b'\xb9' + struct.pack('<I', base + 48)
    code += b'\xe8' + struct.pack('<i', 64 - 15) + b'\xc3'
    data = code.ljust(32, b'\xcc') + storage
    data = data.ljust(64, b'\0') + b'\xc3'
    return lverify.Image(PE(base, data), {base + 48: {'object'}, base + 64: {CTOR if constructor else 'other'}})
with contextlib.redirect_stdout(io.StringIO()):
    a = argument_fixture(0x400000, b'.x\0AAAA')
    b = argument_fixture(0x10000000, b'.x\0BBBB')
    assert lverify.compare('typed short literal', a, a.base, b, b.base, 16, False)
    c = argument_fixture(0x10000000, b'.z\0BBBB')
    assert not lverify.compare('changed typed literal', a, a.base, c, c.base, 16, False)
    a = argument_fixture(0x400000, b'.x\0AAAA', False)
    b = argument_fixture(0x10000000, b'.x\0BBBB', False)
    assert not lverify.compare('untyped argument', a, a.base, b, b.base, 16, False)
print('Typed literal PASS: string constructor required; changed contents rejected')

def word_fixture(base, storage):
    code = b'\x66\xa1' + struct.pack('<I', base + 8) + b'\xc3\xcc'
    return lverify.Image(PE(base, code + storage), {})
with contextlib.redirect_stdout(io.StringIO()):
    a = word_fixture(0x400000, b'w\0AAAAAA')
    b = word_fixture(0x10000000, b'w\0BBBBBB')
    assert lverify.compare('word data', a, a.base, b, b.base, 7, False)
    c = word_fixture(0x10000000, b'w\1BBBBBB')
    assert not lverify.compare('changed word data', a, a.base, c, c.base, 7, False)
print('Memory operand PASS: full read width checked; unrelated trailing data ignored')

def call_fixture(base, storage, callee):
    # push literal; push edx; call callee   (const char* is the argument of a std::string function)
    code = b'\x68' + struct.pack('<I', base + 32) + b'\x52' + b'\xe8' + struct.pack('<i', 64 - 11) + b'\xc3'
    data = code.ljust(32, b'\xcc') + storage
    data = data.ljust(64, b'\0') + b'\xc3'
    return lverify.Image(PE(base, data), {base + 64: {callee}})
OPPLUS = '??$?HDU?$char_traits@D@std@@V?$allocator@D@1@@std@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@ABV10@PBD@Z'
with contextlib.redirect_stdout(io.StringIO()):
    a = call_fixture(0x400000, b')\0\0\0(\0\0\0', OPPLUS)
    b = call_fixture(0x10000000, b')\0\0\0XYZ\0', OPPLUS)
    assert lverify.compare('operator+ literal', a, a.base, b, b.base, 12, False)
    c = call_fixture(0x10000000, b']\0\0\0XYZ\0', OPPLUS)
    assert not lverify.compare('changed operator+ literal', a, a.base, c, c.base, 12, False)
    a = call_fixture(0x400000, b')\0\0\0(\0\0\0', 'other')
    b = call_fixture(0x10000000, b')\0\0\0XYZ\0', 'other')
    assert not lverify.compare('non-string callee', a, a.base, b, b.base, 12, False)
print('String call argument PASS: any std::string(const char*) callee compares through NUL; other callees stay strict')
