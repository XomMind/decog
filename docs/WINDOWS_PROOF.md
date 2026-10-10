# Native Windows proof, 2026-10-09

Validated against the unchanged matching corpus at `4483643`, using VS2010 SP1
16.00.40219.01 on native Windows. All 933 translation units compiled and linked.
No matching source or mapping row was changed. The first native audit found 201
diagnostic `__FILE__` string differences; preserving the historical compiler
paths fixed them without changing or relaxing the strict verifier.

## Compiled-body reconstruction

- 29,816 of 32,014 mapping rows MATCH; the remaining 2,198 are surplus aliases.
- 13,013/13,013 indexed game functions and 9,361/9,361 funclets proved.
- 6,566,496/6,566,496 indexed game-code bytes covered.
- 22,377 unique compiled bodies relocated and individually byte-checked.
- Output SHA256: `6c96192b9b7a81956416abdb11766933bca21fce8c2c0d57b97b172e13cd8184`.

The output hash equals retail because proved compiler output is placed back at
the original addresses. Retail PE/CRT/vendor-library/global-data scaffolding is
retained. This is an address-preserving reconstruction, not an independent
standalone source link. No verification dependency stubs are installed.

Local evidence: `build/full_windows/build.json`,
`build/windows/strict-verify.log`, and `build/windows/COGMIND-rebuilt.json`.
The manifest records individual installed body hashes and retained scaffold.

## Desktop bridge

The computer-use bridge selected the window whose process path was explicitly
`build/windows/game/COGMIND-rebuilt.exe`, using the supplied stock runtime DLLs.
Directly observed screenshots and bridge input established:

1. Beta 17.1 difficulty selection, intro, and live player/map/resource panels.
2. Numpad 5 advanced TIME 1 to 2; Numpad 6 moved east and advanced TIME to 3.
3. Help/options opened; Hibernate saved a 52,873-byte save and exited cleanly.
4. Reopening the same rebuilt executable restored TIME 3, map, log and resources.
5. Another wait advanced TIME 3 to 4. The resumed GUI was left running.

Local evidence: `build/windows/gui-proof.json`,
`build/windows/game/play-session.json`, and the private game save.

## Native headless harness

Retail and rebuild used fresh seeded profiles and the same SDL shim. After a
proved warm-up wait, the replay sent wait, east movement, wait. Both runs had
turns 1→2→4→5, actions 1→2→3→4, spaces moved 0→0→1→1, and energy
110→120→136→146. Core remained 250 and matter 300. All 9,998 jointly observed
terrain cells matched at each observation; the fuzzy verdict passed.

The exact verdict remains false. Each reader skipped one different terrain
entry, and raw known maps differed by two glyphs per observation. Entity
occupancy and all alphabetic known-map glyphs are excluded from the fuzzy
verdict. Initial terrain is captured once per location. This bounded probe does
not establish full gameplay or NPC-path equivalence.

Actual cogbench loopback TCP dump→move east→dump also advanced actions and one
space. The Win32 memory scanner regression, relocation checks, strict target
identity checks, retail equivalence checks, and Python compilation passed.

Local evidence: `build/windows/rebuilt-harness-proof/comparison.json` and its raw
observations, `build/windows/tcp-harness-proof/tcp-proof.json`.
See [WINDOWS.md](WINDOWS.md) and [WINDOWS_HARNESS.md](WINDOWS_HARNESS.md) to repeat.
