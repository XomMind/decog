# Semantic audit of existing matches (2026-10-07)

Byte-identical code establishes an operation, not the original class hierarchy, ownership model, or source spelling. This pass preserves existing compiler-facing symbols and mapping rows. The names below are semantic interpretations, not additional MATCH claims.

## Reproduce the naming audit

```
.venv/bin/python tools/semantic_audit.py
.venv/bin/python tools/semantic_audit.py --json
```

The read-only tool joins **all mapping rows**, retaining aliases and repeated names at different addresses, with `build/namestrings.csv`. It checks cached string bytes against the executable and requires a decoded immediate reference inside the mapped extent. Regenerate the input with `tools/namestrings.py` when needed. It does not rewrite config or regenerate the cache automatically.

Observed snapshot: 21,884 distinct mapped addresses, 439 addresses with multiple names, 22 exact mapping names associated with multiple addresses, seven diagnostic disagreements, five rejected cached associations. These are inventory counts including library/template mappings, not game-function coverage or a new full-link verification.

Limitations: mapping extents are assumed, linear disassembly is not control-flow proof, and only existing cached candidate associations are examined. A valid string reference proves use of a diagnostic label, not that the label is correct. Missing immediate references do not prove a function never accesses a string indirectly. Multiple names/addresses are review candidates, not automatically invalid mappings.

## Naming decisions: avoid making good matches worse

| Address | Keep semantic interpretation | Evidence / rejected interpretation |
|---|---|---|
| `0x415b00` | `XResourceMgr::getSoundFromFile` | Binary xref shows a sound-sample constructor caller and `Failed to load sound` / `Mix_LoadWAV_RW` messages. The embedded `getSurfaceFromFile()` label is misleading. |
| `0x4f9f50` | `DiscordWebhook::addComment` (queue operation) | `src/match_sweep/discord.cpp:24-40` checks a 100-comment cap and pushes under a mutex. Binary contains both `postComment()` and `addComment()` diagnostics. Do not rename this to the network sender. |
| `0x70e640` | `BS::serialize` | Binary contains `Serializing BattleScape`; `src/game/team_c_23.cpp:385` writes world state to an output stream. `BS::BattleScape()` is its diagnostic label, not evidence of a constructor. |
| `0x70ffd0` | `BS` saved-state constructor | `src/game/team_c_28.cpp` is the corresponding saved-state reader. `BS::BattleScape()` is compatible with constructor semantics; it does not require a method named `BattleScape`. |
| `0x5791a0` | `Item::setActive` | Fresh xref lists `setActive()` diagnostics and `setBroken` as a caller. Cached `setBroken()` associations have no immediate reference inside the mapped extent. |
| `0x7e92a0` | `CLore::input` | Fresh xref places it in `CLore` vtable slot 4. Cached `inputAscii()` association has no immediate reference inside the mapped extent. |
| `0x4929b0` | Do not rename from cached `XFontSet::init()` | That cached association also lacks an immediate reference inside the mapped extent. Existing handoff already identifies the advanced-commands-page constructor. |
| `0x474a20` | Retain `Scorekeeper::outputScoresheet` pending focused review | Its large mapped body references `Scorekeeper::totalScore()`, but xref also shows scoresheet labels, output helpers, and game-over callers. A label inside a large body is insufficient to rename the whole body. |

`Config::init_43afa0` versus `Config::init` is a placeholder suffix, not a demonstrated semantic error. The audit also reports an Overmind suffix discrepancy; no reserved Overmind/Zionmind implementation was investigated or changed.

## Folded addresses are operations, not types

Fresh `fdis.py` runs establish:

| Address | Machine operation | Semantic consequence |
|---|---|---|
| `0x416f40` | Return `this + 0x0c` | An address-producing accessor. It can name a string, vector, or color member depending on the receiver. It is not universally an entity-name getter. |
| `0x9b4350` | Load one word from `this + 8` | The `Protobuf::PingRequest::GetCachedSize` label does not establish protobuf ancestry or even an integer result at another call site. A 32-bit pointer has the same load. |
| `0x9b81f0` | Return `*(word*)this + index * 4`, without a range check | Four-byte-element unchecked subscript. Facades naming it `at()` do not have checked `std::vector::at` semantics. Stride alone cannot distinguish handles, pointers, or integers. |
| `0x45ad90` | Load pointer-sized word from `this + 0xec` (`Entity::getInventory`) | Corrected by save-backed pass: this is an `OpS1c_RecList`-layout record list (also at Item+0x58, Prop+0x30), not the item inventory (`getInventoryList` 0x45ab00) and not a protobuf exit list. `addEarlyExiter` (0x5bd450) now uses TriggerRecordList types; see scratch/inventory/REPORT.md. |

