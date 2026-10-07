# Handoff (2026-10-05)

## State
- **2026-10-07 astra580:** `EntityAI::unknown580ec0` (0x580ec0, 0x213 bytes) MATCHes under `tools/try.sh src/op/op_astra580.cpp -- 'EntityAI::unknown580ec0=0x580ec0'`. New source/mapping: `src/op/op_astra580.cpp`, `config/mapping.d/op_astra580.csv`; claim: `build/claims_op_astra580.txt`. Partial record layout and semantic names remain placeholders. No full-link verification of this addition yet.
- Immediately before astra580, commit `1faa70f` passed `tools/build.sh`: 32,026/32,026 mappings MATCH; 42.092% code, 12,512/13,009 functions. The previously reported `op_t3_g.cpp` compile failure was absent in that build.
- **2026-10-06 evening: verified 30.826% code (10,966 / 13,009 funcs), 15.14% data.** op_x2..x5 and op_g1 (2 giants, 90 KB) integrated; 14 order-dependent/DIFF rows pruned. Open: op_r2_d.cpp declares 0x8979b0 as (HItem,int,int), exe takes bool (use (HItem,bool,int)); op_x5_b_c.cpp redeclares OpY7_SpecialCommands (check).
- Giants: Ghidra 12.1.4 in 3rdparty/ghidra, project build/ghidra_cogmind (~2 GB; clones p2..p5 and scratch/ are deletable), decompiles in build/ghidra_cogmind/dec/<va>.c for 41 of 44 giants (missing 0x51da30, 0x8b5250, 0x83dfa0). Workers op_g2..g5 (GiantDie/Move/Damage/Projectile) write semantic code to native/giants/. Cleanup rule: scratch dirs must not end in `_tmp` (integration runs rm -rf build/*_tmp).
- **Native (macOS) track: see docs/NATIVE.md** (tools/native_build.py, tools/callgraph.py). Data matching stat added to progress.py (tools/lverify.py `data_stats`).
- Last *verified* full link (2026-10-06 after op_q/op_r/op_s workers): **25.813%** code bytes, 10,071 / 13,009 functions;
  29,556 / 29,561 verified lines matched; the 5 DIFF rows (op_s1c RecList::add/addAll, op_r1h add4722b0, op_s8b Fn9d4b30, lead_discovered swap<Point>) were dropped from csvs afterwards.
  Stale-claim cleanup (168 VAs) done 2026-10-05; backup in build/claims_bak/.
- To verify: when no agent is editing src/op/, run `tools/build.sh`, then `.venv/bin/python tools/lverify.py | grep DIFF`,
  drop non-matching rows from the offending area csv, then `.venv/bin/python tools/progress.py`.
- build.sh must link: two TUs must not both define the same symbol. Pitfalls seen: a global defined in two TUs (use `extern`);
  a class declared WITHOUT its virtual dtor in one TU gets an implicit inline dtor emitted there, clashing with the real one in another TU (declare `virtual ~X();`).
  Scratch .cpp files in src/ get linked: keep them in build/<area>_tmp.
- 0xA044D0-0xA9xxxx (libprotobuf /O2) and CRT above are unmatchable with try.sh (q5-q8 confirmed).

## Who is working where (2026-10-06)
- No active workers. Subagents (op_q*, op_r*, op_s*) all died on 429 rate limits / revoked OAuth; their csvs/sources are integrated and verified.
  Dormant leftovers: src/op/op_y6.cpp lost 5 functions that op_r4_b.cpp now defines.
- Next: remaining candidates in build/op_unmatched.csv (`0xVA,size`, refreshed 2026-10-06; ~60-1500 B funcs in 0x409000-0xa044d0).
  New workers should use fresh area ids (op_t*, ...).
- Finished (session 31910c09, all jointly MATCH under try.sh): op_w1 0x8a7370-0x8b0000 (53 funcs, 35.9 KB),
  op_w2 0x710000-0x720000 (78, 41.2 KB), op_w3 0x720000-0x730000 (106, 68.0 KB), op_w4 0x730000-0x750000 (69, 37.3 KB),
  op_w6 0x4a0000-0x4b0000 (132, 28.8 KB). Left in op_w4's range: ~28 large functions. Not matched in op_w6:
  CPolymindSuspicion::getRequiredWidth 0x4a1840 (string temporary), CInfoTitle::CInfoTitle (14 instrs differ).
- Older areas: op_a..op_h, op_pb (protobuf), cc_* (session "Function matching"), batch*/misc_small.
- Claim protocol: before starting a function, grep config/mapping.d/*.csv and build/claims_*.txt for its VA, then
  append it to your own build/claims_<area>.txt. Brief for workers: docs/OP_BRIEF.md.
- **Hazard:** two agents writing the same area csv lose matches (op_w6 lost 81 that had to be recovered from source
  comments). Pick a new area id/range (e.g. op_x1) and never rewrite another area's csv.

## Codegen lessons (op_w* workers)
- Stack-slot order is a name hash (insertion order within a bucket), per scope. To brute-force it, compile a toy file with
  the same type:name list (~1 s each); see 31910c09 scratchpad opw1/rank2.py.
- An exe `je` straight to the epilogue means `if (x != y) { ...rest }`, not an early return. A dead `jmp` after a return
  means `if (...) { return; } else { ... }`.
- Two identical-bodied callees where you'd write one = the original had two functions (ICF folded them). Declare both.
- Stubbed callees count as can-throw, so callers keep EH states the exe dropped. Declaring a known non-throwing callee
  `throw()` fixes it.

## Earlier session (2026-10-04)
- Then-verified: 8.061% (529,317 bytes), 3,074 / 12,948 functions, on build/cc_full copied to build/full.

## Done this session (all recorded in config/mapping.d/)
- misc_small.csv (mine): Item::setActivateOkayTurn, Prop::setSoundMute, CMap::endAudioLogs, CMission::mute/unmuteAudio,
  Cell::removeItem, Network::init/deinit, CLog::trigger.
- batch1..batch5, batch8, batch10 csvs from subagents (batch7, batch9 may still be running / unfinished).
- Names fixed in config/names.csv: 0x415b00 getSoundFromFile, 0x4929b0 CCommandsAdvancedPage ctor.

## Verifier changes (tools/lverify.py, tests/check_literals.py)
1. A literal pushed into any std::string(const char*) call (ctor, operator+, operator==...) compares through its NUL.
   Fixes the exe's pooled short literals ("", ")", "\""): the problem was the verifier, not the linker
   (our /GL literals have no map symbols, so it compared 8 raw bytes).
2. When an exe call target has names but none match ours, fall back to consistent-pairing (ICF-folded bodies).
3. Names that exist in our link only as stubs (16 zero bytes) are skipped, not compared.
4. Sparse switches (`movzx r, byte [r+idx]` + `jmp [r*4+tbl]`, byte index table after the dword table) are
   recognised, including several switches whose tables sit back to back (dword1, bytes1, dword2, bytes2):
   dword targets checked as before, index bytes compared raw. Was a bogus "size differs" (0x8af450, 0x71adc0).
5. A pushed operand that names one of our variables (e.g. a .bss std::string before operator+(const char*, ...))
   is paired like any global, not compared as a C literal (0x7329f0).
6. Image.read zero-fills reads past a section's raw data (.bss tail) instead of returning b'' (0x499160).
- tools/funcindex.py also takes a 16-aligned prologue right after a jump table (previous 4 bytes = a code address
  just below) as a function start: +82 starts, none inside a mapped function (0x71a940, 0x7464b0 were merged before).

## Pitfalls
- zsh does not word-split unquoted `$VAR`: pass source lists with `xargs`, never `$SRCS`.
  (This caused a fake "File name is too long / src/web.cpp" build failure.)
- `tools/sources.py` globs src/: delete scratch files (src/game/v9_*.cpp, b7v*.cpp, *.bak) before a plain
  `tools/build.sh`, or filter them out as above.
- try.sh passing in isolation does not prove the combined link passes: stub symbols with the same mangled name must
  pair to ONE exe address across all files (e.g. `Entity::getName` 0x45a280 vs the +0xc getter 0x416f40, now `getNameAt0c`;
  `logWarning` 0x404e50 vs `logError` 0x404f10).
- Stack-slot order follows local variable NAMES (and scope), not just declaration order; renaming a local can fix swaps.
- `volatile int zero` makes `1/zero` load the divisor into ecx; struct-return temps explain stray stack temps.

## Unfinished / next
- Near-misses (stack slots only): EntityAI::setPatrolRandom 0x5b3430, CCommands::setAdvancedCommandsPage 0x7d1960,
  XResourceMgr::getRWopsFromFile 0x415760, GameMetaData::getGalleryCollectionPercent 0x46c700.
- Not attempted: MapRecord::updateItem 0x6c1a90, CompanionData::upgrade 0x7aba60.
- Overmind::/Zionmind:: functions are reserved for another tool; skip them.
- Another Claude session ("Function matching") writes src/game/cc_*.cpp and config/mapping.d/cc_*.csv and
  claims addresses in build/claims_*.txt; mine are in build/claims_57fa48.txt.
- Not touched: names.csv still has stale placeholder names for some entries.
