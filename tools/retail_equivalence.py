"""Fail-closed retail body equivalence, independent of learned symbol pairings.

All instruction bytes and data targets stay exact. Only internal addresses and
external direct control-flow targets may relocate; different external targets
require the same proof recursively. Dependency cycles are checked as a finite
graph, not accepted through a depth cutoff or a provisional cache result.
"""
import collections
import struct

import capstone

def code_falls_through(image, va, insns, code_size, tables=()):
    """Check control flow, not the last opcode: unreachable alignment NOPs are harmless.

    Include every direct internal destination and switch destination as an entry
    even if its dispatch is unreachable. A path into data or a decode gap fails.
    """
    code_end = va + code_size
    by_address = {ins.address: ins for ins in insns}
    pending = [va]
    for ins in insns:
        if (capstone.x86.X86_GRP_JUMP in ins.groups or capstone.x86.X86_GRP_CALL in ins.groups):
            for op in ins.operands:
                if op.type == capstone.x86.X86_OP_IMM and va <= (op.imm & 0xffffffff) < code_end:
                    pending.append(op.imm & 0xffffffff)
    for start, end, dword in tables:
        if dword:
            for offset in range(start, end, 4):
                target = struct.unpack('<I', image.read(va + offset, 4))[0]
                if not va <= target < code_end:
                    return True
                pending.append(target)
    visited = set()
    while pending:
        address = pending.pop()
        if address in visited:
            continue
        visited.add(address)
        ins = by_address.get(address)
        if ins is None:
            return True
        if ins.mnemonic in ('ret', 'retf', 'iret', 'iretd', 'ud2', 'int3', 'hlt'):
            continue
        if capstone.x86.X86_GRP_JUMP in ins.groups:
            for op in ins.operands:
                if op.type != capstone.x86.X86_OP_IMM:
                    continue
                target = op.imm & 0xffffffff
                if va <= target < code_end:
                    pending.append(target)
                elif code_end <= target < va + max((end for _, end, _ in tables), default=code_size):
                    return True
            if ins.mnemonic in ('jmp', 'ljmp'):
                for op in ins.operands:
                    if op.type == capstone.x86.X86_OP_REG:
                        return True
                    if op.type == capstone.x86.X86_OP_MEM and op.mem.base:
                        return True
                continue
        pending.append(ins.address + ins.size)
    return False


