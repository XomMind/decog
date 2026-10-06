"""Annotated, CFG-carved disassembly of one (giant) exe function, for semantic reconstruction.
   usage: gdis.py 0xVA [--summary] [--blocks]
   - true extent by recursive descent from the entry (jcc/jmp targets, jump tables), so data
     following a function does not inflate its size;
   - basic blocks with labels L_<off> and predecessor lists;
   - operands annotated: callee/global names (config csvs), C string literals, float constants;
   - --summary: callees (ordered by first use, with counts), strings, globals, switch tables, EH state count.
   Read-only on the repo; reuses tools/common.py."""
import sys, os, re, struct, collections
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', '..', 'tools'))
import common, capstone
from capstone import x86

_P = common.pe()
SECS = {s.Name.rstrip(b'\0').decode(): (s.VirtualAddress + 0x400000, s.Misc_VirtualSize) for s in _P.sections}

def in_sec(name, a):
    lo, n = SECS[name]; return lo <= a < lo + n

_NAMES = None
def names():
    global _NAMES
    if _NAMES is None:
        _NAMES = {v: k for k, v in common.symbols().items()}
        _NAMES.update(common.imports())
    return _NAMES

def cstring(a):
    if not (in_sec('.rdata', a) or in_sec('.data', a)): return None
    b = common.read_va(a, 512)
    end = b.find(b'\0')
    if end < 1: return None
    s = b[:end]
    if all(32 <= c < 127 or c in (9, 10, 13) for c in s) and (len(s) >= 2 or a in STRING_ARGS):
        return s.decode('latin1')
    return None

STRING_ARGS = set()

def label(a, ins=None):
    n = names().get(a)
    if n: return common.demangle(n) if not n.startswith('__imp_') else n
    return None

def fconst(ins):
    for op in ins.operands:
        if op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index:
            a = op.mem.disp & 0xffffffff
            if in_sec('.rdata', a) and ins.mnemonic.startswith('f'):
                if op.size == 4: return repr(struct.unpack('<f', common.read_va(a, 4))[0])
                if op.size == 8: return repr(struct.unpack('<d', common.read_va(a, 8))[0])
    return None

