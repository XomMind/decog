#!/usr/bin/env python3
"""Conservative bulk protobuf discovery; never installs config mappings.

protobuf_discover.py BUILD --out candidates.csv [--lo VA --hi VA]
protobuf_discover.py BUILD --verify candidates.csv [--lo VA --hi VA]

CSV rows are full linker symbol, retail VA, byte size. The adjacent
CSV.report.json records all trials, ambiguities, exclusions and operand proof.
Verification mode rechecks the complete CSV in one shared relocation context
and writes CSV.verification.json. No funcindex cache or build/full is changed.
"""
import argparse
import collections
import contextlib
import csv
import hashlib
import io
import json
import os
from pathlib import Path
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import capstone
import common
import lverify
import pefile


STATE_DICTS = ('LEARN_FWD', 'STAGE')
STATE_SETS = ('LITERALS', 'ALL_PAIRS')
STATE_LISTS = ('PAIRS', 'LAST_PAIRS', 'LIT_STAGE')


class StableNames(set):
    """Keep lverify.sym_key's equal-length alias tie breaks deterministic."""
    def __iter__(self):
        return iter(sorted(set.__iter__(self)))


def snapshot():
    return {n: getattr(lverify, n).copy() if n in STATE_DICTS + STATE_SETS
            else list(getattr(lverify, n))
            for n in STATE_DICTS + STATE_SETS + STATE_LISTS}


def restore(state):
    for name, value in state.items():
        obj = getattr(lverify, name)
        obj.clear()
        if isinstance(obj, list):
            obj.extend(value)
        else:
            obj.update(value)


def reset():
    for name in STATE_DICTS + STATE_SETS + STATE_LISTS:
        getattr(lverify, name).clear()


def sections(image, executable):
    return [(image.base + s.VirtualAddress,
             image.base + s.VirtualAddress + min(s.Misc_VirtualSize, s.SizeOfRawData),
             s.get_data()[:min(s.Misc_VirtualSize, s.SizeOfRawData)])
            for s in image.pe.sections
            if bool(s.Characteristics & 0x20000000) == executable]


def decoder(detail=False):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = detail
    return md


def span_shape(image, va, size, md):
    """Require full disassembly, or lverify's explicitly validated inline tables."""
    insns = list(md.disasm(image.read(va, size), va))
    tables = lverify.inline_table_offset(insns, va, size)
    end = size if tables is None else tables[0][0]
    insns = [i for i in insns if i.address < va + end]
    if not insns or insns[-1].address + insns[-1].size != va + end:
        return None
    # Padding, undecoded tails and fall-through fragments are not functions.
    if tables is None and insns[-1].mnemonic not in ('ret', 'retf', 'jmp', 'ud2', 'int3'):
        return None
    return (size, tuple((i.mnemonic, i.size) for i in insns),
            tuple(tables or ()))


def retail_spans(image, lo, hi, mapped):
    """Index optimized starts without relying on frame-pointer funcindex.

    Boundaries come from direct calls, non-code pointers (including vtables/EH),
    mapped functions and aligned code after int3 padding. Direct jump targets
    are candidates only when they also have independent boundary evidence:
    treating every loop target as a function would split most optimized bodies.
    """
    evidence = collections.defaultdict(set)
    jumps = set()
    md = decoder()
    md.skipdata = True
    for start, end, data in sections(image, True):
        a, b = max(start, lo), min(end, hi)
        if a >= b:
            continue
        evidence[a].add('range_boundary')
        chunk = data[a - start:b - start]
        for i in range(1, len(chunk)):
            va = a + i
            if va % 16 == 0 and chunk[i - 1] == 0xcc and chunk[i] != 0xcc:
                evidence[va].add('aligned_after_int3')
            if chunk[i - 1:i + 3] == b'\xcc\x55\x8b\xec':
                evidence[va].add('frame_prologue_after_int3')
        for ins in md.disasm(chunk, a):
            if ins.mnemonic not in ('call', 'jmp'):
                continue
            # Direct relative operands only; no disassembler-detail overhead here.
            raw = bytes(ins.bytes)
            target = None
            if len(raw) == 5 and raw[0] in (0xe8, 0xe9):
                target = ins.address + 5 + struct.unpack('<i', raw[1:])[0]
            elif len(raw) == 2 and raw[0] == 0xeb:
                target = ins.address + 2 + struct.unpack('<b', raw[1:])[0]
            if target is not None and lo <= target < hi:
                if ins.mnemonic == 'call':
                    evidence[target].add('direct_call')
                else:
                    jumps.add(target)
    # Data pointers include vtable slots and EH handler addresses. They are
    # boundary hypotheses, not an RTTI proof; exact comparison remains required.
    for start, end, data in sections(image, False):
        for offset in range(0, len(data) - 3, 4):
            target = struct.unpack_from('<I', data, offset)[0]
            if lo <= target < hi:
                evidence[target].add('noncode_pointer')
    for va in mapped:
        if lo <= va < hi:
            evidence[va].add('existing_mapping')
    for va in jumps:
        if va in evidence:
            evidence[va].add('direct_jump')
    starts = sorted(evidence)
    spans = {}
    for va, nxt in zip(starts, starts[1:] + [hi]):
        code = image.read(va, nxt - va).rstrip(b'\xcc')
        if code:
            spans[va] = (len(code), sorted(evidence[va]))
    return spans, {'starts': len(starts), 'direct_jump_targets': len(jumps),
                   'jump_only_targets_excluded': len(jumps - evidence.keys()),
                   'start_evidence': dict(collections.Counter(
                       e for values in evidence.values() for e in values))}


