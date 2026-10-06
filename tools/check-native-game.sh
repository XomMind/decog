#!/bin/sh
set -eu
REPO=$(cd "$(dirname "$0")/.." && pwd)
dir=$(mktemp -d "${TMPDIR:-/tmp}/cogmind-native-game.XXXXXX")
trap 'rm -rf "$dir"' EXIT HUP INT TERM
"${CXX:-c++}" -std=c++11 -Wall -Wextra -Werror -fsanitize=address,undefined \
    "$REPO/tests/native_game.cpp" "$REPO/src/game/penetrationrollpool.cpp" \
    "$REPO/src/game/luigiai.cpp" "$REPO/src/game/seedcodec.cpp" \
    "$REPO/src/util/stringutil.cpp" "$REPO/src/lib/mtrand.cpp" \
    "$REPO/src/util/mathutil.cpp" -o "$dir/check"
"$dir/check"