class Fn:
    def __init__(self, va):
        self.va = va
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
        self.md = md
        self.ins = {}            # addr -> insn
        self.leaders = {va}
        self.tables = []         # (jmp addr, table va, [targets])
        self.bytetables = []
        self.walk()

    def dis1(self, a):
        if a in self.ins: return self.ins[a]
        i = next(self.md.disasm(common.read_va(a, 16), a))
        self.ins[a] = i
        return i

    def walk(self):
        work = [self.va]; seen = set()
        while work:
            a = work.pop()
            while a not in seen:
                seen.add(a)
                i = self.dis1(a)
                m = i.mnemonic
                nxt = a + i.size
                if m in ('ret', 'retn'): break
                if m == 'movzx' and i.operands[1].type == x86.X86_OP_MEM:
                    mem = i.operands[1].mem
                    d = mem.disp & 0xffffffff
                    if in_sec('.text', d) and i.operands[1].size == 1: self.bytetables.append(d)
                if m == 'jmp' or (m.startswith('j') and m != 'jmp'):
                    op = i.operands[0]
                    if op.type == x86.X86_OP_IMM:
                        t = op.imm & 0xffffffff
                        self.leaders.add(t); work.append(t)
                        if m == 'jmp': break
                        self.leaders.add(nxt); a = nxt; continue
                    if op.type == x86.X86_OP_MEM and op.mem.scale == 4 and not op.mem.base:
                        tbl = op.mem.disp & 0xffffffff
                        tg = []
                        k = tbl
                        while True:
                            v = struct.unpack('<I', common.read_va(k, 4))[0]
                            if not (self.va <= v < tbl) or (k != tbl and (k in self.bytetables or any(k == t[1] for t in self.tables))): break
                            tg.append(v); k += 4
                            if len(tg) > 4096: break
                        self.tables.append((a, tbl, tg))
                        for t in tg: self.leaders.add(t); work.append(t)
                        break
                    break
                if m == 'call' and i.operands[0].type == x86.X86_OP_IMM:
                    t = i.operands[0].imm & 0xffffffff
                    n = names().get(t, '')
                    if 'CxxThrowException' in n or 'invalid_parameter' in n: break
                a = nxt
        self.order = sorted(self.ins)
        self.end = max(a + self.ins[a].size for a in self.order)
        self.leaders &= set(self.ins)
        # blocks
        self.blocks = []
        cur = None
        for a in self.order:
            if a in self.leaders or cur is None or self.ins_prev_end != a:
                cur = [a]; self.blocks.append(cur)
            else: cur.append(a)
            self.ins_prev_end = a + self.ins[a].size
            i = self.ins[a]
            if i.mnemonic.startswith('j') or i.mnemonic in ('ret', 'retn'): cur = None
        self.preds = collections.defaultdict(list)
        for b in self.blocks:
            last = self.ins[b[-1]]
            for t in self.succ(last): self.preds[t].append(b[0])

    def succ(self, i):
        m = i.mnemonic; nxt = i.address + i.size
        if m in ('ret', 'retn'): return []
        if m.startswith('j'):
            op = i.operands[0]
            if op.type == x86.X86_OP_IMM:
                t = op.imm & 0xffffffff
                return [t] if m == 'jmp' else [t, nxt]
            for (ja, tbl, tg) in self.tables:
                if ja == i.address: return sorted(set(tg))
            return []
        return [nxt]

    def annotate(self, i):
        op = i.op_str
        va = self.va
        def lab(mo):
            a = int(mo.group(0), 16)
            if i.mnemonic[0] == 'j' and va <= a < self.end: return 'L_%04x' % (a - va)
            n = label(a)
            if n: return '<%s>' % n
            s = cstring(a)
            if s is not None: return '%s"%s"' % (mo.group(0), s.replace('\n', '\\n')[:80])
            return mo.group(0)
        op = re.sub(r'0x[0-9a-f]{5,8}', lab, op)
        if i.mnemonic == 'call' and i.operands[0].type == x86.X86_OP_IMM and '<' not in op:
            op = 'unknown%x' % (i.operands[0].imm & 0xffffffff)
        f = fconst(i)
        if f: op += '   ; ' + f
        return op

    def dump(self, out=sys.stdout):
        print('%08x  %s  extent %#x (index size %#x), %d insns, %d blocks, %d switch tables' % (
            self.va, label(self.va) or '', self.end - self.va, fn_size(self.va), len(self.ins), len(self.blocks), len(self.tables)), file=out)
        for b in self.blocks:
            p = self.preds.get(b[0], [])
            ps = ','.join('%04x' % (x - self.va) for x in sorted(set(p)))
            print('L_%04x:%s' % (b[0] - self.va, ('    ; from ' + ps) if ps and not (len(p) == 1 and p[0] != b[0] and self.fallthrough(p[0], b[0])) else ''), file=out)
            for a in b:
                i = self.ins[a]
                print('  %04x  %-6s %s' % (a - self.va, i.mnemonic, self.annotate(i)), file=out)
                for (ja, tbl, tg) in self.tables:
                    if ja == a:
                        print('        ; switch table %#x: %s' % (tbl, ' '.join('%d:L_%04x' % (k, t - self.va) for k, t in enumerate(tg))), file=out)

    def fallthrough(self, pblock, a):
        for b in self.blocks:
            if b[0] == pblock:
                last = self.ins[b[-1]]
                return last.address + last.size == a and not last.mnemonic.startswith('j')
        return False

    def summary(self):
        calls = collections.OrderedDict(); strs = collections.OrderedDict(); globs = collections.Counter(); floats = collections.Counter()
        eh = set()
        for a in self.order:
            i = self.ins[a]
            if i.mnemonic == 'call':
                op = i.operands[0]
                if op.type == x86.X86_OP_IMM:
                    t = op.imm & 0xffffffff; n = label(t) or 'unknown%x' % t
                elif op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index:
                    n = label(op.mem.disp & 0xffffffff) or 'indirect[%#x]' % (op.mem.disp & 0xffffffff)
                else: n = 'virtual(%s)' % i.op_str
                calls[n] = calls.get(n, 0) + 1
            for op in i.operands:
                v = None
                if op.type == x86.X86_OP_IMM: v = op.imm & 0xffffffff
                elif op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index: v = op.mem.disp & 0xffffffff
                if v is None or i.mnemonic == 'call' or i.mnemonic.startswith('j'): continue
                if v < 0x401000: continue
                s = cstring(v)
                if s is not None and in_sec('.rdata', v): strs[s] = strs.get(s, 0) + 1
                elif in_sec('.data', v) or in_sec('.rdata', v):
                    f = fconst(i)
                    if f: floats[f] += 1
                    else: globs['%#x %s' % (v, label(v) or '')] += 1
            if i.mnemonic == 'mov' and 'byte ptr [ebp - 4]' in i.op_str or 'dword ptr [ebp - 4]' in i.op_str and i.mnemonic == 'mov':
                if i.operands[1].type == x86.X86_OP_IMM: eh.add(i.operands[1].imm)
        return calls, strs, globs, floats, eh

