# Native Windows executable reconstruction

The matching project is a collection of partial C++ translation units, not a
standalone source application. Its normal output is `match.dll`, linked with
verification-only dependency stubs and `/NOENTRY`. Do not try to run that DLL.

`tools/fullbuild_windows.py` compiles all matching sources with the kit's actual
VS2010 SP1 compiler on Windows. `tools/rebuild_windows.py` then installs compiler
output into the original address layout. Every installed function must pass the
existing strict target-identity verifier, and the relocated body must be exactly
equal to the corresponding retail bytes. There is no runtime stub substitution.

This produces an **address-preserving executable reconstruction**, not a fully
independent source link. Retail supplies PE headers/imports, CRT and third-party
library code, global data/initializers not covered by verified mapping rows,
and owned game assets. The resulting executable can have the same SHA256 as
retail: exact compiled code is placed at its original addresses. The per-function
manifest records compiler-image addresses and body hashes so this claim is
auditable. Full game coverage is required by default; `--allow-partial` explicitly
permits a development build with original game functions retained.

## Prerequisites

- Windows x64 with the x86 VC100 runtime (normally already installed by games).
- Python 3.11 or later, `pefile==2024.8.26`, `capstone==5.0.9`.
- Private kit under `cogmind-kit/`, with the compiler/SDK MSIs and CAB files.
- Your complete **Beta 17.1** installation, including runtime DLLs, `data/`,
  `rex/`, and `cogmind.x`. Its executable must have SHA256
  `6c96192b9b7a81956416abdb11766933bca21fce8c2c0d57b97b172e13cd8184`.
- At least 12 GiB free physical memory before a full build.

Keep the kit and full installation out of Git. `build/` is already ignored;
local installation directories can be added to `.git/info/exclude`.

## Build and play

Run from the repository root in PowerShell:

```powershell
python -m venv .venv
.venv\Scripts\python -m pip install --index-url https://pypi.org/simple capstone==5.0.9 pefile==2024.8.26
.venv\Scripts\python tools\fullbuild_windows.py --setup --jobs 4
.venv\Scripts\python tools\rebuild_windows.py
.venv\Scripts\python tools\play_windows.py --game 'COGMIND (Beta 17.1)'
```

The setup performs administrative extraction into `build/toolchain/`; it does
not install or switch your system's compiler. `COGMIND_VC` and `COGMIND_SDK` can
point to existing compatible VC/SDK directories. The Windows driver preserves
link order, normalizes Windows path separators, includes `include/compat`, uses
the same `build/.fullbuild.lock` as the existing full-build wrapper, and logs
each compile/link operation. It never invokes the macOS Wine scripts.

The driver creates two directory junctions outside the checkout at
`C:\_\_RL\COGMIND\_cogmind` and
`C:\_\_RL\Protobuffer\protobuf-3.5.1`. These preserve retail's diagnostic
`__FILE__` literals; compiling through the workspace's ordinary path causes 201
strict differences. Existing paths must refer to this checkout or the driver
refuses to proceed. The junctions remain for subsequent builds. No source files
or diagnostic strings are rewritten.

The playable copy is `build/windows/game/COGMIND-rebuilt.exe`. Launch it from
that directory so its relative assets resolve. The supplied installation is
copied and preserved. An existing stage is refused to avoid overwriting saves;
use a new `--stage` when repeating a run. `--stage-only` prepares without launch.
The copied installation includes its existing player profile and saves. The
playable launcher requires complete strict game coverage even if a development
executable was produced with `--allow-partial`.

## Evidence and checks

- `build/full_windows/build.json`: compiler, flags and source hashes.
- `build/full_windows/*.log`: compile/link diagnostics.
- `build/windows/strict-verify.log`: every strict mapping result, including
  surplus alias rows that can DIFF despite complete game-function coverage.
- `build/windows/COGMIND-rebuilt.json`: input/config hashes, complete coverage,
  installed functions/body hashes, retained scaffold statement, output hash.
- `build/windows/game/play-session.json`: actual process executable, hash, cwd.

```powershell
.venv\Scripts\python tests\check_windows_relocation.py
.venv\Scripts\python tests\check_target_identity.py
.venv\Scripts\python tests\check_retail_equivalence.py
```

The strict verifier has not been relaxed. Complete game-function and code-byte
coverage is a different condition from every configured alias row matching.
Optimized library functions absent from the index and runtime/global data are
not claimed to be independently reconstructed by this process.

See `WINDOWS_HARNESS.md` for headless SDL/StatMind operation and differential
gameplay checks without desktop input.

The completed native build, desktop save/resume check, and bounded retail versus
rebuild replay are recorded in [WINDOWS_PROOF.md](WINDOWS_PROOF.md).
