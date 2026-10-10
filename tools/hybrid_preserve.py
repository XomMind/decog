"""Verify that a private hybrid preserves quarantined retail instruction bytes.

This establishes code preservation, not gameplay/input-state equivalence.
Usage: .venv/bin/python tools/hybrid_preserve.py <hybrid.exe> [report.json]
"""
import hashlib
import json
from pathlib import Path
import sys
import pefile
import common
from hybrid_float import retail_quarantine


def verify(path):
    retail_path = Path(common.REPO) / 'resources/COGMIND.exe'
    retail = pefile.PE(str(retail_path), fast_load=True)
    hybrid = pefile.PE(str(path), fast_load=True)
    if retail.OPTIONAL_HEADER.ImageBase != hybrid.OPTIONAL_HEADER.ImageBase:
        raise ValueError('Hybrid image base differs from retail')
    base = retail.OPTIONAL_HEADER.ImageBase
    graph = json.loads((Path(common.REPO) / 'build/callgraph.json').read_text())
    sizes = {int(key, 16): value for key, value in graph['sizes'].items()}
    protected, policy = retail_quarantine()
    checked = 0
    mismatches = []
    for address in sorted(protected & sizes.keys()):
        size = sizes[address]
        expected = retail.get_data(address - base, size)
        actual = hybrid.get_data(address - base, size)
        if len(expected) != size or len(actual) != size or expected != actual:
            mismatches.append({'address': '%#x' % address, 'size': size})
        checked += 1
    return {'retail_sha256': hashlib.file_digest(retail_path.open('rb'), 'sha256').hexdigest(),
            'hybrid_sha256': hashlib.file_digest(Path(path).open('rb'), 'sha256').hexdigest(),
            'quarantine': policy, 'protected_functions_checked': checked,
            'changed_protected_functions': mismatches,
            'scope': 'Instruction-byte preservation only; not gameplay equivalence.'}


if __name__ == '__main__':
    if len(sys.argv) not in (2, 3):
        raise SystemExit(__doc__)
    report = verify(sys.argv[1])
    if len(sys.argv) == 3:
        Path(sys.argv[2]).write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))
    raise SystemExit(1 if report['changed_protected_functions'] else 0)
