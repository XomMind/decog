#!/bin/sh
[ -n "$CM_BG" ] || exec env CM_BG=1 taskpolicy -c utility nice -n 10 "$0" "$@"
# Run a VS2010 SP1 tool (cl.exe, link.exe, dumpbin.exe...) under native macOS wine (Rosetta).
# One-time setup: tools/setup-wine.sh. The repo appears where Kyzrati's tree lived,
# C:\_\_RL\COGMIND\_cogmind (__FILE__ strings embedded in the exe must match), and vendored
# protobuf at C:\_\_RL\Protobuffer\protobuf-3.5.1. cwd is preserved relative to the repo.
REPO=$(cd "$(dirname "$0")/.." && pwd)
H=${COGMIND_WINE_HOME:-$HOME/.cogmind-wine}
rel=$(python3 -c 'import os,sys;print(os.path.relpath(os.getcwd(),sys.argv[1]))' "$REPO")
case "$rel" in ..*) rel=. ;; esac
export DYLD_FALLBACK_LIBRARY_PATH="$H/engine/frameworks:$H/engine/wswine.bundle/lib"
export WINEPREFIX="$H/prefix" WINEDEBUG=-all
export COGMIND_MSVC="Z:$(printf %s "$H/msvc" | tr / '\\')"
export COGMIND_CWD="C:\\_\\_RL\\COGMIND\\_cogmind\\$(printf %s "$rel" | tr / '\\')"
exec "$H/engine/wswine.bundle/bin/wine" 'C:\_\_RL\COGMIND\_cogmind\tools\cogmindrun.bat' "$@"
