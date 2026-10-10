"""Conservative hybrid hook quarantine; not a floating-point equivalence proof.

Keep original FP bodies and every indexed caller intact. Unknown/indirect calls and
incomplete instruction decoding also seed the quarantine: the graph cannot prove
that these paths avoid floating-point work. No compiler FP flag is an exemption.
"""
import collections
import json
from pathlib import Path
import capstone
import common


def is_float(instruction):
    mnemonic = instruction.mnemonic
    return (capstone.x86.X86_GRP_FPU in instruction.groups
            or mnemonic in {'wait', 'fwait', 'ldmxcsr', 'stmxcsr', 'fxsave', 'fxrstor',
                            'xsave', 'xsaveopt', 'xsavec', 'xsaves', 'xrstor', 'xrstors'}
            or mnemonic.startswith(('cvt', 'vcvt', 'round', 'vround'))
            or (mnemonic.endswith(('ss', 'sd', 'ps', 'pd'))
                and mnemonic.startswith(('add', 'sub', 'mul', 'div', 'sqrt', 'rcp',
                                         'rsqrt', 'min', 'max', 'cmp', 'comi', 'ucomi',
                                         'mov', 'and', 'or', 'xor', 'unpck', 'shuf',
                                         'hadd', 'hsub'))))


def retail_quarantine():
    graph = json.loads((Path(common.REPO) / 'build/callgraph.json').read_text())
    sizes = {int(key, 16): value for key, value in graph['sizes'].items()}
    edges = {int(key, 16): {int(value, 16) for value in values}
             for key, values in graph['edges'].items()}
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    decoder.detail = True
    roots = collections.defaultdict(set)
    for address, size in sizes.items():
        decoded = 0
        for instruction in decoder.disasm(common.read_va(address, size), address):
            decoded += instruction.size
            if is_float(instruction):
                roots['floating_point'].add(address)
            if instruction.mnemonic in ('call', 'jmp') and instruction.operands:
                operand = instruction.operands[0]
                if operand.type != capstone.x86.X86_OP_IMM:
                    roots['indirect_control'].add(address)
                elif not address <= operand.imm < address + size and operand.imm not in sizes:
                    roots['unindexed_control'].add(address)
        if decoded != size:
            roots['incomplete_decode'].add(address)
    roots['unindexed_hook'] = {address for address, size in common.functions().values()
                              if address not in sizes}
    reverse = collections.defaultdict(set)
    for caller, callees in edges.items():
        for callee in callees:
            reverse[callee].add(caller)
    excluded = set().union(*roots.values())
    pending = list(excluded)
    while pending:
        for caller in reverse[pending.pop()]:
            if caller not in excluded:
                excluded.add(caller)
                pending.append(caller)
    return excluded, {'indexed_functions': len(sizes),
                      'seed_counts': {reason: len(values) for reason, values in roots.items()},
                      'excluded_with_callers': len(excluded)}


if __name__ == '__main__':
    import sys
    excluded, summary = retail_quarantine()
    output = {'summary': summary, 'excluded': ['%#x' % address for address in sorted(excluded)]}
    if len(sys.argv) == 2:
        Path(sys.argv[1]).write_text(json.dumps(output, indent=2))
    print(json.dumps(summary, indent=2))
