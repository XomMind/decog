#!/bin/sh
# Check reconstructed RNG behavior using the native C++ compiler.
set -eu
REPO=$(cd "$(dirname "$0")/.." && pwd)
dir=$(mktemp -d "${TMPDIR:-/tmp}/cogmind-native-rng.XXXXXX")
trap 'rm -rf "$dir"' EXIT HUP INT TERM
"${CXX:-c++}" -std=c++11 -Wall -Wextra -Werror "$REPO/tests/native_rng.cpp" \
    "$REPO/tests/native_rng_peer.cpp" "$REPO/src/lib/mtrand.cpp" "$REPO/src/util/mathutil.cpp" -o "$dir/check"
"$dir/check"
