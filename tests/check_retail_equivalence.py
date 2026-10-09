"""Complete-span equivalence must not hide tails, data identity or recursive differences."""
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lverify
from retail_equivalence import RetailEquivalence


class Image:
    def __init__(self, bodies, relocations=()):
        self.bodies, self.relocations = bodies, relocations

    def read(self, va, size):
        for start, body in self.bodies.items():
            if start <= va < start + len(body):
                return body[va - start:va - start + size]
        return b''


def proof(bodies, spans=None, relocations=()):
    return RetailEquivalence(Image(bodies, relocations),
                             spans if spans is not None else {va: len(b) for va, b in bodies.items()},
                             lverify.inline_table_offset)


def call(va, target):
    return b'\xe8' + struct.pack('<i', target - va - 5)


def value(n):
    return b'\xb8' + struct.pack('<I', n) + b'\xc3'


assert proof({0x1000: value(1), 0x2000: value(1)}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: value(1), 0x2000: value(2)}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\xc3', 0x2000: b'\xc3\x90\xc3'}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\x0f', 0x2000: b'\x0f'}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\xc3' + value(1), 0x2000: b'\xc3' + value(2)}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: value(1), 0x2000: value(1)}, {0x1000: 6}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\xa1' + struct.pack('<I', 0x7000) + b'\xc3',
                  0x2000: b'\xa1' + struct.pack('<I', 0x8000) + b'\xc3',
                  0x7000: b'\x01\0\0\0', 0x8000: b'\x01\0\0\0'}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\x75\x01\x90\xc3', 0x2000: b'\x75\x00\x90\xc3'}).equivalent(0x1000, 0x2000)
assert not proof({0x1000: b'\xeb\x7f', 0x2000: b'\xeb\x7f'}).equivalent(0x1000, 0x2000)
# Numeric immediates are not relocations merely because their values fall inside a body.
assert not proof({0x1000: value(0x1000), 0x2000: value(0x2000)}).equivalent(0x1000, 0x2000)
assert proof({0x1000: value(0x1000), 0x2000: value(0x2000)},
             relocations=(0x1001, 0x2001)).equivalent(0x1000, 0x2000)

# More than two recursive levels: the leaf difference must reach the root.
bodies = {}
for base in (0x1000, 0x2000):
    for step in range(6):
        va = base + step * 0x10
        bodies[va] = call(va, va + 0x10) + b'\xc3'
    bodies[base + 0x60] = value(1)
p = proof(bodies)
assert p.equivalent(0x1000, 0x2000)
bodies[0x2060] = value(2)
p = proof(bodies)
assert not p.equivalent(0x1000, 0x2000)
assert not p.equivalent(0x1020, 0x2020)

# A mutual-recursion cycle is equivalent only if every dependency checks out.
bodies = {0x1000: call(0x1000, 0x1010) + b'\xc3',
          0x2000: call(0x2000, 0x2010) + b'\xc3',
          0x1010: call(0x1010, 0x1000) + call(0x1015, 0x1020) + b'\xc3',
          0x2010: call(0x2010, 0x2000) + call(0x2015, 0x2020) + b'\xc3',
          0x1020: value(1), 0x2020: value(1)}
assert proof(bodies).equivalent(0x1000, 0x2000)
bodies[0x2020] = value(2)
p = proof(bodies)
assert not p.equivalent(0x1000, 0x2000)
assert not p.equivalent(0x1010, 0x2010)


def table(base, destination=7):
    return b'\xff\x24\x85' + struct.pack('<I', base + 9) + b'\xc3\xc3' + struct.pack('<I', base + destination)

relocs = (0x1003, 0x1009, 0x2003, 0x2009)
assert proof({0x1000: table(0x1000), 0x2000: table(0x2000)}, relocations=relocs).equivalent(0x1000, 0x2000)
assert not proof({0x1000: table(0x1000), 0x2000: table(0x2000, 8)}, relocations=relocs).equivalent(0x1000, 0x2000)

def aligned_table(base):
    return (b'\xff\x24\x85' + struct.pack('<I', base + 10)
            + b'\xc3\x90\x90' + struct.pack('<I', base + 7))

assert proof({0x1000: aligned_table(0x1000), 0x2000: aligned_table(0x2000)},
             relocations=(0x1003, 0x100a, 0x2003, 0x200a)).equivalent(0x1000, 0x2000)

def fallthrough_table(base):
    return (b'\x74\x07\xff\x24\x85' + struct.pack('<I', base + 10)
            + b'\x90' + struct.pack('<I', base + 9))

p = proof({0x401000: fallthrough_table(0x401000), 0x402000: fallthrough_table(0x402000)},
          relocations=(0x401005, 0x40100a, 0x402005, 0x40200a))
assert not p.equivalent(0x401000, 0x402000)
assert p.reasons[(0x401000, 0x402000)] == 'unproved fallthrough boundary'

def indirect_reentry(base):
    return (b'\xb8' + struct.pack('<I', base + 14) + b'\xff\xe0'
            + b'\xff\x24\x8d' + struct.pack('<I', base + 15) + b'\x90'
            + struct.pack('<I', base + 5) + struct.pack('<I', base + 5))

offs = (1, 10, 15, 19)
p = proof({0x401000: indirect_reentry(0x401000), 0x402000: indirect_reentry(0x402000)},
          relocations=tuple(0x401000 + o for o in offs) + tuple(0x402000 + o for o in offs))
assert not p.equivalent(0x401000, 0x402000)
assert p.reasons[(0x401000, 0x402000)] == 'unproved fallthrough boundary'
print('Retail equivalence PASS: full tails, boundaries, data identity, deep dependencies, cycles, control flow, tables')
