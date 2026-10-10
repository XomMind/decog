# Native Windows gameplay harness

The repository's `harness/*.cpp` files are link-time matching probes. The
interactive gameplay harness is the separate XomMind SDL / StatMind / cogbench
stack. `tools/windows_harness.py` prepares external checkouts for Windows without
committing them or modifying an owned game installation.

The reconstructed executable described in [WINDOWS.md](WINDOWS.md) retains the
retail PE/CRT/vendor-library/global-data scaffold and installs compiler-generated,
strictly verified matching game-function bodies at their original addresses.
It is not a standalone source-only rebuild. The gameplay harness compares that
specific reconstruction with the retail executable, records executable/DLL hashes,
and does not establish provenance for code retained from the scaffold.

Validated upstream revisions:

| Repository | Revision |
| --- | --- |
| SDL-1.2 | `d343471907d0f1ee2f38ff217ff7e9ba659f70ba` |
| StatMind | `ea65dc962331b94dc119b982f4d73e923991ef31` |
| cogbench | `1de79223b56245b577b275f23d928db493b78076` |

Prerequisites: Windows x64, Python 3, Rust's native MSVC toolchain, Visual Studio
2022 Build Tools with desktop C++ and Windows SDK, and a complete owned Beta 17.1
game installation. The kit contains only the executable, so it cannot supply the
game data. The supported retail executable SHA256 is
`6c96192b9b7a81956416abdb11766933bca21fce8c2c0d57b97b172e13cd8184`.

Run from the decog root in PowerShell:

```powershell
git clone https://github.com/XomMind/SDL-1.2 scratch/harness/SDL-1.2
git clone https://github.com/XomMind/StatMind scratch/harness/StatMind
git clone https://github.com/XomMind/cogbench scratch/harness/cogbench
git -C scratch/harness/SDL-1.2 checkout d343471907d0f1ee2f38ff217ff7e9ba659f70ba
git -C scratch/harness/StatMind checkout ea65dc962331b94dc119b982f4d73e923991ef31
git -C scratch/harness/cogbench checkout 1de79223b56245b577b275f23d928db493b78076
python tools/windows_harness.py --statmind scratch/harness/StatMind --cogbench scratch/harness/cogbench --sdl scratch/harness/SDL-1.2 --build-statmind --build-sdl build/windows-harness
```

The preparation is repeatable and fails if its upstream patch anchors change.
It changes the explicitly supplied external checkouts. SDL uses WinDIB / waveOut,
avoiding the obsolete DirectX SDK and the upstream Steam-install postbuild copy.
The shim's GCC export attributes and thiscall assembly are converted to MSVC.
The dummy backend gets a virtual 1920x1080 desktop, necessary for Cogmind's font
fitting. Override `STATMIND_DUMMY_WIDTH` / `STATMIND_DUMMY_HEIGHT` to change it.
No global AVX2 compiler requirement is imposed; the upstream optimized routines
retain their CPU feature dispatch.

StatMind uses `OpenProcess`, `ReadProcessMemory`, `WriteProcessMemory`, and
`VirtualQueryEx`. Only committed accessible memory in the 32-bit address space
is scanned. Writes require already-writable memory; page protections are not
changed. Run it under the same Windows account as the game. `--pid` selects a
particular instance rather than discovering a process by its name.

```powershell
python tools/cogmind_harness_windows.py --game 'COGMIND (Beta 17.1)' --stage build/windows/harness-retail --profile build/windows/harness-retail-profile --sdl build/windows-harness/SDL.dll --headless
$env:STATMIND_PID = '<pid printed by launcher>'
python scratch/harness/cogbench/cogbench.py --statmind scratch/harness/StatMind/target/release/statmind.exe daemon
```

In a second terminal:

```powershell
python scratch/harness/cogbench/cogbench.py dump
$env:PYTHONIOENCODING = 'utf-8'
python scratch/harness/cogbench/glyphs.py --statmind scratch/harness/StatMind/target/release/statmind.exe screen
python scratch/harness/cogbench/cogbench.py move e
```

