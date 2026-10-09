#!/usr/bin/env python3
"""Classify strict target failures without changing mappings or allowing aliases.

Usage: classify_targets.py [--dir build/full] [--out build/target_audit]
Writes .json, .csv and .log with exact build/config hashes and every rejected
operand. Indexed retail body equivalence is evidence, not overload identity.
"""
import argparse
import collections
import contextlib
import csv
import hashlib
import json
from pathlib import Path

import common
import funcindex
import lverify
import progress
from fnsize import fn_size
from retail_equivalence import RetailEquivalence, indexed_spans


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def coverage(results):
    functions = common.functions()
    matched = {functions[name][0]: name for name, ok in results.items() if ok}
    named = {int(r[0], 16): r[1] for r in common.load_csv('names.csv')}
    for name, (va, _) in functions.items():
        named.setdefault(va, name)
    lib = {int(r[1], 16) for r in common.load_csv('library.csv')}
    ranges = [(int(r[0], 16), int(r[1], 16)) for r in common.load_csv('library_ranges.csv')]
    starts = funcindex.starts()
    funcs = []
    for i, va in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else va + fn_size(va)
        size = len(common.read_va(va, end - va).rstrip(b'\xcc'))
        state = ('library' if va in lib or any(lo <= va < hi for lo, hi in ranges)
                 else 'matched' if va in matched else 'named' if va in named else 'unknown')
        funcs.append((va, size, state, matched.get(va) or named.get(va) or ''))
    progress.DATA.clear()
    progress.DATA.update(lverify.data_stats())
    return progress.stats(funcs)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--dir', type=Path, default=Path('build/full'))
    ap.add_argument('--out', type=Path, default=Path('build/target_audit'))
    args = ap.parse_args()
    args.out.parent.mkdir(parents=True, exist_ok=True)
    lverify.DLL, lverify.MAP = str(args.dir / 'match.dll'), str(args.dir / 'match.map')
    config = sorted((Path(common.REPO) / 'config').rglob('*.csv'))
    hashes = {str(path.relative_to(common.REPO)): digest(path) for path in config}
    tool_hashes = {str(Path('tools') / name): digest(Path(common.REPO) / 'tools' / name)
                   for name in ('classify_targets.py', 'retail_equivalence.py', 'lverify.py',
                                'common.py', 'funcindex.py', 'fnsize.py', 'progress.py')}
    inputs = {'exe': digest(common.EXE), 'dll': digest(lverify.DLL), 'map': digest(lverify.MAP),
              'config': hashes, 'tools': tool_hashes}
    if inputs['exe'] != common.EXE_SHA256:
        ap.error('retail EXE hash differs from the configured Beta 17.1 artifact')
    for name in ('LEARN_FWD', 'STAGE', 'LITERALS', 'ALL_PAIRS', 'PAIRS', 'LAST_PAIRS', 'LIT_STAGE'):
        getattr(lverify, name).clear()
    rejected = collections.defaultdict(dict)
    current = [None]
    original_target, original_compare = lverify.target_matches, lverify.compare

    def audit_target(image, va, names):
        result = original_target(image, va, names)
        targets, ambiguous = lverify.configured_targets(image, names or ())
        if not result and targets:
            key = (va, tuple(sorted(targets)), tuple(sorted(names or ())))
            rejected[current[0]][key] = {'actual': va, 'expected': sorted(targets),
                                        'names': sorted(names or ()), 'ambiguous': ambiguous}
        return result

    def audit_compare(name, *a, **kw):
        current[0] = name
        return original_compare(name, *a, **kw)

    lverify.target_matches, lverify.compare = audit_target, audit_compare
    try:
        with args.out.with_suffix('.log').open('w') as log, contextlib.redirect_stdout(log):
            results = lverify.verify_all()
    finally:
        lverify.target_matches, lverify.compare = original_target, original_compare
    _, _, retail = lverify.CTX['v']
    proof = RetailEquivalence(retail, indexed_spans(retail), lverify.inline_table_offset)
    rows = []
    classes = collections.Counter()
    functions = common.functions()
    for name, ok in results.items():
        if ok:
            continue
        targets = list(rejected[name].values())
        for target in targets:
            evidence = []
            for expected in target['expected']:
                equivalent = proof.equivalent(expected, target['actual'])
                pair = proof.pair(expected, target['actual'])
                reason = ('same address' if expected == target['actual'] else proof.reasons[pair])
                status = ('body-equivalent' if equivalent else 'unresolved' if any(
                    term in reason for term in ('extent', 'disassembly', 'fallthrough', 'relocation'))
                    else 'body-different')
                evidence.append({'expected': expected, 'status': status, 'reason': reason})
            target['evidence'] = evidence
            target['classification'] = ('identity-ambiguous' if target['ambiguous'] else
                'body-equivalent' if any(e['status'] == 'body-equivalent' for e in evidence) else
                'unresolved' if any(e['status'] == 'unresolved' for e in evidence) else 'body-different')
        kinds = {t['classification'] for t in targets}
        classification = next((k for k in ('body-different', 'identity-ambiguous', 'unresolved', 'body-equivalent')
                               if k in kinds), 'no-configured-target-evidence')
        classes[classification] += 1
        rows.append({'name': name, 'va': functions[name][0],
                     'target_evidence_class': classification, 'targets': targets})
    conflicts = common.mapping_conflicts()
    report = {'schema': 1, 'inputs': inputs, 'rule': 'strict configured identities; no ICF acceptance',
              'boundary_limit': 'existing retail index; conflicting extents and incomplete bodies rejected; '
                                'optimized entries absent from the index remain unresolved',
              'identity_limit': 'body equivalence does not establish unique original overload identity',
              'target_evidence_limit': 'per-caller buckets summarize rejected targets only; '
                                       'independent instruction/size/table differences remain in the log',
              'comparisons': len(results), 'match': sum(results.values()), 'diff': len(rows),
              'mapping_conflicts': conflicts, 'target_evidence_classes': dict(classes),
              'coverage': coverage(results), 'rows': rows,
              'proof_pairs': [{'a': a, 'b': b, 'equivalent': ok, 'reason': proof.reasons[(a, b)],
                               'dependencies': proof.dependencies.get((a, b), [])}
                              for (a, b), ok in sorted(proof.results.items())]}
    # Inputs must still be the artifacts actually examined, not a concurrent edit.
    final_config = sorted((Path(common.REPO) / 'config').rglob('*.csv'))
    if inputs['exe'] != digest(common.EXE) or inputs['dll'] != digest(lverify.DLL) or inputs['map'] != digest(lverify.MAP) or final_config != config or any(
            sha != digest(Path(common.REPO) / path) for path, sha in {**hashes, **tool_hashes}.items()):
        raise RuntimeError('build/config/tools changed during classification; report not published')
    args.out.with_suffix('.json').write_text(json.dumps(report, indent=2) + '\n')
    with args.out.with_suffix('.csv').open('w', newline='') as out:
        writer = csv.writer(out)
        writer.writerow(('name', 'va', 'target_evidence_class', 'actual', 'expected', 'target_names', 'evidence'))
        for row in rows:
            for target in row['targets'] or [{}]:
                writer.writerow((row['name'], hex(row['va']), row['target_evidence_class'],
                                 hex(target['actual']) if target else '',
                                 ';'.join(hex(va) for va in target.get('expected', ())),
                                 ';'.join(target.get('names', ())),
                                 json.dumps(target.get('evidence', ()), separators=(',', ':'))))
    print('%d/%d MATCH; %d DIFF' % (report['match'], report['comparisons'], report['diff']))
    print(json.dumps(report['target_evidence_classes'], sort_keys=True))
    cov = report['coverage']
    print('Strict game coverage: %d/%d functions; %d/%d bytes (%.6f%%)' % (
        cov['funcs_matched'], cov['funcs'], cov['code_matched'], cov['code_bytes'],
        progress.pct(cov['code_matched'], cov['code_bytes'])))
    print('Evidence: %s.{json,csv,log}' % args.out)
    return 0 if not rows and not conflicts else 1


if __name__ == '__main__':
    raise SystemExit(main())