Concrete traps:

- `src/game/batch5.cpp:65-82,194-209`: the `Protobuf::Cogmind` / `ExplicitlyConstructed` facade supports matching inventory enumeration in `EntityAI::addEarlyExiter`; it does not establish a protobuf-owned exit list.
- `src/game/batch7.cpp` and `batch8.cpp`: inheritance and explicitly qualified protobuf getters stand in for folded operations. Do not propagate these into a canonical gameplay hierarchy.
- `src/game/cc_r1_06.cpp:30-35`: the receiver-specific interpretation of `0x416f40` is a group member-vector address. `src/engine/xconsole.h:156-202` uses the same operation for `XCell::fore`.
- Disassembly/xref labels select one alias. Read the receiver and consumer before trusting the displayed class name. `semantic_audit.py --json` retains the complete mapping alias sets rather than a last-name-wins view.

## World lifecycle and the two different engines

The global pointer at `0xcefc4c` is the battlescape/world-state owner (`BS`, called `Map` in partial reconstructions), not the cell grid at `0xcfd44c` and not the `CMap` presentation console. Its teardown target is `0x7130c0` (`src/game/team_c_22.cpp`). Serialization and saved-state construction are `0x70e640` and `0x70ffd0`.

The global pointer at `0xcefc50` is a separate gameplay-effects engine. `GM::endGame` at `0x78d4c0` clears pools, deletes/nulls the world, then deletes/nulls this engine (`src/game/batch10.cpp:87-110`). Fresh xref confirms the deleting-wrapper edges; the engine's underlying destructor is `0x4548e0`.

There is also a **console-associated particle engine**, with constructor `0x50fa20`, destructor `0x454ca0`, and update `0x50fff0`. Fresh xref confirms construction from Console constructors and a separate update path. `src/op/op_u2.cpp:855-919` lays out console at `+0`, dimensions at `+4`, offset at `+0xc`, and active/recycled lists at `+0x14/+0x24`.

`src/game/batch4.cpp:45-119` conflates these two identities under `Engine`: `killGroup` uses lists at `+0x14/+0x24`, whereas `update` casts its receiver to lists at `+0/+0x10` and compares it with `0xcefc50`. The cast is matching scaffolding, not proof of one layout. Use descriptive semantic labels **gameplay-effects engine** and **console-particle engine** until original class spellings are independently established.

The same file's `XTimer::update` at `0x4218e0` is better interpreted as **noise-field advancement**: `src/op/op_r1b.cpp:381-457` reconstructs its field operations, and fresh xref names callers in both engine updates. An elapsed-time check elsewhere in the engine does not make this object a timer.

## Large-scope reconstruction priorities

1. **Recover identities by receiver and offset before merging classes.** Start with BS/Map, the two engines, Entity inventory, and Group membership. Record value versus address returns, ownership, and typed consumers. Never infer a common class from an ICF address or a shared diagnostic prefix.
2. **Use world save/load/destruction as a joint layout constraint.** `team_c_23`, `team_c_28`, and `team_c_22` respectively expose write order, construction/read order, and cleanup. [INFERENCE] Reconciling those three views should resolve more fields and ownership than independently naming tiny accessors. Keep per-level globals in the ownership model; not all world state lives inside BS.
3. **Separate ABI evidence from semantic model.** The `/Od` matching translation units deliberately use partial layouts, opaque template types, and fake inheritance. Do not consolidate them into a shared header merely for readability: class unification can change template selection, EH inference, and existing matches. A later cutover must migrate every caller and prove the full link.
4. **Preserve aliases in analysis and count unique addresses explicitly.** `common.functions()` is keyed by name and cannot retain multiple rows with the same spelling at different addresses. The new audit deliberately uses `mapping_rows()`. Alias count is not additional game coverage; name collisions are not proof of distinct semantic functions.
5. **Validate meaningful state transitions, not just successful compilation.** For a future runnable semantic cutover, prioritize world save/load round trips, teardown ownership, inventory transfer, and active-to-recycled effect transitions. These are proposed verification targets, not tests exercised by this static pass.

## Verification and change boundary

