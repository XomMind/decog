"""Lift 0x7a0e80 (Scorekeeper stat set -> Protobuf::Stats, 1013 straight-line statements) to C++.
   usage: lift_7a0e80.py > src/op/op_g1_scorestats.cpp body
   Each statement in the exe is
       push <id>; mov ecx,[ebp+8]; call StatSet::get; push eax; mov ecx,[ebp+0xc];
       call mutable_a; mov ecx,eax; call mutable_b; ...; call <int32 setter>
   The setters are ICF-folded (one body per field offset), so the field is recovered from the
   setter's store offset and the 32-bit layout of the message class the last mutable_ returns
   (member order parsed from src/web/scoresheet.pb.h). Byte-exact MATCH under tools/try.sh."""
import sys, os, re
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.join(HERE, '..', '..', '..')
sys.path.insert(0, os.path.join(REPO, 'tools')); sys.path.insert(0, HERE)
import common, capstone, gdis
from capstone import x86

H = open(os.path.join(REPO, 'src', 'web', 'scoresheet.pb.h')).read()
CLASSES = {m.group(1): m.group(2).split(' private:\n')[-1]
           for m in re.finditer(r'^class (\w+) : public ::google::protobuf::Message.*?\n(.*?)^};', H, re.S | re.M)}
MRET = {(m.group(2), m.group(3)): m.group(1)
        for m in re.finditer(r'inline ::Protobuf::(\w+)\* (\w+)::mutable_(\w+)\(\)', H)}

def layout(cname):
    """32-bit offsets of the data members (vptr at 0)."""
    off, out = 4, {}
    for line in CLASSES[cname].splitlines():
        line = line.strip()
        if not line or line.startswith(('friend', '//', 'static', 'typedef', 'template', 'enum')) or '(' in line: continue
        mm = re.match(r'(?:mutable )?(.+?)\s+(\w+);$', line)
        if not mm: continue
        t, n = mm.groups()
        if t.endswith('*') or 'ArenaStringPtr' in t or 'InternalMetadata' in t: sz, al = 4, 4
        elif 'RepeatedPtrField' in t: sz, al = 16, 4
        elif 'RepeatedField' in t: sz, al = 12, 4
        elif t == 'bool': sz, al = 1, 1
        elif 'int64' in t or t == 'double': sz, al = 8, 8
        else: sz, al = 4, 4
        off = (off + al - 1) // al * al
        out[off] = (n, t); off += sz
    return out

def main():
    names = {}
    for k, v in common.symbols().items(): names.setdefault(v, []).append(common.demangle(k))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    def store_off(a):
        for i in md.disasm(common.read_va(a, 64), a):
            if i.mnemonic == 'mov' and i.operands[0].type == x86.X86_OP_MEM and i.operands[0].mem.base != x86.X86_REG_EBP:
                return i.operands[0].mem.disp
    f = gdis.Fn(0x7a0e80)
    ins = [f.ins[a] for a in f.order]
    k = 4
    while k < len(ins) - 3:
        sid = ins[k].operands[0].imm
        assert ins[k + 1].op_str == 'ecx, dword ptr [ebp + 8]' and ins[k + 4].op_str == 'ecx, dword ptr [ebp + 0xc]'
        k += 5; chain = []
        while True:
            chain.append(ins[k].operands[0].imm & 0xffffffff); k += 1
            if ins[k].mnemonic == 'mov' and ins[k].op_str == 'ecx, eax': k += 1; continue
            break
        cls, path = 'Stats', []
        for a in chain[:-1]:
            (field,) = [m.group(2) for n in names[a] for m in [re.match(r'Protobuf::(\w+)::mutable_(\w+)$', n)] if m and m.group(1) == cls]
            path.append(field); cls = MRET[(cls, field)]
        name, t = layout(cls)[store_off(chain[-1])]
        assert 'int32' in t, (cls, name)
        print('\tpbStats->%s->set_%s(stats->get472440(%d));' % ('->'.join('mutable_%s()' % p for p in path), name[:-1], sid))

if __name__ == '__main__':
    main()