def source_spans(image):
    names = collections.defaultdict(set)
    for name, va in lverify.MAP_ALL:
        names[va].add(name)
    repeated = collections.defaultdict(set)
    for va, aliases in names.items():
        for name in aliases:
            repeated[name].add(va)
    mapped_names = set(common.functions())
    out, skipped = [], collections.Counter()
    md = decoder(True)
    for lo, hi, _ in sections(image, True):
        starts = sorted(va for va in names if lo <= va < hi)
        for va, nxt in zip(starts, starts[1:] + [hi]):
            aliases = sorted(names[va])
            usable = [n for n in aliases if len(repeated[n]) == 1
                      and n not in mapped_names and common.demangle(n) not in mapped_names
                      and not n.startswith(('??_C', '__real@', '__xmm@'))]
            if not usable:
                skipped['mapped_or_duplicate_or_constant_name'] += 1
                continue
            if lverify.is_stub(image, va) or any(a == va for a, _ in lverify.STUBS):
                skipped['stub'] += 1
                continue
            name = min(usable, key=lambda n: (not n.startswith('?'), n))
            size = len(image.read(va, nxt - va).rstrip(b'\xcc'))
            if size < 8:
                skipped['short_body_under_8_bytes'] += 1
                continue
            shape = span_shape(image, va, size, md)
            if shape is None:
                skipped['unproven_extent_or_decode'] += 1
                continue
            out.append({'name': name, 'aliases': aliases, 'ours_va': va,
                        'size': size, 'shape': shape})
    return out, dict(skipped), repeated


def trial(symbol, theirs, tva, ours):
    """Always roll back every verifier global, including successful trials."""
    saved = snapshot()
    try:
        key = lverify.sym_key(ours.resolve(symbol['ours_va']))
        prior = lverify.LEARN_FWD.get(key)
        if prior is not None and prior != tva:
            return None
        lverify.LEARN_FWD[key] = tva
        with contextlib.redirect_stdout(io.StringIO()):
            ok = lverify.compare(symbol['name'], theirs, tva, ours,
                                 symbol['ours_va'], symbol['size'], False)
        if not ok:
            return None
        pairs = set(lverify.ALL_PAIRS)
        pairs.add((symbol['ours_va'], tva))
        forward = {}
        for ova, eva in pairs:
            if ova in forward and forward[ova] != eva:
                return None
            forward[ova] = eva
        return {'retail_va': tva, 'size': symbol['size'],
                'learned': dict(lverify.LEARN_FWD), 'pairs': sorted(pairs),
                'verified_literals': sorted(lverify.LITERALS)}
    finally:
        restore(saved)


def compatible_set(candidates):
    """Exclude EVERY participant in a conflict; never choose an arbitrary winner."""
    constraints = collections.defaultdict(lambda: collections.defaultdict(set))
    for index, (symbol, hit) in enumerate(candidates):
        for key, value in hit['learned'].items():
            constraints[('symbol', key)][value].add(index)
        for ova, eva in hit['pairs']:
            constraints[('address', ova)][eva].add(index)
        # ICF is supported for operand targets, but CSV discoveries must have
        # a unique source body per retail address (no arbitrary alias winner).
        constraints[('retail_body', hit['retail_va'])][symbol['ours_va']].add(index)
    rejected, conflicts = set(), []
    for (kind, key), values in sorted(constraints.items(), key=lambda kv: str(kv[0])):
        if len(values) > 1:
            involved = sorted(set().union(*values.values()))
            rejected.update(involved)
            conflicts.append({'kind': kind, 'key': key,
                              'values': [{'value': v, 'candidates': sorted(ids)}
                                         for v, ids in sorted(values.items())],
                              'names': [candidates[i][0]['name'] for i in involved]})
    return [c for i, c in enumerate(candidates) if i not in rejected], conflicts