The daemon binds only loopback TCP, default port 31725; override
`COGBENCH_PORT` for parallel instances. Direct MCP stdio is also supported:
`statmind.exe --mcp --pid PID`. `STATMIND_PID` is passed through by cogbench.
Dump paths preserve Windows drive letters. `--headless` uses dummy SDL video
and audio; omit it for a game window. The launcher always copies the complete
game, installs the shim in that private copy, uses the game working directory,
and supplies `-luigiAi` with an isolated profile. The original installation is
never modified. Use fresh stage and profile paths for deterministic runs.

For a repeated retail baseline, or a retail versus reconstructed comparison:

```powershell
python tools/compare_gameplay_windows.py --game 'COGMIND (Beta 17.1)' --sdl build/windows-harness/SDL.dll --statmind scratch/harness/StatMind/target/release/statmind.exe --output build/windows/comparison --headless --seed DECOGWINDOWS1
# Add --right build/windows/COGMIND-rebuilt.exe for a reconstructed executable.
```

The runner waits for a game-produced known map containing the player and proves
one warm-up wait advanced gameplay before its initial observation. It captures
initial terrain/occupancy once per location and game-produced known-map/resource/action
stat dumps after each action, sends the same action list to
both fresh seeded profiles, and writes `comparison.json` plus raw observations.
`--actions actions.json` accepts a list of MCP `{tool, arguments}` objects.
The default sequence is wait, move east, wait. Each action must advance game
counters. The comparison excludes heap addresses, colors and wall-clock fields.
Repeated retail games have matched counters/resources and static terrain but
different ambient actor positions; those positions are excluded from the fuzzy
verdict and retained in the separate exact verdict. The upstream cell sweep has
also returned 9,999 of a 10,000-cell map, with a different unreadable entry between
runs. At most one missing entry is tolerated, all jointly observed terrain must
match, and the report records coverage. Larger gaps fail.

The fuzzy known-map projection replaces every alphabetic glyph with space;
letters ordinarily represent robots, but any other feature represented by a letter
is excluded too. The complete original known maps remain in the raw observations.
Terrain is sampled at location entry and cached during the short replay; this is
not continuous verification of terrain damage or a proof of NPC behavior.
The comparison is a bounded regression probe and does not establish complete
gameplay equivalence. Native code replacement must retain addresses and shim
fingerprints, or the shim will fail closed when resolving the rebuilt executable.

The native retail versus reconstructed run passed this bounded comparison on
2026-10-09. In both runs, turns progressed 1, 2, 4, 5; actions progressed
1, 2, 3, 4; one space was moved; and energy progressed 110, 120, 136, 146.
Core integrity stayed 250 and matter stayed 300. All 9,998 jointly observed
terrain cells matched at each observation. Each reader skipped one different
cell, and two raw robot glyphs differed at each observation; the exact verdict
was false. The local report is uild/windows/rebuilt-harness-proof/comparison.json.
The output executable hash equals the reference hash because verified game bodies
are byte-identical after relocation into the retained retail scaffold.

Windows scanner regression:

```powershell
cargo test --release --manifest-path scratch/harness/StatMind/Cargo.toml windows_tests
```

This uses an actual low-address Win32 allocation and process handle, verifies
a magic pair crossing a 64KiB scan boundary, and checks write-range validation.

Native cogbench TCP integration (fresh output directory):

```powershell
python tests/check_windows_cogbench.py --game 'COGMIND (Beta 17.1)' --sdl build/windows-harness/SDL.dll --statmind scratch/harness/StatMind/target/release/statmind.exe --cogbench scratch/harness/cogbench --output build/windows/tcp-proof
```

This checks daemon startup, `dump`, `move e`, and another `dump`, asserting
that game-produced action and movement counters increase. It rejects an occupied
port and closes only the private game and daemon it launched. The tested native
retail run advanced from one wait/action and zero spaces moved to two actions,
one move and one space moved.

The fixed-address upstream `player` record remains unpopulated on the tested
native Windows build even during active gameplay. The runner uses the game's
own player-centered known-map dump instead; `player` and `look` can report stale
coordinates, so use `dump` or `glyphs.py screen` as the reliable observation.
The upstream `actionReady` stays zero too: a mailbox reply saying "no turn
advanced" is not authoritative. Game-produced action/turn counters prove progress.
The upstream Kubernetes supervisor, browser video stream, and macOS episode
launcher are not used by these native launch and comparison commands.
