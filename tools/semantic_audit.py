"""Audit mapped names against embedded diagnostics without changing match symbols.

Usage: .venv/bin/python tools/semantic_audit.py [--json]
Requires build/namestrings.csv (tools/namestrings.py). Mapping rows are claims,
not a fresh lverify result. Diagnostic labels are evidence, not rename commands.
"""
import argparse
import collections
import csv
import json
import os

import capstone
import common


def audit():
    mapped = collections.defaultdict(set)
    sizes = collections.defaultdict(set)
    for name, address, size in common.mapping_rows():
        va = int(address, 16)
        mapped[va].add(name)
        sizes[va].add(int(size, 16))

    candidates = collections.defaultdict(list)
    with open(os.path.join(common.REPO, 'build', 'namestrings.csv')) as stream:
        for label, address, count, functions in csv.reader(stream):
            for function in functions.split(';'):
                if function and int(function, 16) in mapped:
                    candidates[int(function, 16)].append((label, int(address, 16), int(count)))

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    findings, rejected = [], []
    for va, labels in sorted(candidates.items()):
        # Conflicting extents require review, not an arbitrary choice of one row.
        if len(sizes[va]) != 1:
            rejected.append(dict(va=hex(va), reason='conflicting mapped extents',
                                 sizes=sorted(sizes[va])))
            continue
        references = collections.defaultdict(list)
        for ins in md.disasm(common.read_va(va, next(iter(sizes[va]))), va):
            for operand in ins.operands:
                if operand.type == capstone.x86.X86_OP_IMM:
                    references[operand.imm & 0xffffffff].append(hex(ins.address))
        evidence = []
        for label, address, count in labels:
            expected = label.encode('ascii') + b'\0'
            if common.read_va(address, len(expected)) != expected:
                reason = 'cached label does not match executable bytes'
            elif address not in references:
                reason = 'no decoded immediate reference inside mapped extent'
            else:
                evidence.append(dict(label=label[:-2], string_va=hex(address),
                                     instruction_vas=references[address],
                                     cached_referring_functions=count))
                continue
            rejected.append(dict(va=hex(va), label=label, string_va=hex(address), reason=reason))
        names = sorted(mapped[va])
        normalized = {common.demangle(name) for name in names}
        disagreements = sorted({item['label'] for item in evidence} - normalized)
        if disagreements:
            findings.append(dict(va=hex(va), mapped_names=names,
                                 differing_labels=disagreements, evidence=evidence))

    aliases = [dict(va=hex(va), names=sorted(names))
               for va, names in sorted(mapped.items()) if len(names) > 1]
    # Do not collapse by name: the same spelling at multiple addresses matters too.
    by_name = collections.defaultdict(set)
    for va, names in mapped.items():
        for name in names:
            by_name[name].add(va)
    conflicts = [dict(name=name, addresses=[hex(va) for va in sorted(addresses)])
                 for name, addresses in sorted(by_name.items()) if len(addresses) > 1]
    return dict(summary=dict(mapped_addresses=len(mapped), alias_addresses=len(aliases),
                             name_address_conflicts=len(conflicts),
                             diagnostic_disagreements=len(findings),
                             rejected_cached_evidence=len(rejected)),
                diagnostic_disagreements=findings, rejected_cached_evidence=rejected,
                name_address_conflicts=conflicts, aliases=aliases)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--json', action='store_true', help='include all aliases and evidence')
    args = parser.parse_args()
    result = audit()
    if args.json:
        print(json.dumps(result, indent=2))
        return
    for key, value in result['summary'].items():
        print('%s: %d' % (key, value))
    for item in result['diagnostic_disagreements']:
        print('\n%s %s' % (item['va'], ', '.join(item['mapped_names'])))
        print('  differing diagnostics: ' + ', '.join(item['differing_labels']))
        for evidence in item['evidence']:
            print('  %s at %s, referenced by %s' %
                  (evidence['label'], evidence['string_va'], ', '.join(evidence['instruction_vas'])))
    for item in result['rejected_cached_evidence']:
        print('\nRejected cached evidence: ' + json.dumps(item, sort_keys=True))
    for item in result['name_address_conflicts']:
        print('\nConflicting mapping name: ' + json.dumps(item, sort_keys=True))


if __name__ == '__main__':
    main()