def verify_together(candidates, theirs, ours):
    reset()
    learned = {}
    for _, hit in candidates:
        for key, value in hit['learned'].items():
            if key in learned and learned[key] != value:
                raise ValueError('inconsistent accepted learned set')
            learned[key] = value
    lverify.LEARN_FWD.update(learned)
    for symbol, hit in candidates:
        # Trials roll back, then only the accepted shared context is committed.
        checked = trial(symbol, theirs, hit['retail_va'], ours)
        if checked is None:
            reset()
            return False
        lverify.LEARN_FWD.update(checked['learned'])
        lverify.ALL_PAIRS.update(map(tuple, checked['pairs']))
        lverify.LITERALS.update(map(tuple, checked['verified_literals']))
    return True


def dump(path, report):
    Path(path).parent.mkdir(parents=True, exist_ok=True)
    with open(path, 'w', encoding='utf-8') as f:
        json.dump(report, f, indent=2, sort_keys=True)
        f.write('\n')


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('builddir', type=Path)
    ap.add_argument('--out', type=Path)
    ap.add_argument('--verify', type=Path, metavar='CSV')
    ap.add_argument('--lo', type=lambda x: int(x, 0), default=0xa044d0)
    ap.add_argument('--hi', type=lambda x: int(x, 0), default=0xaa0000)
    args = ap.parse_args(argv)
    if not args.verify and not args.out:
        ap.error('--out is required for discovery')
    full = (Path(common.REPO) / 'build' / 'full').resolve()
    destination = args.verify if args.verify else args.out
    if destination.resolve() == full or full in destination.resolve().parents:
        ap.error('discovery and verification reports must not overwrite build/full')
    ranges = [(int(r[0], 0), int(r[1], 0)) for r in common.load_csv('library_ranges.csv')
              if len(r) >= 3 and r[2].startswith('protobuf')]
    if not any(lo <= args.lo < args.hi <= hi for lo, hi in ranges):
        ap.error('search bounds must lie within the configured protobuf library range')
    lverify.DLL = str(args.builddir / 'match.dll')
    lverify.MAP = str(args.builddir / 'match.map')
    mp = lverify.load_map()
    ours = lverify.Image(pefile.PE(lverify.DLL), lverify.map_names(mp))
    # Preserve ALL aliases at every static/public address, not only load_map's
    # one preferred address per name. Duplicate names remain conservative keys.
    for name, va in lverify.MAP_ALL:
        ours.names.setdefault(va, set()).update((name, common.demangle(name)))
    ours.names = {va: StableNames(names) for va, names in ours.names.items()}
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names(), common.symbols())
    mapped = {va for va, _ in common.functions().values()}
    spans, index_info = retail_spans(theirs, args.lo, args.hi, mapped)
    symbols, skipped, repeated = source_spans(ours)
    report = {'schema': 1, 'builddir': str(args.builddir),
              'range': [args.lo, args.hi], 'index': index_info,
              'source_symbols': len(symbols), 'source_skipped': skipped,
              'duplicate_linker_names': {n: sorted(v) for n, v in sorted(repeated.items()) if len(v) > 1},
              'inputs_sha256': {name: hashlib.sha256(Path(path).read_bytes()).hexdigest()
                                for name, path in [('dll', lverify.DLL), ('map', lverify.MAP), ('exe', common.EXE)]},
              'limitations': [
                  'Conservative boundary hypotheses can split bodies at EH/data pointers or miss unreferenced unaligned optimized starts.',
                  'Direct calls are scanned in the configured range, not across all game code; jump-only internal labels are not starts.',
                  'Source extents end at next linker code symbol minus int3 padding; incomplete decoding, fall-through tails and bodies under 8 bytes are excluded.',
                  'No length cap: complete symbol spans, including recognized inline switch tables, are compared.',
                  'Duplicate linker names cannot identify individual static copies in CSV; only unique aliases can be emitted; verifier symbol-key collisions may conservatively reject copies.',
                  'Proof uses existing lverify relocation semantics, including learned unnamed targets; operands are consistent but target bodies/data are not recursively proven.',
                  'Unique means among indexed retail candidates, not an exhaustive proof over all possible byte offsets.',
                  'All conflicting unique candidates are excluded, not greedily assigned; ambiguity is never resolved by elimination.']}
    reset()
    if args.verify:
        lookup = {n: s for s in symbols for n in s['aliases'] if len(repeated[n]) == 1}
        candidates, errors = [], []
        with open(args.verify, newline='', encoding='utf-8') as f:
            for line, row in enumerate(csv.reader(f), 1):
                if not row or row[0].startswith('#'):
                    continue
                try:
                    if len(row) != 3:
                        raise ValueError('expected name,VA,size')
                    name, tva, size = row[0], int(row[1], 0), int(row[2], 0)
                    symbol = lookup.get(name)
                    if symbol is None or size != symbol['size']:
                        raise ValueError('unknown/duplicate symbol or wrong complete source size')
                    if tva in mapped or tva not in spans or spans[tva][0] != size:
                        raise ValueError('mapped address or unproven retail extent/range')
                    symbol = dict(symbol, name=name)
                    hit = trial(symbol, theirs, tva, ours)
                    if hit is None:
                        raise ValueError('exact relocation comparison failed')
                    candidates.append((symbol, hit))
                except ValueError as e:
                    errors.append({'line': line, 'error': str(e)})
        accepted, conflicts = compatible_set(candidates)
        good = not errors and not conflicts and verify_together(accepted, theirs, ours)
        report.update(mode='verify', csv=str(args.verify), verified=good,
                      rows=len(candidates), errors=errors, conflicts=conflicts)
        dump(str(args.verify) + '.verification.json', report)
        print('verified=%s rows=%d errors=%d conflicts=%d' %
              (good, len(candidates), len(errors), len(conflicts)))
        return 0 if good else 1
    md = decoder(True)
    index = collections.defaultdict(list)
    rejected_spans = 0
    for va, (size, evidence) in sorted(spans.items()):
        if va in mapped or size < 8:
            continue
        key = span_shape(theirs, va, size, md)
        if key is None:
            rejected_spans += 1
        else:
            index[key].append(va)
    unique, records = [], []
    trial_count = 0
    for symbol in symbols:
        cands = index.get(symbol['shape'], ())
        hits = []
        for tva in cands:
            trial_count += 1
            hit = trial(symbol, theirs, tva, ours)
            if hit is not None:
                hit['boundary_evidence'] = spans[tva][1]
                hits.append(hit)
        records.append({k: v for k, v in symbol.items() if k != 'shape'} |
                       {'shape_candidates': len(cands), 'exact_matches': len(hits), 'hits': hits})
        if len(hits) == 1:
            unique.append((symbol, hits[0]))
    accepted, conflicts = compatible_set(unique)
    if not verify_together(accepted, theirs, ours):
        raise RuntimeError('accepted set failed shared-context verification; no CSV written')
    accepted_names = {s['name'] for s, _ in accepted}
    for record in records:
        record['status'] = ('accepted' if record['name'] in accepted_names else
                            'conflict' if record['exact_matches'] == 1 else
                            'ambiguous' if record['exact_matches'] > 1 else 'unmatched')
    report.update(mode='discover', csv=str(args.out), symbols=records,
                  conflicts=conflicts, accepted_shared_verification=True,
                  committed_learned=dict(lverify.LEARN_FWD),
                  committed_pairs=sorted(lverify.ALL_PAIRS),
                  counts={'shape_index_keys': len(index),
                          'indexed_retail_bodies': sum(map(len, index.values())),
                          'retail_unproven_extents': rejected_spans,
                          'exact_trials': trial_count, 'unique_before_conflicts': len(unique),
                          'accepted': len(accepted), 'conflict_rejected': len(unique) - len(accepted),
                          'ambiguous_symbols': sum(r['exact_matches'] > 1 for r in records),
                          'ambiguous_exact_hits': sum(r['exact_matches'] for r in records if r['exact_matches'] > 1),
                          'unmatched_symbols': sum(r['exact_matches'] == 0 for r in records)})
    args.out.parent.mkdir(parents=True, exist_ok=True)
    with open(args.out, 'w', newline='', encoding='utf-8') as f:
        writer = csv.writer(f, lineterminator='\n')
        for symbol, hit in sorted(accepted, key=lambda c: (c[1]['retail_va'], c[0]['name'])):
            writer.writerow((symbol['name'], hex(hit['retail_va']), hex(hit['size'])))
    dump(str(args.out) + '.report.json', report)
    print(json.dumps(report['counts'], sort_keys=True))
    return 0


if __name__ == '__main__':
    sys.exit(main())
