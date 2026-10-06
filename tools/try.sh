#!/bin/sh
# Quick experiment: compile file(s) the real way (/GL + LTCG link, own scratch dir, safe to run
# in parallel) and compare chosen functions against COGMIND.exe.
#   tools/try.sh file.cpp [more.cpp ...] -- 'Name=0xVA' ...   (Name = Class::member or mangled)
REPO=$(cd "$(dirname "$0")/.." && pwd); cd "$REPO"
srcs=""; while [ $# -gt 0 ] && [ "$1" != "--" ]; do srcs="$srcs $1"; shift; done; shift
dir=$(mktemp -d "$REPO/build/try.XXXXXX")
trap 'rm -rf "$dir"' EXIT
.venv/bin/python tools/ltcg.py "$dir" $srcs || exit 1
exec .venv/bin/python tools/trycmp.py "$dir" "$@"
