#!/bin/sh
# Run at utility QoS + nice 10 so builds yield to the user's apps (-b background starved builds: 4 min -> 70+ min).
[ -n "$CM_BG" ] || exec env CM_BG=1 taskpolicy -c utility nice -n 10 "$0" "$@"
# Quick experiment: compile file(s) the real way (/GL + LTCG link, own scratch dir, safe to run
# in parallel) and compare chosen functions against COGMIND.exe.
#   tools/try.sh file.cpp [more.cpp ...] -- 'Name=0xVA' ...   (Name = Class::member or mangled)
REPO=$(cd "$(dirname "$0")/.." && pwd); cd "$REPO"
export JOBS=${JOBS:-2}
srcs=""; while [ $# -gt 0 ] && [ "$1" != "--" ]; do srcs="$srcs $1"; shift; done; shift
dir=$(mktemp -d "$REPO/build/try.XXXXXX")
trap 'rm -rf "$dir"' EXIT
.venv/bin/python tools/ltcg.py "$dir" $srcs || exit 1
exec .venv/bin/python tools/trycmp.py "$dir" "$@"
