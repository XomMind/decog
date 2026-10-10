"""Address-preserving installation must preserve opcodes, branches and tables."""
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from rebuild_windows import relocate_body


class Image:
    def __init__(self, va, body):
        self.va, self.body = va, body

    def read(self, va, size):
        return self.body[va - self.va:va - self.va + size]


def body(va, global_va, target):
    return b'\x55\x8b\xec\xa1' + struct.pack('<I', global_va) + b'\xe8' + struct.pack('<i', target - va - 13) + b'\x5d\xc3'


compiled = body(0x10000000, 0x10100000, 0x10001000)
retail = body(0x400000, 0xcf0000, 0x401000)
assert relocate_body(Image(0x10000000, compiled), 0x10000000,
                     Image(0x400000, retail), 0x400000, len(retail)) == retail
# A nearby jump retains its instruction displacement after address placement.
compiled = b'\xeb\x01\x90\xc3'
assert relocate_body(Image(0x10000000, compiled), 0x10000000,
                     Image(0x400000, compiled), 0x400000, len(compiled)) == compiled
# Switch table: jmp [eax*4+table], ret, then one absolute destination.
def switch(va):
    return b'\xff\x24\x85' + struct.pack('<I', va + 8) + b'\xc3' + struct.pack('<I', va + 7)
assert relocate_body(Image(0x10000000, switch(0x10000000)), 0x10000000,
                     Image(0x400000, switch(0x400000)), 0x400000, 12) == switch(0x400000)
try:
    relocate_body(Image(0x10000000, b'\x90\xc3'), 0x10000000,
                  Image(0x400000, b'\x55\xc3'), 0x400000, 2)
    raise AssertionError('Unmatched opcode was accepted')
except ValueError:
    pass
print('Windows relocation PASS: external addresses, relative calls, short jumps, switch tables, opcode rejection')