def fn_size(va):
    from fnsize import fn_size as f
    try: return f(va)
    except SystemExit: return 0

if __name__ == '__main__':
    va = int(sys.argv[1], 16)
    f = Fn(va)
    if '--summary' in sys.argv:
        calls, strs, globs, floats, eh = f.summary()
        print('%#x %s extent %#x index %#x insns %d blocks %d switches %d eh-states %d' % (
            va, label(va) or '', f.end - va, fn_size(va), len(f.ins), len(f.blocks), len(f.tables), len(eh)))
        print('== callees (%d distinct, %d calls)' % (len(calls), sum(calls.values())))
        for k, v in calls.items(): print('  %4d  %s' % (v, k))
        print('== strings (%d)' % len(strs))
        for k, v in strs.items(): print('  %4d  %r' % (v, k))
        print('== globals (%d)' % len(globs))
        for k, v in sorted(globs.items()): print('  %4d  %s' % (v, k))
        print('== float constants: %s' % dict(floats))
    elif '--calls' in sys.argv:
        # every call with its stack arguments (first argument first) as pushed since the previous call;
        # pushed registers are replaced by their last `mov/lea reg, src` (ret(off) = result of the call at off),
        # an object copied onto the stack (sub esp,N + ctor) shows as <tmpN>
        pend, ecx, regs = [], None, {}
        for a in f.order:
            i = f.ins[a]
            m, ops = i.mnemonic, f.annotate(i)
            if m == 'push':
                pend.append(regs.get(ops, ops))
            elif m in ('mov', 'lea', 'movzx', 'movsx') and ',' in ops:
                dst, src = [s.strip() for s in ops.split(',', 1)]
                src = regs.get(src, src)
                if m == 'lea': src = '&' + src
                if dst in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi'): regs[dst] = src
                if dst == 'ecx': ecx = src
            elif m == 'sub' and ops.startswith('esp,'):
                pend.append('<tmp%s>' % ops.split(',')[1].strip())
            elif m == 'call':
                print('%04x  %-44s ecx=%-26s args=[%s]' % (a - va, ops[:70], ecx, ', '.join(reversed(pend))))
                pend, ecx, regs = [], None, {'eax': 'ret(%04x)' % (a - va)}
            elif m == 'add' and ops.startswith('esp,'):
                pend = []
    else:
        f.dump()
