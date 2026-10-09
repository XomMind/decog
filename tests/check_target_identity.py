"""A wrong configured callee must not become a MATCH through learned pairing."""
from pathlib import Path
import contextlib
import io
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import lverify


class Image:
    def __init__(self, base, target, names):
        self.lo, self.hi = base, base + 0x10000
        self.base, self.target, self.names = base, target, names
        self.code = None
        self.name_targets = {}
        for va, aliases in names.items():
            for name in aliases:
                self.name_targets.setdefault(name, set()).add(va)
        generated = {lverify.demangle(n) for aliases in names.values() for n in aliases
                     if n.startswith('?') and lverify.demangle(n) != n}
        self.identities = {n: vas for n, vas in self.name_targets.items() if n not in generated}

    def read(self, va, size):
        body = self.code if self.code is not None else b'\xe8' + struct.pack('<i', self.target - self.base - 5) + b'\xc3'
        return body[va - self.base:va - self.base + size]

    def resolve(self, va):
        return self.names.get(va)


def check(target, names, expected, onames=None, pointer=False, offset=0):
    lverify.LEARN_FWD.clear()
    ours = Image(0x100000, 0x101000, {0x101000: onames or {'callee'}})
    theirs = Image(0x400000, target, names)
    if pointer:
        ours.code = b'\xb8' + struct.pack('<I', ours.target + offset) + b'\xc3'
        theirs.code = b'\xb8' + struct.pack('<I', theirs.target) + b'\xc3'
    with contextlib.redirect_stdout(io.StringIO()):
        result = lverify.compare('caller', theirs, theirs.base, ours, ours.base, 6, False)
    assert result == expected, (target, names, result)
    if not expected:
        assert not lverify.LEARN_FWD and not lverify.LAST_PAIRS


check(0x401000, {0x401000: {'callee'}}, True)
check(0x402000, {0x401000: {'callee'}, 0x402000: {'wrong'}}, False)
check(0x402000, {0x401000: {'callee'}}, False)
check(0x402000, {0x402000: {'wrong'}}, True)  # genuinely unconfigured source symbol

scalar = '?set@XColor@@QAEXEEE@Z'
copy = '?set@XColor@@QAEXABU1@@Z'
overloads = {0x401000: {scalar, 'XColor::set'}, 0x402000: {copy, 'XColor::set'}}
check(0x401000, overloads, True, {scalar, 'XColor::set'})
check(0x402000, overloads, False, {scalar, 'XColor::set'})
check(0x401000, {0x401000: {copy, 'XColor::set'}}, False, {scalar, 'XColor::set'})
check(0x402000, overloads, False, {scalar, 'XColor::set'}, pointer=True)
check(0x401000, overloads, True, {scalar, 'XColor::set'}, pointer=True)

public_ctor = '??0RepeatedPtrFieldBase@internal@protobuf@google@@QAE@XZ'
protected_ctor = '??0RepeatedPtrFieldBase@internal@protobuf@google@@IAE@XZ'
other_sig = '??0RepeatedPtrFieldBase@internal@protobuf@google@@IAE@H@Z'
check(0x401000, {0x401000: {protected_ctor}}, True, {public_ctor})
check(0x402000, {0x401000: {protected_ctor}}, False, {public_ctor})
check(0x401000, {0x401000: {other_sig, lverify.demangle(other_sig)}}, False, {public_ctor, lverify.demangle(public_ctor)})

old_stubs, old_slot = lverify.STUBS[:], lverify.STUB_SLOT[0]
try:
    lverify.STUBS[:] = [(0x101000, 'callee'), (0x102000, 'other')]
    lverify.STUB_SLOT[0] = 4096
    check(0x401004, {0x401000: {'callee'}}, True, pointer=True, offset=4)
    check(0x402004, {0x401000: {'callee'}}, False, pointer=True, offset=4)
finally:
    lverify.STUBS[:] = old_stubs
    lverify.STUB_SLOT[0] = old_slot

for raw in (b'', b'\x0f', b'\xc3\x0f'):
    ours = Image(0x100000, 0, {})
    theirs = Image(0x400000, 0, {})
    ours.code = theirs.code = raw
    with contextlib.redirect_stdout(io.StringIO()):
        assert not lverify.compare('incomplete body', theirs, theirs.base, ours, ours.base, max(1, len(raw)), False)

lverify.STAGE.clear()
assert lverify.learn({'unknown'}, 0x401000)
assert not lverify.learn({'unknown'}, 0x402000)
print('Target identity PASS: configured addresses, overload collisions, wrong targets, unknown consistency')