class RetailEquivalence:
    def __init__(self, image, spans, table_offset):
        self.image, self.spans, self.table_offset = image, spans, table_offset
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True
        self.bodies = {}
        self.results = {}
        self.reasons = {}
        self.dependencies = {}
        self.relocations = set(getattr(image, 'relocations', ()))
        if hasattr(image, 'pe'):
            import pefile
            image.pe.parse_data_directories(directories=[
                pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_BASERELOC']])
            self.relocations.update(image.base + entry.rva
                                    for block in getattr(image.pe, 'DIRECTORY_ENTRY_BASERELOC', ())
                                    for entry in block.entries if entry.type == 3)

    @staticmethod
    def pair(a, b):
        return (min(a, b), max(a, b))

    def body(self, va):
        if va in self.bodies:
            return self.bodies[va]
        size = self.spans.get(va)
        if not size or size <= 0:
            result = (None, 'unknown function extent')
        else:
            raw = self.image.read(va, size)
            insns = list(self.md.disasm(raw, va))
            tables = self.table_offset(insns, va, size)
            end = size if tables is None else tables[0][0]
            insns = [i for i in insns if i.address < va + end]
            if len(raw) != size or not insns or insns[-1].address + insns[-1].size != va + end:
                result = (None, 'incomplete disassembly')
            elif code_falls_through(self.image, va, insns, end, tables or ()):
                result = (None, 'unproved fallthrough boundary')
            else:
                result = ((size, raw, insns, tables or (), {i.address - va for i in insns}), None)
        self.bodies[va] = result
        return result

    def local(self, pair):
        av, bv = pair
        a, ar = self.body(av)
        b, br = self.body(bv)
        if a is None or b is None:
            return (), ar or br
        size, araw, ai, at, boundaries = a
        bsize, braw, bi, bt, bboundaries = b
        if size != bsize:
            return (), 'body size differs'
        if at != bt or len(ai) != len(bi) or boundaries != bboundaries:
            return (), 'instruction or table layout differs'
        deps = set()
        for ia, ib in zip(ai, bi):
            off = ia.address - av
            if ia.size != ib.size or ia.mnemonic != ib.mnemonic:
                return (), 'instruction differs at +%#x' % off
            ab, bb = bytearray(ia.bytes), bytearray(ib.bytes)
            relative = capstone.x86.X86_GRP_JUMP in ia.groups or capstone.x86.X86_GRP_CALL in ia.groups
            if relative and ia.imm_size:
                aa = next((o.imm & 0xffffffff for o in ia.operands if o.type == capstone.x86.X86_OP_IMM), None)
                ba = next((o.imm & 0xffffffff for o in ib.operands if o.type == capstone.x86.X86_OP_IMM), None)
                if aa is None or ba is None or ia.imm_offset != ib.imm_offset or ia.imm_size != ib.imm_size:
                    return (), 'control-flow operand differs at +%#x' % off
                ain, bin = av <= aa < av + size, bv <= ba < bv + size
                if ain or bin:
                    if not (ain and bin and aa - av == ba - bv and aa - av in boundaries):
                        return (), 'internal control flow differs at +%#x' % off
                elif aa != ba:
                    deps.add(self.pair(aa, ba))
                ab[ia.imm_offset:ia.imm_offset + ia.imm_size] = b'\0' * ia.imm_size
                bb[ib.imm_offset:ib.imm_offset + ib.imm_size] = b'\0' * ib.imm_size
            # Absolute addresses into each body's own code/tables relocate by offset.
            # Every other immediate/displacement, including data and IAT targets,
            # remains byte-exact; equal data contents do not imply equal identity.
            for field, width in ((ia.disp_offset, ia.disp_size), (ia.imm_offset, ia.imm_size)):
                if width != 4 or (relative and field == ia.imm_offset):
                    continue
                aa = struct.unpack_from('<I', ia.bytes, field)[0]
                ba = struct.unpack_from('<I', ib.bytes, field)[0]
                ain, bin = av <= aa < av + size, bv <= ba < bv + size
                if ain or bin:
                    if not (ain and bin and aa - av == ba - bv):
                        return (), 'internal address differs at +%#x' % off
                    if ia.address + field not in self.relocations or ib.address + field not in self.relocations:
                        return (), 'internal immediate lacks relocation at +%#x' % off
                    ab[field:field + width] = bb[field:field + width] = b'\0' * width
            if ab != bb:
                return (), 'instruction bytes or data target differs at +%#x' % off
        for start, end, dword in at:
            if not dword:
                if araw[start:end] != braw[start:end]:
                    return (), 'switch index table differs'
            else:
                for off in range(start, end, 4):
                    aa = struct.unpack_from('<I', araw, off)[0] - av
                    ba = struct.unpack_from('<I', braw, off)[0] - bv
                    if aa != ba or aa not in boundaries:
                        return (), 'switch jump table differs'
                    if av + off not in self.relocations or bv + off not in self.relocations:
                        return (), 'switch target lacks relocation'
        return deps, None

    def equivalent(self, a, b):
        if a == b:
            return True
        root = self.pair(a, b)
        if root in self.results:
            return self.results[root]
        pending = [root]
        visited, bad = set(), {}
        parents = collections.defaultdict(set)
        while pending:
            pair = pending.pop()
            if pair in visited:
                continue
            visited.add(pair)
            if pair in self.results:
                if not self.results[pair]:
                    bad[pair] = self.reasons[pair]
                continue
            deps, reason = self.local(pair)
            self.dependencies[pair] = sorted(deps)
            if reason:
                bad[pair] = reason
            for dep in deps:
                parents[dep].add(pair)
                pending.append(dep)
        queue = collections.deque(bad)
        while queue:
            child = queue.popleft()
            for parent in parents[child]:
                if parent not in bad:
                    bad[parent] = 'dependency %#x/%#x: %s' % (*child, bad[child])
                    queue.append(parent)
        for pair in visited:
            self.results[pair] = pair not in bad
            self.reasons[pair] = bad.get(pair, 'complete relocation-equivalent bodies')
        return self.results[root]


def indexed_spans(image):
    """Use the existing retail index, rejecting conflicting declared extents.

    Optimized entries absent from this index stay unknown rather than using a
    first-return heuristic, which can truncate a multi-return function.
    """
    import common
    import funcindex
    starts = funcindex.starts()
    declared = collections.defaultdict(set)
    for va, size in common.functions().values():
        declared[va].add(size)
    sections = [(image.base + s.VirtualAddress, image.base + s.VirtualAddress + s.SizeOfRawData)
                for s in image.pe.sections if s.Characteristics & 0x20000000]
    out = {}
    for va, nxt in zip(starts, starts[1:]):
        if not any(lo <= va < nxt <= hi for lo, hi in sections):
            continue
        size = len(image.read(va, nxt - va).rstrip(b'\xcc'))
        if declared[va] and declared[va] != {size}:
            continue
        out[va] = size
    return out