Executed the new audit's text and JSON CLI paths against the repository executable. A separate smoke command asserted rejection of the Item/CLore cached misattributions, retention of both Discord diagnostic labels, and retention of both mangled and readable Item aliases. Ran focused `xref.py` for naming/lifecycle evidence and `fdis.py` for all four operations in the folded-address table.

The audit pass itself changed no source. The save-backed fixes below did change sources and were verified with a private full LTCG link: 32026/32026 MATCH, 0 DIFF (build/full_sem3). No game-runtime behavior is claimed.

## Save-backed fixes applied (2026-10-07)

Saves: gzip around a raw little-endian ostream, no tags/lengths. Header: string `Beta 17.1`, string build `260824a`, i32 saveVersion 94; then map indices, map records, 7 handle pools, PlayerData, Stats, GameData, four rec blocks, then `BS::serialize` (302 writes; BS starts at stream offset 0x1cdbb). Both v94 saves parse exactly to EOF with the decoder generated from exe call order (`scratch/savefmt/savedump.py`, gitignored). v75-v93 bodies are not v94-compatible.

Applied: `batch4.cpp` split (`EndObjB::update` for the gameplay object at 0xcefc50; console particle `Engine`; noise field embedded in both); `batch5/7/8/10.cpp` protobuf facades and `GROUP_TYPE`-style macros replaced by receiver-correct types (0x9b4350 = `Group::getFaction`/`Item::getType`/`Entity::getRecord`); `team_c_28.cpp` `C28_G20` size 0x20 -> 0x14 (exe 0x9d29d0 allocates 0x14); `op_y9.cpp` handle-generation global renamed (`list1[slot]<<16|slot` handle scheme). Reports and the 346-row BS layout table: `scratch/engines`, `scratch/inventory`, `scratch/savefmt`, `scratch/world`.

Unknown: most BS member names (21 proven, 52 inferred, 217 unknown), PlayerData f700/f724, dtor ownership gaps (+0x800 records, +0x288 weighted objects, six serialized globals not reset).

## Surgical (extermination) parties (2026-10-10)

The UI calls party type 5 "extermination" (`partyTypeNames_d2f350`); the code's own label is `Overmind::spawnSurgicalParty()` (logError string at 0xbea564). Its only immediate reference is inside 0x685a10. `config/names.csv` had attributed it to 0x6854e0 with a merged extent: 0xfa1 = 0x530 + 0xa71. 0x685a10 is now `spawnSurgicalParty`, and 0x6854e0 (Q-Series utility parts, sibling of `loadZWeaponList`) is now `loadZPartList`.

The timer is the absolute turn `Overmind+0x70` (0xcf6498). `OpR3c_Overmind::resetSurgicalTimer` (0x684c40) sets it to turn + `surgicalIntervals[depthIndex]` (0xb93790 cols 0-1) + Zone Cloak delay (0xb989b4 by `rifLevels[9]`) + 75 * `BS::getDisabledGarrisonAccesses()`, then clears the visited-block grid at `Overmind+0x60` (0xcf6488). `BS::playerActionFinish` (0x774390) subtracts `surgicalBlocks[type].timerCredit` (0xb90294) the first time Cogmind's position enters a `size`-cell block (0xb90290). `BS::onGarrisonAccessDisabled` (0x727370) adds 75. `Overmind::turnUpdate` (0x675100) resets the timer whenever `turn >= timer`; only after that does it apply the 25-turn `lastDispatchTurn` gap and the cap of fewer than 10 type-5 parties.

Other names from the same pass: `getDepthIndex` (0x46f4e0 / 0x46ed20, 11 + depth), `countParties` / `findParty` / `lastParty` (0x45edd0 / 0x45ed50 / 0x45ed10), `selectRobotOfClass` (0x6c5600; args rarity, class, next tier), `findDispatchExit` (0x683500), `addParty` (0x6827d0), `spawnInterceptParty` (0x686490, type 9), `spawnCouplingParty` (0x6868e0, type 10), `spawnHunterParty` (0x687520, type 7, Hunter leader), `rifLevels_cf4a04` (RIF ability levels; index order is `rifAbilityNames_d2a2e0`), and `mapNames_cfaca0` / `robotClassNames_d2f798`. Verification: a full LTCG build gave row-for-row the same lverify result as the pre-rename build. After alias pruning (`docs/HANDOFF.md`, State) the full build verifies 29,661 / 29,661.
