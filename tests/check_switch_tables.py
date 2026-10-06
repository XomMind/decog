"""Reject changed code or switch destinations; accept relocated identical tables."""
import contextlib
import io
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lverify

class Image:
    def __init__(self, base, data):
        self.lo, self.hi = base, base + len(data)
        self.data = data
    def read(self, va, size):
        return self.data[va - self.lo:va - self.lo + size]
    def resolve(self, va):
        return None

def image(base, destinations=(7, 8), opcode=0xc3):
    return Image(base, b'\xff\x24\x85' + struct.pack('<I', base + 9)
                 + bytes([opcode, 0xc3])
                 + b''.join(struct.pack('<I', base + d) for d in destinations))

def matches(a, b):
    with contextlib.redirect_stdout(io.StringIO()):
        return lverify.compare('switch self-check', a, a.lo, b, b.lo, 17, False)

a = image(0x400000)
assert matches(a, image(0x10000000))
assert not matches(a, image(0x10000000, destinations=(8, 7)))
assert not matches(a, image(0x10000000, destinations=(7, 9)))
assert not matches(a, image(0x10000000, opcode=0x90))
print('Switch verifier PASS: relocation accepted; altered targets/code rejected')
