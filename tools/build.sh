#!/bin/sh
# Build every src/**/*.cpp + harness/*.cpp the way Cogmind was built (VS2010 SP1, /Od + /GL,
# /LTCG link) into build/full/match.dll, verify against COGMIND.exe, refresh progress report.
#   tools/build.sh [name-filter ...]
set -e
REPO=$(cd "$(dirname "$0")/.." && pwd); cd "$REPO"
.venv/bin/python tools/ltcg.py build/full $(.venv/bin/python tools/sources.py)
.venv/bin/python tools/lverify.py "$@" || status=$?
.venv/bin/python tools/progress.py >/dev/null && echo "progress: $(python3 -c 'import json;s=json.load(open("build/progress.json"));print("%.3f%% code, %d/%d functions" % (100*s["code_matched"]/s["code_bytes"], s["funcs_matched"], s["funcs"]))')"
exit ${status:-0}
