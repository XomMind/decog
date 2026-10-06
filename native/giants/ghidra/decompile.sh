#!/bin/sh
# Decompile exe functions with Ghidra headless (project prepared by setup: see docs/giants/METHOD.md).
#   native/giants/ghidra/decompile.sh <project dir> <outdir> 0xVA [0xVA ...]
# One Ghidra instance per project dir (projects are locked); clone the project dir to run several queues.
REPO=$(cd "$(dirname "$0")/../../.." && pwd)
G=$REPO/3rdparty/ghidra/ghidra_12.1.4_PUBLIC
proj=$1; out=$2; shift 2
GHIDRA_MAXMEM=${GHIDRA_MAXMEM:-6G} exec "$G/support/analyzeHeadless" "$proj" cogmind -process COGMIND.exe -noanalysis -readOnly \
	-scriptPath "$REPO/native/giants/ghidra" -postScript G1Decompile.java "$out" "$@"
