"""Require every new mapping to exist and match in the fresh combined image."""
import csv
import json
import pathlib
import sys
import shutil
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import common
import lverify
import progress

folder = ROOT / (sys.argv[1] if len(sys.argv) > 1 else 'build/match_push/native')
lverify.DLL = str(folder / 'match.dll')
lverify.MAP = str(folder / 'match.map')
snapshot = tempfile.TemporaryDirectory(prefix='cogmind-match-config-')
shutil.copytree(ROOT / 'config', pathlib.Path(snapshot.name) / 'config')
common.REPO = snapshot.name
results = lverify.verify_all(quiet=True)
with (ROOT / 'config/mapping.d/match_push.csv').open() as stream:
    mappings = list(csv.reader(stream))
missing = [row[0] for row in mappings if row[0] not in results]
failed = [row[0] for row in mappings if results.get(row[0]) is False]
if missing or failed:
    raise SystemExit('Missing: %s; differing: %s' % (missing, failed))
assert len(mappings) == len({int(row[1], 16) for row in mappings})
# Reuse the completed comparison results when collecting the progress treemap.
verify_all = lverify.verify_all
lverify.verify_all = lambda *args, **kwargs: results
functions = progress.collect()
stats = progress.stats(functions)
stats['date'] = '2026-10-04'
report = {
    'new_unique_functions': len(mappings),
    'new_bytes': sum(int(row[2], 16) for row in mappings),
    'new_matches': len(mappings),
    'combined_matches': sum(results.values()),
    'combined_comparisons': len(results),
    'combined_differences': [name for name, ok in results.items() if not ok],
    'progress': stats,
    'code_percent': 100 * stats['code_matched'] / stats['code_bytes'],
}
if len(sys.argv) > 2:
    baseline = ROOT / sys.argv[2]
    lverify.DLL = str(baseline / 'match.dll')
    lverify.MAP = str(baseline / 'match.map')
    lverify.LEARN_FWD.clear()
    lverify.verify_all = verify_all
    lverify.DLL = str(baseline / 'match.dll')
    lverify.MAP = str(baseline / 'match.map')
    baseline_results = lverify.verify_all(quiet=True)
    baseline_bad = {name for name, ok in baseline_results.items() if not ok}
    current_bad = {name for name, ok in results.items() if not ok}
    report['baseline_matches'] = sum(baseline_results.values())
    report['baseline_comparisons'] = len(baseline_results)
    report['baseline_differences'] = sorted(baseline_bad)
    report['introduced_differences'] = sorted(current_bad - baseline_bad)
    if report['introduced_differences']:
        raise SystemExit('Introduced differences: %s' % report['introduced_differences'])
output = ROOT / 'build/match_push'
(output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
(output / 'progress.json').write_text(json.dumps(stats, indent=2) + '\n')
(output / 'progress.html').write_text(progress.treemap(functions, stats))
(output / 'progress.svg').write_text(progress.badge(stats))
print(json.dumps(report, indent=2))
