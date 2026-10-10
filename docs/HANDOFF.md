# Handoff (2026-10-08, evening)

## State

**Historical state: 13,013 / 13,014 game functions, 96.08% code** (last lenient full build; library
reclassifications below lower the denominator). This is not a strict verified count; see the repair below.

**Current state (2026-10-09, strict): 13,013 / 13,013 game functions, 6,566,496 / 6,566,496 code bytes (100.00%).**
Strict full build `build/full_r9`, audit `build/target_audit_r9.*`: 29,816 / 32,014 rows MATCH, 0 regressions
in any round. Rounds 4/4b/5 (ConsoleUI, CMapUpdate, XConsoleCallers, Strings, PosPoint, Unnamed, StlTemplates,
Polymind, StlTail; reports in `scratch/<name>/REPORT.md`): 96.70% -> 99.70% -> 99.94% -> 100%.
The 2,198 remaining DIFF rows all sit at retail VAs that another row already credits (1,786 body-different,
412 identity-ambiguous): they are surplus ICF/alias rows, not missing functions. `lverify` still exits 1 because of them.
Pruning or repointing them is the remaining work.
Several STL rows name an ICF-arbitrary instantiation at folded VAs ([INFERENCE] in the round reports).
`tools/progress.py` has not been rerun: `docs/progress.*` are stale.

### Remaining function: done (2026-10-08, late)
- **0x51da30 `BS::turnUpdate_51da30`** (258 KB, 62,072 insns) now MATCHes in `tools/try.sh`. Source
  `src/util/uniform_01.cpp`, row `config/mapping.d/uniform.csv`. Gate on a full build (`build/full_giant`,
  strict verifier): the candidate adds exactly this row (28,057 -> 28,058 MATCH of 32,328) and no row changes status.
  All 5,703 frame offsets and all 931 EH unwind entries are identical. Draft history and tools: `scratch/whiskey/NOTES.md`
  ("completion"), frame solver `scratch/giant_frame/gf.py`.
- Mapping fix found on the way: `lead_discovered.csv` named 0x9af3b0 (`assign(1,c)`) as `string::operator+=(char)`.
  It is `operator=(char)`; `operator+=(char)` is 0x9af410 (`append(1,c)`). Both rows lvx-MATCH; strict total
  28,032 -> 28,057 (25 rejected callers recovered). 4,270 strict rejections remain for review.

### Verifier leniency (fixed fail-closed; mapping review required)
`tools/lverify.py` no longer learns a replacement address for a configured callee. Configured symbol identities,
including imports, must target an address named for that symbol. Only unconfigured symbols may learn consistent
target pairings. The same restriction applies to vtable coverage accounting and unnamed pointer operands.
There is no ICF exception: different addresses are rejected until a separate complete-body equivalence proof
exists. This deliberately rejects unproved genuine aliases as well as incorrect rows; DIFF is not by itself
proof that the reconstructed caller is wrong. No depth-limited recursive equivalence claim is made.

Strict state after this pass (retained `build/full`, repaired mappings, `tools/classify_targets.py`):
**27,996 / 32,326 MATCH; 4,330 DIFF; exit 1. Strict coverage 11,611 / 13,013 functions, 3,125,157 / 6,566,496 code
bytes (47.59%)**, down from the lenient 96%. Evidence (local, uncommitted): `build/target_audit_final.{json,csv,log}`.
DIFF buckets by rejected-target evidence only: 3,384 body-different, 945 identity-ambiguous (signature-free
display-name collisions, e.g. `std::...::insert` overloads), 1 other. Body equivalence is never overload identity.

New tools: `tools/retail_equivalence.py` (complete-body proof: full extents, relocation-aware internal addresses,
exact data/IAT targets, cycle-safe recursive callee proof, CFG fallthrough/indirect-jump guard, shared with lverify)
and `tools/classify_targets.py` (read-only report). Regressions: `tests/check_target_identity.py`,
`tests/check_retail_equivalence.py`. lverify now also: prefers exact decorated identities over display aliases,
rejects truncated retail decodes, and fails if a rejected target is hidden by equal relative displacement bytes.
Every retail-side `Image(...)` caller passes `common.symbols()`.

`0x9bad50` cluster (270 rows in `lead_discovered.csv`; the body is the stringbuf deleting dtor, not a universal
one): 234 rows repointed to their existing canonical wrapper address (each direct strict MATCH), 36 with no unique
canonical alias deleted. Manifests: `build/target_repair_{original,changes,demoted}`.

Next: the 945 ambiguous and 3,384 body-different rows (many are real wrong rows or unresolved stub callees such
as `??1Closure`, not ICF folds); `tools/progress.py` was not rerun, so `docs/progress.*` still show the lenient count.
No full build or source edits happened. Previous research dirs `scratch/bravo3/`, `scratch/charlie3/` were absent.

Triage (reports in `scratch/triage/`, uncommitted; counts from `build/target_audit_final.json`):
- Access-letter rule R1 applied in `lverify.configured_targets` (names differing only in `Q/I/A` access letter resolve to the
  one configured identity; zero or several matches stay rejected). Re-audit `build/target_audit_r1.*`:
  **28,029 / 32,326 MATCH, 4,297 DIFF; 11,644 / 13,013 functions, 3,125,688 / 6,566,496 bytes (47.60%)**.
- 912 ambiguous rows left: 182 same-address different signature/instantiation (genuine), 632 callee configured only under an
  ICF-folded sibling (config gaps: `_Tree`, Point/Pos/Area/Rect ctors, vector members), 95 placeholder-named retail targets,
  2 `U`/`V` struct-key rows (not recommended), 1 `_floorf`. A looser alias-bucket rule would convert 189 rows but accepts
  signature mismatches; rejected.
- 3,384 body-different rows: 204 our callee is a stub, 1,500 real callee size differs, 1,555 dependency mismatch, 125 other.
  Highest leverage callees: `XConsole::getWidth` (129 rows; retail calls 0x44b0d0 but config maps 0x9b6bd0),
  `vector<int>::push_back(int&&)` (109), `string::operator+=(char)` (47), `Pos::Pos()`/`Point::Point()` stubs (82 combined),
  `Array2D<int>::operator()` stubs (58), `vector<HItem>::~vector` (39), `vector<int>::back` (31).
- Most affected mapping files: `lead_stl_b.csv` 2,703 rows, `lead_discovered.csv` 312, `op_h.csv` 121. No import-only rejections.
- Combined with the row-427 fix in `lead_discovered.csv` (0x9af3b0 is `string::operator=(char)`; the real `+=`
  is 0x9af410, rows 427/428, both MATCH), re-audit `build/target_audit_r2.*`: **28,057 / 32,327 MATCH, 4,270 DIFF;
  11,671 / 13,013 functions, 3,464,459 / 6,566,496 bytes (52.76%)**. Buckets: 3,350 body-different, 919 ambiguous, 1 other.
- Strict full build of the committed tree (`build/full_strict`, includes `UfBS::turnUpdate_51da30`, which MATCHes under the
  strict verifier): **28,058 / 32,328 MATCH, 4,270 DIFF; 11,672 / 13,013 functions, 3,722,203 / 6,566,496 bytes (56.68%)**;
  audit `build/target_audit_r3.*`. This is the first count that rests on the strict gate; the 96% figure above is obsolete.
  `tools/progress.py` has not been rerun, so `docs/progress.*` are stale.
- First repair round (scratch/{GetWidthFix,TreeGaps,VectorCallees,PointArrayStubs}, uncommitted evidence): wrong callee rows were
  re-pointed or added in new `config/mapping.d/strict_repairs.csv` (123 rows; 73 old rows removed from lead_discovered, lead_stl_a,
  lead_stl_b, team_b_repair), plus real definitions `src/util/zz_point_ctors.cpp` (Pos()/Point()/Pos(const Pos&)/Point(int)/...)
  and `src/util/zz_array2d_int.cpp` (Array2D<int>::operator()). Fixes: `XConsole::getWidth` is 0x44b0d0 (0x9b6bd0 was freeCells),
  `vector<int>::push_back(int&&)` 0x9b9280, `vector<HItem>::~vector` 0x9b7e00, `vector<int>::back` 0x9b6540, `vector<string>()` 0x9b8e80.
  Strict full build `build/full_r4`: **28,643 / 32,375 MATCH, 3,732 DIFF, 0 regressions vs build/full_strict (538 flips, 47 new rows all
  MATCH); 12,180 / 13,013 functions, 4,621,518 / 6,566,496 bytes (70.38%)**. Buckets: 2,975 body-different, 756 ambiguous, 1 other.
  Pos/Point folding and the Array2D layout are [INFERENCE] from body equality. Not applied (evidence in scratch): TreeGaps drop list of
  335 caller rows (_Tree/iterator/pair/allocator, structurally different bodies), 12 `_Pair_base` rows at 0x9eee40, `vector<UHExplosive>`
  (our 64-byte element vs retail 4-byte handle: a source type bug), lvalue/rvalue caller-source differences (`push_back<string>(const&)` etc.).
- Second repair round (scratch/{GeometryCtors,StringFamily,VectorCopies,SameAddressFolds}): 214 rows added to `strict_repairs.csv`, 186 old rows
  removed from 11 files, new real definitions `src/util/zz_geometry_ctors.cpp` (Rect(), Rect(const Rect&), Area(), XEvent(int), Array2D<bool>::operator()),
  `zz_entity_inventory_hitem.cpp`, `zz_entity_inventory_hitemb.cpp` (Entity::getInventoryList). Notable: `less<string>` is 0x9be6c0 (0x9e7970 is
  allocator<string>::construct), string::insert overloads 0x9af760/0x9bb200/0x9bb340, `vector<Point>(const&)` 0x9b35b0, `vector<int>(const&)` 0x9f5990,
  `vector<vector<int>>::push_back(&&)` 0x9e8d90 with the scalar vector move ctor chain. One old MATCH row, `_Construct<vector<int>>` (lead_stl_a 0x9f3750),
  was dropped without replacement (conflicts with the corrected chain). Strict full build `build/full_r5`: **29,038 / 32,403 MATCH, 3,365 DIFF, 0
  regressions vs build/full_r4 (367 flips, 29 new rows MATCH); 12,436 / 13,013 functions, 5,120,633 / 6,566,496 bytes (77.98%)**. Buckets: 2,746
  body-different, 618 ambiguous, 1 other.
  Remaining are mostly CALLER-SOURCE issues, not mapping: (a) `push_back(const&)` vs `&&` (29 rows, `scratch/VectorCopies/caller_source_issues.csv`;
  VS2010 picks const& for implicit int<->unsigned conversions and named lvalues, && for casts, literals and call results; fixed copies proven in
  `scratch/VectorCopies/src/`); (b) string `begin/end/operator+` const vs mutable (27+13 rows, source constness, e.g. `const string file` locals);
  (c) `basic_string(string&&)` where retail copies (14); (d) `vector<UHExplosive>` element type (our 64-byte struct vs retail 4-byte handle);
  (e) 40+ `_Tree<string,X>` instantiations configured to the retail map<string,string> body (our sources use the wrong map value types).
  Unproved/untouched: Pos/Rect source-type confusions (D2Parse, D2Evolve call Pos() where retail zero-inits 4 ints at 0x40a6e0).
- Third round, caller-SOURCE repairs (scratch/{PushBackForms,StringConstness,RemainingTop,MapValueTypes}): 150 files in `src/` edited (push_back
  `&&` vs `const&` forms, string constness/copy-vs-move, Pos/Rect source types), 99 mapping rows added and 628 removed (533 of the removals are
  synthetic deque/list/reverse_iterator alias rows of `src/lead/stl_b.cpp` that retail has no code for and that lost no MATCH), plus 21 re-pointed
  `map<string,string>` rows (retail has exactly one map instantiation, `pair<const string,string>` 0x38 bytes: `_Isnil` +0x45, `_Color` +0x44;
  the 686 `map<string,X>` placeholder rows were aliases onto it) and the `Init_40ca90` -> `Unknown_40cde0::Unknown_40cde0()` row rename.
  Strict full build `build/full_r6`: **29,385 / 31,861 MATCH, 2,476 DIFF, 0 regressions vs build/full_r5 (347 flips, 7 new MATCH rows); 12,703 / 13,013
  functions, 6,349,686 / 6,566,496 bytes (96.70%)**. Buckets: 2,033 body-different, 441 ambiguous, 2 other. The earlier 96% figure and this one
  are not comparable: this one rests on the strict verifier.
  Lessons: (1) `try.sh` copies made in scratch rewrote `#include` paths; only `<fstream>` in `op_b.cpp` was a real addition. (2) `try.sh`
  compiles ONE TU, so it cannot see ODR clashes: `op_cmap_808de0.cpp` (`struct Point : Pos {}`) and `team_c_34.cpp` (`C34_Area{Pos,Pos}`) made the
  compiler emit implicit `Point(const Point&)`/`Pos(const Pos&)` that collide with the explicit definitions in `op_w8.cpp`/`zz_point_ctors.cpp` (LNK2005).
  Both edits were reverted; they need declared copy ctors or a different type fix.
  Held back (not installed; copies under scratch/RemainingTop): shared header edits (`engine/xconsole.h` setFore/setBack 0x417b00 vs `setFgColor`,
  `consoles/consoleui.h`, `pathing/gamedecl.h`, `pathing/dijkstracosts.cpp`), `op_cmap_update.cpp` (replaces file-unique `Cmu*` types; may change LTCG
  nothrow inference), and the `vector<UHExplosive>` fix (`HExplosive` as a 4-byte handle in `op_s1c/op_r1g/cc_r2_30` plus `src/util/zz_explosive64.cpp`
  and `explosive64_all.csv`, 8 rows). Optional, also not installed: `scratch/MapValueTypes/optional_drop_diff_aliases.txt` (280 unsupported DIFF alias rows).
  `tools/progress.py` still not rerun: `docs/progress.*` are stale.

### Fixed this evening (committed with this handoff)
- 19 names mapped to 2-3 different VAs (one row of each was never verified, since `common.functions()` keys by name):
  renamed to the real symbol or deleted, each change lvx-checked (bravo3; table in its report, tools in `scratch/bravo3/`).
  `common.mapping_conflicts()` + an ERROR/exit 1 in `lverify` now stop this recurring.
- Protobuf-3.5.1 `status.cc` static initializers (0xb5c720 OK, 0xb5c730 CANCELLED, 0xb5c7c0 UNKNOWN) moved to
  `config/library.csv`: an unmodified `/O2` compile of that file is byte-identical (`scratch/alpha3/st/`).
- `vec_d2b4bc` (team_c_02.cpp) uses a private 3-byte element type: 0x9b3da0 is the 3-byte-element `~vector`.

### Tooling notes
- Build tools run at utility QoS + nice 10 (`taskpolicy -c utility`); never `-b`.
- Giant-function toolchain: newest in `scratch/victor/`, `scratch/papa/`, `scratch/romeo/`, `scratch/lima/` (frame-layout
  solver), `scratch/yankee/td/` (Heni-draft converters). Only `tools/try.sh` is authoritative; ebp-insensitive diffs hide bugs.


## Isolated protobuf bulk matching (2026-10-08)

A separate protobuf rebuild/discovery pass, independent of the game build. New tools: `tools/protobuf_build.py` and `tools/protobuf_discover.py`. The builder compiles all 80 runtime sources from the upstream CMake lists with VS2010 SP1 16.00.40219.01, `/MD /EHsc /GS /DNDEBUG /DWIN32 /D_WINDOWS`, without `/GL` or LTCG. Retail source spelling `..\protobuf-3.5.1\src\...` and the absolute header include root are preserved. It archives real objects into `protobuf.lib` and links an inspection-only `/NOENTRY` DLL; there are no dependency stubs.

| Profile | Verified distinct retail bodies | Bytes |
| --- | ---: | ---: |
| `/O2` | 111 | 7,208 |
| `/O2 /Oy-` | 1,185 | 248,812 |

Retained builds: `build/protobuf_o2_v2/` and `build/protobuf_o2_fp_v2/`. Candidate rows: `scratch/protobuf_bulk/o2.csv` and `scratch/protobuf_bulk/o2_fp.csv`; adjacent `.report.json` and `.verification.json` preserve discovery evidence and shared-context verification. Both sets reverified with zero errors/conflicts. The original string hash at `0xa04ca0` is included under its real `stdext::hash_compare<const char *, google::protobuf::CstringLess>` specialization.

Reproduce the winning configuration:

```sh
.venv/bin/python tools/protobuf_build.py build/protobuf_o2_fp --profile o2-fp --jobs 2
.venv/bin/python tools/protobuf_discover.py build/protobuf_o2_fp --out scratch/protobuf_bulk/o2_fp.csv
.venv/bin/python tools/protobuf_discover.py build/protobuf_o2_fp --verify scratch/protobuf_bulk/o2_fp.csv
```

Discovery compares complete instruction bytes with the existing verifier's address-relocation semantics, adds optimized starts from direct calls/padding/non-code pointers, rolls back trial pairings, and excludes ambiguity and all conflicting candidates. These are byte-equivalence candidates, not proof of unique original overload identity or recursive correctness of every referenced target/data object. The winning pass excludes 1,095 ambiguous source symbols and 2,469 otherwise unique but conflicting source candidates, including possible ICF aliases; do not count these as matches.

Actual Windows runtime smoke linked against the winning static archive passed DescriptorProto serialization/parsing, descriptor reflection, and repeated-field clearing (31 serialized bytes); executable retained as `build/protobuf_o2_fp_v2/smoke.exe`. A deliberately truncated candidate was rejected. The builder also rejected `build/full` and a shell-metacharacter output path before building.

No bulk rows were installed in `config/mapping.d`, and no game full build was run: the existing game pipeline compiles `/Od /GL` sources and does not consume this separate optimized library. Keep these rows tied to their private DLL/map until a library gate proves old game mappings plus the new library mappings. Earlier failed quoting/platform-define builds are diagnostic artifacts, not accepted builds.

## Native iterator mapping repair (2026-10-08)

`scratch/loop_charlie_43/mapping_repair_manifest.csv` lists five positively proven existing row corrections in cc_prop.csv, team_a_repair.csv and op_y8.csv: const begin9afb40→9afb70, const end9afba0→9afbd0, const+9b0950→9b09b0, mutable+9b09b0→9b0950, const-9c2140→9b09e0. `iterator_overlay.csv` contains these plus five genuine native coverage aliases and the callback candidate; `MAPPING_REPAIR.md`/native_helpers13.dis bind real MSVC10 xstring and full constructor/+=/-= chains. Other suspicious E8 aliases remain unproved and must not be blanket removed. A vector<bool> suspicion was retracted after a genuine native probe.

**The general verifier can learn call-target pairings even when the decorated native overload identity is wrong.** A MATCH alone does not establish that identity. Supplemental `scratch/manager_loop/strict_native_calls.py` checks actual retail call byteoffsets against decorated compiled native callees. Run it against fresh callback try.GkQThh and later full build with candidates.csv/iterator_overlay.csv; explicitly require 18 checked callback calls and no wrong identities. The old b229 audit log `scratch/manager_loop/upload43_native_calls_30.log` fails seven identities and is intentionally retained. Lore's own direct identity audit additionally proves lex→Unchecked→scalar read-only char* chain; char*/constchar* pure read-only ICF bodies cannot uniquely establish original constness. Do not change the verifier, drop mappings or waive this semantic check.

## Latest verified checkpoint (2026-10-08, twenty-ninth source batch)

- **12,909 / 13,016 game functions; 54.796% code matched.** Two unique matches add 11,986 bytes over `8486655`; 107 functions remain. Code totals: 3,598,290 / 6,566,759 bytes.
- **32,252 / 32,252 comparisons MATCH, zero DIFF.** Serialized full build `build/manager_loop_source_full_29.log`, candidate gate `build/manager_loop_source_lvx_29.log`, registered gate `build/manager_loop_source_registered_29.log`. Three installed source hashes checked; raw/code audits zero executable interior operands. Explicit full-context critical native allocator construct9f05e0 gate passed. Older caller repair adds no unique coverage.
- EntityAI movement5b76c0 (5716B) returns fullint status and writes real mandatory int* movement output. Genuine native View44 owns Array2D12 at8 and fallback28 positively stored/read by9cfd90; no framepadding. Native Point/HE vectors, message string temporary and all EH/early-cleanup scopes retain actual lifecycle. World collection is a borrowed pointer-element vector with Point-compatible leading views, not claimed complete allocated Point8 elements.
- Actual visibility716940 has nullableEntity*/nativecount-output; allowance748a00 has nullableView44*/incomplete borrowed Source* with positive nonnull string8 read. Dispatch687520 optional Point is established by two nonnull goal calls. Complex interfaces ordinarymaythrow, genuine scalar/pool/grid/Point leaves positively audited. Borrowed AI prefix is not a complete allocated owner. No invented allocator operations/fake helper or forcedextent.
- CSV Entity export79a180 (6270B) uses genuine native ofstream/string/vector<int>, authentic formatting/lifetimes, native Def/equipment pointer-vector views and true Range8 endpoints. External factory793200 creates genuine Entity328 in poold21720, then actual637bb0 removes each temporary Entity; source declares real external lifecycle instead of allocating an incomplete view. Otherwise-unused native string has real retail ctor/dtor and is preserved without inventing filler.
- Actual resistance5cb570 takes int,bool and speed5d15a0 bool; meaningful fullword getters/unsigned immunity vector count, hidden HEntity return and nested quoted formatting preserve positive ABI. Only true scalar/pool leaves promise throw(); streams/formatting/mutation ordinarymaythrow. Readonly/signedness compatible views do not claim uniquely recovered original typedefs.
- Old EntityAI caller5b7400 correction propagates actual int* to5b76c0; actual takeTurn5826b0 passes scalar-local addresses. Main691B and native owner/lifetime/control/exception behavior unchanged. Isolated emitted helpers50/51 included reachable allocator construct9f05e0 DIFF because Pointcopy was external; existing op_w8.cpp supplies genuine scalarcopy in full link. Explicit full-context helper proof required and passed, no waiver. Original and unsuccessful throw-only exploratory probe preserved; only three pointer parameter changes installed.

## Previous verified checkpoint (2026-10-08, twenty-eighth source batch)

- **12,907 / 13,016 game functions; 54.613% code matched.** Three unique matches add 19,309 bytes over `b57c8b4`; 109 functions remain. Code totals: 3,586,304 / 6,566,759 bytes.
- **32,250 / 32,250 comparisons MATCH, zero DIFF.** Serialized complete full build `build/manager_loop_source_full_28.log`, all-old plus candidate gate `build/manager_loop_source_lvx_28.log`, registered proof `build/manager_loop_source_registered_28.log`; six installed source hashes checked, raw/code audits zero executable interior-stub operands. Three older repairs receive zero additional coverage credit.
- World hit-chance evaluator718430 (5724B) returns float, consumes actual HEntity/mandatory Point/native optional float-vector output and fullint mode. Genuine subcell stepper Base44/derived48, native Point/int vectors and readonly input/output chains have positive raw provenance. Lookup458950 returns borrowed Modifier*, target45a760 fullint, aim5d7b00 truebool input. Original observed diff=25 store retained; two actual trailing tables verified. Original constness/signedness are not claimed uniquely recovered.
- Recursive seed decoder4351e0 (6004B) owns genuine native strings and thirteen actual RNG state types, authentic RNG2508/RNGC4/PCG24 plus scalar state extents. Positive native seed constructors, string iterator lifetime, recursive AL bool return, signed char parser arguments and signed grid remainder preserve observed behavior. Two real trailing tables verified; no fabricated allocated object or filler helper.
- Map fire821450 (7581B) reconstructs usable-weapon selection, melee fallback, special assimilation/reboot, resource and friendly/cave warnings, native path snapshot and real Shoot record transfer/turn-delay output. Shoot124 has real four-slot Base16, native Line16/HItem4/Point8 vectors; Phrase32 owns native string4 with actual message-owner cleanup. Optional PathStep16 output remains separate incomplete domain from true Line16. Native Range8 remains distinct from Point8; complex calls retain ordinary exception contracts.
- Legacy fire63a3e0 repair replaces opaque allocated Action storage with the proven Shoot124 hierarchy and three genuine native owners; actual weighted36/Line/Item owners, native record handle factory/World transfer, meaningful Point assignment and both message HEntity arguments restored. Unsupported complex throw annotations removed and actual Player bool reward preserved. Existing full mapped body/helper checks pass without extra coverage.
- AI assimilation5bbf70 corrects actual Player and Phrase bool returns plus Phrase optional Point input; reinforcement73d320 corrects Dispatch optional Point input. Ignored results/null arguments alone had masked these contracts. Positive actual callee coordinate/AL reads establish domains; compatible readonly qualification does not claim unique original spelling. Earlier sources and isolated proofs retained; no blanket cleanup claim for other old callers.

## Previous verified checkpoint (2026-10-08, twenty-seventh source batch)

- **12,904 / 13,016 game functions; 54.319% code matched.** Two unique matches add 9,867 bytes over `3a14484`; 112 functions remain. Code totals: 3,566,995 / 6,566,759 bytes.
- **32,247 / 32,247 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_27.log`, complete candidate gate `build/manager_loop_source_lvx_27.log`, registered proof `build/manager_loop_source_registered_27.log`. Two installed source hashes checked; raw/code audits zero executable interior-stub operands and genuine extents retained.
- EntityAI assimilation5bbf70 (4815B) returns fullint and accepts int chance/native HEntity. Native Target12 pointer vectorf0, actual Entity string+c/Group28 and borrowed Def68/ac/b0/120 views have positive downstream evidence. Native nested Prop-vector and Machineint-vector mutations, six native string temporary scopes and real route/bubble/end macro expansions preserve actual behavior and cleanup; no custom-object allocation or fake owner/helper.
- Effect dispatcher4569a0 slot7 corrected from maskedint to optional conststring*: queuedrecordfield8 flows through51da30 and49c610 into5111e0 text; nonnull ram caller and synchronous lifetime corroborate the domain. Slot8 is incomplete borrowed trigger/effect-record owner from Entityec, never inferred item Inventory from folded labels. Final genuine ABI correction independently recompiled and fully gated; older provisional callers are separate audit work.
- Settings loader4c8740 (5052B) uses genuine native Record172 with three28B strings14/30/50, unsigned vector70 and fourRange8 fields88..a0; Bridge52/Rect16 and external lifecycle/deepcopy have positive raw proof. Caller allocation establishes Settings164; gzip184 and authentic PhysFS96 satisfy native compiler assertions. Earlier100B stream inference from stackgap was retracted, no padding substituted. Real112B trailing switch table remains standard verified.
- Actual filenamecopy/boolbyte, native byvalue find string, fullint parser4bd300 with two int-to-float stores, unsigned direction conversion and all validation exits preserve native ownership/EH. Emptyclose9c05e0 is only a proven empty leaf, not a false fileclose claim; actual stream destructor owns cleanup. Original FILEzero/fclose guards and caret-byte initialization appear in raw; no invented unused local/scaffold. Readonly input qualification is a compatible private view rather than unique recovered source spelling. Complex allocating/native/files/parsing interfaces ordinarymaythrow.

## Previous verified checkpoint (2026-10-08, twenty-sixth source batch)

- **12,902 / 13,016 game functions; 54.169% code matched.** Three unique matches add 16,990 bytes over `980790e`; 114 functions remain. Code totals: 3,557,128 / 6,566,759 bytes.
- **32,245 / 32,245 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_26.log`, complete candidate gate `build/manager_loop_source_lvx_26.log`, registered proof `build/manager_loop_source_registered_26.log`. Three installed source hashes checked. Raw/code audits zero executable interior-stub operands; genuine target extents unchanged. Explicit critical gate proves both reachable native string replace overloads MATCH in this exact full context.
- Reinforcement73d320 (4762B) uses actual bool(bool,bool,bool,optional Point*) interface, full integer AI follow argument and borrowed Squad* dispatch return. Ten nested native string-vector templates and two real36B weighted owners retain observed allocation, random selection and cleanup. Native Point/Area coordinates, optional placement and proper Entity/Group pools preserve real lifetimes. Read-only position qualification is a compatible private view, not a uniquely recovered original accessor spelling. All general allocating calls remain ordinary maythrow.
- Shell insertion90d550 (5563B) actually mutates its first string and receives a signed fullword mirror skip count; truncate returns bool(string&,unsigned,int), replacement returns owned string(string&,bool*). Genuine128B Text and120B Button owners use native Console108 and actual child-pointer vectors, borrowed Def*6c and real external constructors/destructors. Iterator conversions, temporary native strings, real pointer references and parent-owned child lifetimes are preserved. Two transitively reachable replace overloads had isolated npos constant differences; neither was waived, and both explicitly pass full context before registration.
- Parts activation8993e0 (6665B) has actual void(Part*,bool), real borrowed Part/Item/Entity/Def views and native Part-pointer vector74. Actual native string temporaries and conservative ordinary potentiallythrowing message/hint/refresh/action interfaces preserve EH. Genuine five-entry mode table maps1+2 to hint37,3 to38,4 to39; seven real trailing switch tables remain included in standard verification. No new object allocation, fabricated helper body, forced storage or byte-extent adjustment.

## Previous verified checkpoint (2026-10-08, twenty-fifth source batch)

- **12,899 / 13,016 game functions; 53.910% code matched.** Three unique matches add15,890 bytes over `34b8ff7`; 117 functions remain. Code totals: 3,540,138 / 6,566,759 bytes.
- **32,242 / 32,242 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_25.log`, complete candidate gate `build/manager_loop_source_lvx_25.log`, registered proof `build/manager_loop_source_registered_25.log`. Three installed source hashes checked. Raw/code audits zero executable interior-stub operands; genuine target extents unchanged. Eight directly byte-proved native constructor aliases add no unique credit.
- Population6e0eb0 (4701B) allocates genuine EntityAI304 with real Point-vector owners24/6c/90, Entity-memorydc, target-pointerf0 and owned-record-pointer120. Native external ctor/dtor and positive destructor delete chains establish owned pointers114/11c;118 is honestly unknown void storage directly freed by operator delete, no such pointee allocated here. Unknown tracked4B fields do not claim handle-pool identity. Nested route Point vectors, packed-bool input proxy, weightedDef*/Talk*36, native Point/Rect/Area/string lifetimes and implicit Rect-to-Area temporary preserve actual frame/cleanup. Ordinary spawn/pathfind/terrain/removal/talk/rename and distinct Entity/Prop/Item domains retain truthful signatures; original const qualifications are not claimed from compatible read-only views.
- Volley render88a000 (5670B) uses real Console slot7, native HItem vector78 and float vector8c with positive construction/destruction and direct Itempool/FPU uses. Local native slots vector and strings preserve cleanup; real optional Maprange pathvector*/Point* replace masked bool guesses, unknown16B PathStep is incomplete borrowed interface only. Mutable Point position, hidden Entity/Item/Color/Point returns, byte heat flag/fullwidth guidance/resource/time fields, native int-list speed sum and paletteColor3 vector are audited. No object allocation/filler/forced helper body; complexrender/format/cost/lookup/mutation ordinary maythrow.
- Map collection86e310 (5519B) owns actual20B Record values HE0/Point4/RGBc/glyph10 and native pointer buffers; explicit delete helper frees each record without clearing list, subsequent vector destructors release backing arrays. Seven draw categories use genuine native Entity/Item/Point/int collections, mandatory writable bounds, signed-int-reference erase and borrowed Color* or hiddenColor outputs. Track20 and native borrowed grid prefixes use actual strides; pointer/reference source spelling is not uniquely recovered. Observed bottom-border initialization quirk is preserved.
- Eight genuine private core constructor aliases (Record65B/Area43B and37B/Point33B,33B,38B/Color50B/HE23B) are individually standardMATCH and avoid global provisional class collisions. These are actual observed scalar/copy/value constructor bodies, never fake wrappers or forced padding. Exact shared addresses were already covered; only the5519B handler adds coverage. Track glyph/color leaf no-throw claims have transitive ascii/palette/blink/copy evidence; all allocating/mutable/general interfaces remain ordinary. No target trailing tables or verifier waivers.

## Previous verified checkpoint (2026-10-08, twenty-fourth source batch)

- **12,896 / 13,016 game functions; 53.668% code matched.** Two unique matches add10,194 bytes over `2238e96`; 120 functions remain. Code totals: 3,524,248 / 6,566,759 bytes.
- **32,231 / 32,231 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_24.log`, full candidate gate `build/manager_loop_source_lvx_24.log`, registered proof `build/manager_loop_source_registered_24.log`. Two installed source hashes checked; raw/code audits report zero interior-stub operands. No forced extents or verifier waivers.
- Battle-royale setup6ed7d0 (4448B) models actual60B Group with selfHGroup/native Entity-member vector/native RGB3 vector, real external constructor/destructor and hidden HGroup factory adoption. Native Room108/Rect16/weighted36/grid12/string and Point/Entity/Item-vector owners preserve actual lifetime and cleanup. Actual getters, Point copy/assignment, int-range domain, item/Entity spawn, const-string rename and ignored bool activation interfaces are independently audited. Borrowed definition/cell views remain partial unsized records; allocating parsing/factories/spawn/mutation interfaces remain ordinary maythrow.
- Genuine budget loop chooses a new weighted item repeatedly, preserving retail conditional addition/subtraction; all actual helper/code proofs pass. The one explicitly marked zero-output if(0) allocator idiom follows AGENTS.md74, after retained genuine name/declaration/scope probes showed exactly four register differences. No extra object, fake helper, dead negation or guessed exception deletion. Native scalar count and outer ItemDef pointer scope, separate release name-load/size checks and string cleanup retain retail behavior. Range min/max and true16B Rect shuffle strides have positive downstream evidence.
- Parts trigger895020 (5746B) allocates actual native Console108/Part164/Cycle112/Modal112/Exoskeleton120 owners with external real constructor/destructor lifecycles and parent child-vector adoption. Part secondary HItem metadata is positively recovered from native Itempool inventory pointer comparisons and Marker8/10 writes; retained pointer-transfer/error branches and vector<vector<Marker*>> cleanup match original ownership. Actual cache/count scalars and typed child references are declared; no padded allocated extent. Exoskeleton counters derive from its real renderer.
- Trigger is true Console slot11(conststring&,int), ordinary refresh890710 void(bool), genuine unsigned-count/signed-value integer fill, four-int slot sum and read-only handle/pool/count predicates. Native strings/Point/HI temporaries and repeated independent header macro scopes preserve lifetimes. All allocation/formatting/UI/refresh/error interfaces maythrow. Borrowed Parts/Marker prefixes are never allocated. No target switch-table masking or added helper code.

## Previous verified checkpoint (2026-10-08, twenty-third source batch)

- **12,894 / 13,016 game functions; 53.513% code matched.** Two unique matches add10,116 bytes over `0a5a4c6`; 122 functions remain. Code totals: 3,514,054 / 6,566,759 bytes.
- **32,229 / 32,229 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_23.log`, full candidate gate `build/manager_loop_source_lvx_23.log`, registered proof `build/manager_loop_source_registered_23.log`. Two installed source hashes checked; raw/code audits zero executable interior-stub operands. Explicit `build/manager_loop_source_critical_23.log` also proves both transitively reachable native string replace overloads9afac0/9bb440 MATCH in full context: isolated82/84 discrepancy is not waived.
- Game-over TU repair retains all thirteen old bodies while adding update7bc900 (4972B). Actual Console96/108 hierarchy/Buffer12/Cell20/native child-vector owners, ConsoleArt132 and CArtAnimated136 with actual AsciiImage16B vector/Point offset/borrowed Def* are declared with real external lifecycles. Parent adopts new Console/EndingText; martyr vector holds borrowed aliases and deletes through actual parent removal before native vector erase. Native strings/grid/weighted-vector lifetimes and old dispatch tables are retained.
- Genuine noarg Engine Effect factory followed by bool initializer replaces unsupported old stack bridges at three actual-use sites. Borrowed definition lookup uses Def**, native animation vectors/close animation use Def*, and optional Point pointers remain distinct from mandatory Point references. Actual Sound result/unsigned identifier, Generator byte flags/fullint final parameter, Stats unsigned index, Graph byte flag and scoresheet bool remain coherent. Achievement-count unsigned is only a native-size compatible view, not uniquely recovered original signedness. Known Point type is unified across global-coordinate view and full-expression copy construction; no assignment into uninitialized storage or opaque allocated owner. No extra unique credit for existing repairs/covered helpers.
- Machine-target trigger8fbb70 (5144B) overrides native Console slot11. Borrowed Item/Prop handles resolve actual pools and native ItemDef/EntityDef/PropData pointers; stored label is genuine native string owner. Conditional string references/literal conversion, iterator erase/insert, highlight markers, truncation, repeated real Point temporaries and percent-tier effect rendering preserve retail. Engine retains allocated Effect ownership; factory/initializer/string operations remain ordinary maythrow. Actual scalar leaves have downstream raw proof. Genuine trailing tables5016..5144 retained.

## Previous verified checkpoint (2026-10-08, twenty-second source batch)

- **12,892 / 13,016 game functions; 53.359% code matched.** Three unique matches add14,298 bytes over `71ee101`; 124 functions remain. Code totals: 3,503,938 / 6,566,759 bytes.
- **32,227 / 32,227 comparisons MATCH, zero DIFF.** Serialized full compile/link `build/manager_loop_source_full_22.log`, full candidate gate `build/manager_loop_source_lvx_22.log`, registered proof `build/manager_loop_source_registered_22.log`. Five installed source hashes checked. Raw/code audits report zero executable interior-stub operands. No forced extents or verifier waivers.
- World population6dfdb0 (4345B) and6e3c30 (4484B) retain native36B weighted sets with typed definition/talk pointers, actual native strings/Point/Area/vector owners, true Entity/location/group domains, spawn and const-string rename interfaces. Borrowed exits are vector<Exit*> with4B pointer stride; pathfinding uses actual Entity*/unsigned* optional outputs and follow takes a fullint. Native conditional Area selection, RNG and retail cross-collection removal sequence are preserved. Read-only lookup qualification is a bounded compatible private view, not uniquely recovered original constness. Allocating/spawn/dialogue/UI calls remain ordinary maythrow.
- Parts swap89adf0 (5469B) uses true native Console hierarchy and allocated32B Phrase owner with actual external lifecycle and immediate message adoption. Both primary and secondary handles have positive Item-pool provenance; native snapshot vectors own their backing arrays, while Parts/Items remain borrowed. Real full-expression optional string lifetimes, multi-slot adjacency, removal/reinsertion and secondary row refresh preserve retail. Fresh removal proof confirms byteflag, fullword index andret12; complex formatting/allocation/refresh remain ordinary.
- Old op_x4a repair retains all four previously mapped bodies (2886B) with genuine int(HItem,bool3) labels, two Entity/three optional string message interface, correctly typed unequip, int-reference erase, unsigned move and actual borrowed Part* plus byte flag. No additional unique credit or global caller cleanup claim.
- Corrected exactly one false `std::string::operator+=` mapping in op_r6 at a01da0 to its genuine compiler-generated native16B iterator subtraction forwarder; true string append9af3d0 in cc_prop remains registered. Covered const-base subtractiona01de0 is also registered. Actual pooled-record semantics remain unknown: the Area declaration witnesses borrowed arithmetic, not a vector allocation/element-owner claim. The genuine two-Point Area copy chain is positively traced; no handwritten helper body. Both aliases add zero unique functions/bytes. Candidate comparison removes the erroneous name and restores its true canonical append row before checking the complete mapping set.

## Previous verified checkpoint (2026-10-08, twenty-first source batch)

- **12,889 / 13,016 game functions; 53.141% code matched.** Three unique matches add14,000 bytes over `120127f`; 127 functions remain. Code totals: 3,489,640 / 6,566,759 bytes.
- **32,222 / 32,222 comparisons MATCH, zero DIFF.** Full compile/link `build/manager_loop_source_full_21.log`; candidate gate `build/manager_loop_source_lvx_21.log`; registered proof `build/manager_loop_source_registered_21.log`. Three installed source hashes checked. Raw/code audits `build/manager_loop_source_audit_21.log` and `build/manager_loop_source_code_audit_21.log` report zero executable interior-stub operands; genuine target switch tables stay within verified extents.
- Assimilation handler retains complete112B CEffect owners over true96/108B Console hierarchy, native child/effect vectors and typed20B Cell buffer, actual eight conditional UI captures and parent ownership. Real mutablePoint copy and optionalRect, mandatory writable range outputs, fullwidth sound result, hidden native string/Point/Color returns and repeated visibility conditions preserve retail lifetimes. Complex allocation, animations, reveal, Cell queries and UI mutations remain ordinary may-throw.
- Part status update creates actual124B HitChance owner with complete108B Console and native16B factor-vector owner. Actual Item/Entity pools, Game object receiver, borrowed Hud* factory return, fullinteger blend flag/sound result, followers vector<HEntity>, optional Point-vector output/integer range input and writable Point output reference are audited through actual callees. Native geometry/color copy and constructor/EH lifetimes preserve retail; allocating formatting/removal/refresh paths remain ordinary. Five real dispatch/index tables occupy4560..4720, not executable helper operands.
- Info label handling uses actual int(int,HEntity,stringbyvalue,intkind), real owned parameter/string/native vectors, optional vector<float>/bool outputs and actual weapon-list bool return. Nested rows use genuine unsigned integral-template assign(2u,0u), independently distinct from six-count const-int-ref rows. Real unused Point vector construction is observed retail. Stylekind enters Console108/Timer52 creation while expiry is separately fixed tick+1000. Three genuine double-to-float storage warnings preserve retail x87 evaluation. Borrowed partial Map/grid/label views are never allocated; true switch tail4576..4620 remains verified.

## Previous verified checkpoint (2026-10-08, twentieth source batch)

- **12,886 / 13,016 game functions; 52.928% code matched.** Five unique matches add21,180 bytes over `6360b33`; 130 functions remain. Code totals: 3,475,640 / 6,566,759 bytes. Two already-covered Command destructor aliases receive no unique credit.
- **32,219 / 32,219 comparisons MATCH, zero DIFF.** Full compile/link `build/manager_loop_source_full_20.log`; full candidate gate `build/manager_loop_source_lvx_20.log`; registered proof `build/manager_loop_source_registered_20.log`. Six installed source hashes checked. Raw and code-aware audits `build/manager_loop_source_audit_20.log` and `build/manager_loop_source_code_audit_20.log` cover five new functions, two aliases and the older scan repair, with no executable interior-stub operands.
- Projectile impacts preserve genuine scoped native strings and executed common terrain-damage flow. Actual main void(Entity,Impact*,Point&,bool), fourteen-slot integer damage return, typed Weapon/Explosion/Records pointers, byte flags, cached player status and rechecked target lifetime are audited through actual callees. Native borrowed grids and Point references retain real lifecycle; ordinary allocating message/death/damage paths remain may-throw.
- Entity labels use true Entity focus and byte flags, real native handle/Point/borrowed-console vectors, nested native integer cost rows and actual count/reference assign(6u,0). Borrowed scan prefix is explicitly incomplete while actual external indexing uses20B stride. Actual group members+c/pool230 and Entity cells+30, separate direction columns, hidden-result Point/Item values, real text/label creation and owner destruction scopes are proven; no allocated partial owner or folded-symbol type inference.
- Edge label placement uses true borrowed Timer type0/Console4/Point28 proven by ctor499e00, native Timer-pointer backing and four owned Point interval vectors. No local Timer/Console deletion. Real96/108B Console hierarchy, typed20B Cell buffers, hidden8B Point and byvalue3B Color, native unsigned-reference erase9ce6d0, genuine scan goto, interval endpoints and panel clipping reproduce retail. Allocating and mutating interfaces retain ordinary exceptions.
- Keyboard initialization uses actual176B native ifstream, native strings/vectors, allocated48B Command and44B Binding owners. External constructors/copy and real shift/ctrl field ordering are proven. Genuine empty Command destructor has actual implicit string cleanup; compiler deleting wrapper is byte-matched as covered alias. Real executed temporary Command copy/set/delete, manager adoption, parsed-file local scopes and stream virtual-base destruction remain. No fake owning surrogate or forced extent; prior guessed stream sizes are withdrawn.
- Video-mode setup retains actual SDL1.2 cdecl imports,20B event and8B Rect, real logging string owners and full-int JLog end return. Borrowed REX/FontSet/FontData views expose native string/vector members and true observed dimensions; no partial view allocated. Genuine mode selection, sentinel handling, renderer branch, centering and event drain preserve retail, with ordinary exceptions.
- Existing team_b_35 scan repair replaces false label handle/int-flag declarations with Entity/Item/Prop byte-bool contracts, preloaded fake factory/init bridge with actual noarg Effect factory plus seven-argument bool initializer, integer lookup with Def**, optional string/Entity/Point message ABI and opaque Phrase blob with true32B Source-pointer/native-string owner. Main1612B remains MATCH without unique credit. All allocating paths ordinary; borrowed partial Map/World/Exit/Effect views are never allocated here.

## Previous verified checkpoint (2026-10-08, nineteenth source batch)

- **12,881 / 13,016 game functions; 52.605% code matched.** Three unique matches add12,659 bytes over `e9841c4`; 135 functions remain. Code totals: 3,454,460 / 6,566,759 bytes.
- **32,212 / 32,212 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_19_repaired.log`; candidate gate: `build/manager_loop_source_lvx_19_repaired.log`; registered proof: `build/manager_loop_source_registered_19.log`. Four frozen source hashes checked before commit. Raw and code-aware audits both report zero interior-stub operands: `build/manager_loop_source_audit_19_repaired.log`, `build/manager_loop_source_code_audit_19_repaired.log`.
- Machine content/override creates actual136B CText/156B Target/296B Shell owners, real native strings/vectors and externally declared lifecycle. Typed20B Cell buffer and true12 Console virtual ABI slots replace opaque pointer/void placeholders; unused private names remain explicitly inferred. Parent constructor registration owns newchildren, target-vector backing borrows pointers, Shell ctor publishes its actual global. True Prop handle/pool22c, fullwidth keys/timing and conditional strings preserve observed behavior. Directnew pointer insertion fixes genuine lifetime/frame source shape.
- Inventory reopen preserves actual modes0..5, borrowed Inventory prefix with native Item/tick histories, temporary native Item vectors/string lifetimes and parent-managed child removal. The initial combined gate exposed the unsigned timestamp helper mismatch; fresh signed native vector<int> history and direct int clock reference now call the actual9b9d30 helper, independently reviewed without casts or new operations. Original logs/draft preserved. Native int& erase-step, collect unsigned(vector<HItem>*), total int(int*) and borrowed EffectPair* interfaces are proven through actual callees. No partial Console/Inventory view is allocated. Genuine trailing24B switch table remains verified; scalar local names reproduce native frame ordering without padded temporaries.
- Sigix integration uses true incomingEntity/nativeItem inventory, complete112B CEffect owners/Console hierarchy/nativebuffers/children, parent-owned UIcaptures and actualeffects backing. Sevenor8 captures depend on inventorypanel. Real int(int) equipAll, boolItemequip, typedbooldefinition flag, mutablePoint copy, optionalRectpointer, byvaluePoint and full message/Fx pointer ABI are independently audited. Message/string/new/factory/marker/UI/nativeowner operations retain ordinary exceptions. Actual render is virtualslot7; no fake callback or helper bodies.
- Older turn-handler repair exposes genuine three-pointer-plus-allocator native owners, fixes labels int(HItem,bool,bool,bool), message sixthEntity, actualPoint& assignment and realint Xom event return. Allocating neighbors/select/entity/item movement/UI/event/Effect acquisition/init remain ordinary; independent review additionally proved pull71ef30 nativePoint-vector constructor/copy and Logend7b4f10→scroll nativechild new/insert/push, removing both false throw guarantees. Actual pure refresh/rotation/delay/companion destructor chains support narrow declarations. Existing3597Bturn/33Bpair constructor remain MATCH and earn no additional unique credit. Earlier drafts preserved, real RNGheader unchanged.

## Previous verified checkpoint (2026-10-08, eighteenth source batch)

- **12,878 / 13,016 game functions; 52.412% code matched.** Three unique matches add14,073 bytes over `35e4f35`; 138 functions remain. Code totals: 3,441,801 / 6,566,759 bytes.
- **32,209 / 32,209 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_18.log`; candidate gate: `build/manager_loop_source_lvx_18.log`; registered proof: `build/manager_loop_source_registered_18.log`. Three frozen installed hashes checked before commit. Raw and code-aware audits both report zero interior-stub operands: `build/manager_loop_source_audit_18.log`, `build/manager_loop_source_code_audit_18.log`.
- Mission input uses actual184B gzifstream owner, allocated32B Phrase containing borrowed definition pointer/owned native string, direct-new ownership transfer, actual nontrivial Point/Event copies and optional message string/Point pointers. Actual anchor74 is HEntity, proven through actor-follow pool/caller evidence; provisional Prop annotation retracted. Stream/save/load/GM/UI/message mutations retain ordinary exception contracts. Message7b1750 returns void; show793450 has actualbool return despite being ignored.
- Item descriptions append to caller-owned native string and three-byte RGB vector, preserving genuine utility failure/default branch, weapon modifiers, string temporaries and x87 float/double evaluation. Entity5d2150 baseline is fullinteger, not bool inferred from literalzero. The genuine float compound narrowing warning is documented; cast variants altered actual instruction evaluation and were rejected. No fake helpers/owner padding or source allocator idioms.
- Item labels use four real native local vectors (Items/borrowed Memory*/Points/borrowed consoles), six fullinteger score slots, native string, typed grids and52B memory records. Actual interface is int(HItem,bool,bool,bool), with factory mandatory Pointreference/borrowed record pointers. Actual View210 is HEntity, independently proven through CellEntity45d250/equality9b78e0/Entitypool9b6570 assignments; fresh corrected copy supersedes Item annotation. Real conditional Point lvalues and zero-score goto retain observed lifetimes/control. Genuine two trailing switch tables remain verified; documented leading break idioms are permitted inferred source shape.

## Previous verified checkpoint (2026-10-08, seventeenth source batch)

- **12,875 / 13,016 game functions; 52.198% code matched.** Inventory input adds 4,535 bytes over `72deedc`; 141 functions remain. Code totals: 3,427,728 / 6,566,759 bytes.
- **32,206 / 32,206 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_17.log`; candidate gate: `build/manager_loop_source_lvx_17.log`; registered proof: `build/manager_loop_source_registered_17.log`. Exact installed source hash checked before commit. Raw and code-aware audits both report zero interior-stub operands: `build/manager_loop_source_audit_17.log`, `build/manager_loop_source_code_audit_17.log`.
- Inventory input preserves actual event dispatch, six native Item-vector sorting scopes, borrowed player inventory and true local owners. The observed unused vector has a real constructor/destructor lifetime. Native96B XConsole/108B Console expose actual Buffer/children ownership; the112B ModeReport allocation uses its real external lifecycle. Optional Point pointers and two Entity handles in the Info API are distinguished from Item handles. Allocating operations retain ordinary exception contracts.
- Reverse sorting uses the actual unsigned byte field/local, rather than bool normalization inferred from initialization. Canonical erase-step helper takes int&, with four signed partition indices and ordinary unsigned container-size conversion. Independent review corrected the earlier unsigned-reference draft, preserved it in scratch, and re-proved the exact installation copy. Genuine jump/index tables stay within the verified function extent. No padded temporary, fabricated helper body or exception waiver.

## Previous verified checkpoint (2026-10-08, sixteenth source batch)

- **12,874 / 13,016 game functions; 52.129% code matched.** Four unique matches add 17,226 bytes over `ac8e39a`; 142 functions remain. Code totals: 3,423,193 / 6,566,759 bytes.
- **32,205 / 32,205 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_16.log`; candidate gate: `build/manager_loop_source_lvx_16.log`; registered proof: `build/manager_loop_source_registered_16.log`. Four frozen source hashes checked before commit. Raw and code-aware audits both report zero interior-stub operands: `build/manager_loop_source_audit_16.log`, `build/manager_loop_source_code_audit_16.log`.
- Four new TUs reconstruct inventory equip, shell manual rendering, cinematic effect updating and paused-shoot state handling. Inventory equip preserves real Item list owners, replacement selection, resources/confirmation, mimic factory/effect paths and native string cleanup. Effect503b20 is an actual void nine-slot API with mandatory Point references and optional target/payload/parent pointers; its Engine acquire returns an owned pooled effect. Definition lookup uses true borrowed pointer outputs and allocating calls retain ordinary exception contracts.
- Manual90a360 recovers the long-standing two-register near miss after genuine XConsole→Console hierarchy, ownership and callback repairs. Actual96B XConsole owns12B Cell grid/16B child vector;108B Console owns84B Engine and adopted child hierarchy. Native Buffer lifecycle is externally declared. The canonical mutable-string comparator and true sort iterator ABI are preserved. Actual discarded empty() remains, followed by the explicitly permitted AGENTS zero-output allocator idiom, marked in source and documented as inferred source shape. No emitted extra behavior or forced frame storage.
- Effect updating preserves real borrowed EffectDef pointers, Point/Bounds/RGB/Pixel lifetimes, native Point/grid owners and the original shake-timer precedence. Corrected installation copy uses actual nullable Rect pointer and externally declared native-grid lifecycle. Raw Cell byte getter and bool Map marking are distinguished. Its genuine trailing switch stays within the verified extent; no helper body or extent override.
- Paused-shoot state uses a distinct pooled record handle, actual124B Shoot owner fields, true two-Point Line/Item/undecoded collection owners, Map record collection and paused member. Real bool diagnostic ternaries reproduce normalization, while Point/name/value formatting creates actual owning strings. Pool removal uses actual virtual deletion and potentially allocating free-list mutation. Same-handle deletion and unconditional final assignment retain observed behavior. Explicit real owner lifecycle declarations supersede opaque implicit-lifecycle drafts without adding bodies.


## Previous verified checkpoint (2026-10-08, fifteenth source batch)

- **12,870 / 13,016 game functions; 51.867% code matched.** Five unique matches add 18,705 bytes over `2eb4dd4`; 146 functions remain. Code totals: 3,405,967 / 6,566,759 bytes.
- **32,201 / 32,201 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_15.log`; candidate gate: `build/manager_loop_source_lvx_15.log`; registered proof: `build/manager_loop_source_registered_15.log`. Six frozen source hashes checked before commit. Raw and code-aware audits both report zero interior-stub operands: `build/manager_loop_source_audit_15.log`, `build/manager_loop_source_code_audit_15.log`.
- Five new TUs reconstruct evasion modifiers, HUD rendering, adjacent-map attack/conversion, collision/movement confirmation and UFD area updates. Native string/Point/RGB lifetimes, true16B allocator-backed owners,20B packed-bit owner/8B bit proxies and12B owning integer grid preserve actual behavior. Genuine evasion switch trailers remain within their verified extent. HUD conditional color lvalues generate the actual reference temporary without dummy storage, and retain the retail ignored toupper result.
- New Shoot/AI allocation views expose every known native collection owner instead of opaque extent blobs. Shoot124B contains genuine16B two-Point Lines, Item owner44 and actual Entity targets; AI304B exposes its known Point/remembered-Entity/target/order ownership. Undecoded element types remain incomplete private types. Real external constructors/destructors retain ordinary exception contracts; no helper body or forced padding. Factory effect-record handles remain distinct from Entity/Item handles and establish actual transfer ownership.
- Downstream ABI audits corrected ignored show793450 to bool, true Group getter index/change bool slots, borrowed native entity-list reference and Point-copy return. Movement speed5d15a0 notification argument is bool: its only three reads are byte loads, supported by canonical caller declarations. Original evasion int/zero inference was superseded by fresh bool/false proofs. UFD updates distinguish no-argument Engine acquire from bool Effect initialization with mandatory dimensions Point reference, optional target pointers and full integer draw flags. Original draft pointer/void guesses were corrected before installation.
- Older5111e0 wrapper now uses its actual three optional native-string pointers and two Entity handles, plus the true40B Source*/owned-string/row/turn message owner. Constructor→text expansion→Entity name resolution and downstream message insertion prove these contracts beyond forwarding-only bytes. Real temporary strings and transferred messages preserve cleanup. The sixth parameter's old cosmetic name remains limited terminology; its actual type is corrected. Fresh isolated591B MATCH and independent review preceded this combined gate.

## Previous verified checkpoint (2026-10-08, fourteenth source batch)

- **12,865 / 13,016 game functions; 51.582% code matched.** Two unique matches add 6,287 bytes over `7f779b2`; 151 functions remain. Code totals: 3,387,262 / 6,566,759 bytes.
- **32,196 / 32,196 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_14.log`; candidate gate: `build/manager_loop_source_lvx_14.log`; registered proof: `build/manager_loop_source_registered_14.log`. Two frozen source hashes checked before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_14.log`, `build/manager_loop_source_code_audit_14.log`).
- New TUs reconstruct timed cinematic effects and adjacent-entity map actions. Cinematic effects preserve the actual36B weighted owner, parent-adopted112B effect and132B art child with owned16B image and Point. Lookup returns a borrowed EffectDef pointer through a real pointer output; downstream initialization dereferences that definition. The original integer annotation was corrected before installation and fresh exact-source standard/alias proofs passed. Mutable erase iterators, owning replacement strings and actual bool text processor retain real lifetimes and ordinary exception contracts.
- Map actions preserve Entity/Item/Prop handles, borrowed position reference and true Point value temporaries, native16B Item collection, shared genuine case counters and message-route three string pointers/two Entity handles. Downstream grid/group/option reads support leaf exception annotations; mutations/string/owner operations remain potentially throwing. Raw attack condition accepts !solid. Final register allocation uses the explicitly permitted AGENTS empty if(false) idiom, marked in source: it emits zero code, and two ordinary scopes left only eight register differences. It is documented as an inferred compiler technique, not claimed original source text.

## Previous verified checkpoint (2026-10-08, thirteenth source batch)

- **12,863 / 13,016 game functions; 51.486% code matched.** Seven unique matches add 25,914 bytes over `8036f43`; 153 functions remain. Code totals: 3,380,975 / 6,566,759 bytes. Nine genuine helper aliases add comparisons at previously covered addresses only.
- **32,194 / 32,194 comparisons MATCH, zero DIFF.** Expanded corrected full compile/link: `build/manager_loop_source_full_13_repaired.log`; candidate gate: `build/manager_loop_source_lvx_13_repaired.log`; registered proof: `build/manager_loop_source_registered_13.log`. Seven frozen source hashes checked before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_13_repaired.log`, `build/manager_loop_source_code_audit_13_repaired.log`). Earlier four-source gate passed32,186 comparisons; expanded final proof supersedes it.
- Seven new TUs reconstruct Entity construction, WAR-area population, gallery construction, map comment rendering, hacking-window setup, log bubbles and message insertion. Actual native strings, Point/Rect/Area values, owned collections and parent-adopted child consoles preserve observed lifetimes. Definitions and metadata stay borrowed. Gallery binds the real comparator, actual sound ABI and two-string column stride. Comment rendering distinguishes no-argument Engine acquisition from seven-argument Effect initialization.
- Native VS2010 release collection layout is established by actual constructor and accessors: first/last/allocated-end pointers at0/4/8 plus the native empty allocator at+c, naturally aligned to16B. Final corrected views use typed pointers and real allocator members without invented proxy or padding. Two such owners plus total form actual36B weighted tables. Genuine eight-byte EffectType-pointer/integer pairs and distinct owned RecordNode versus borrowed RecordDef types recover the Entity constructor; complete pair/copy/EC helper bodies independently MATCH. Actual constructor-body inference preserves genuine new-result slots.
- Unsupported throw guarantees were removed from allocating name-code, string padding, effect insertion, weights construction, stream parsing and Engine acquisition. Fresh exact-copy proofs preserve ordinary exception contracts. Nonallocating allocator-copy/zero-store vector construction and trivial field/handle getters retain evidence-supported leaf contracts. Absence of local EH does not establish nothrow.
- Complete message construction/text-expansion audit establishes three optional string pointers and two Entity handles. Message insertion uses that actual route ABI and a genuine copy constructor which default-constructs its own empty text while copying metadata, row and turn. Actual Source*0/string4/row20/turn24 layout corrects the bubble grouping-field name. Native += expression boundaries preserve real shared helpers. Hacking setup uses true bool bubble argument, actual16B machine-hacking constructor, borrowed inventory values and optional Rect pointer. No fake helper body, forced extent or verifier exemption.

## Previous verified checkpoint (2026-10-08, twelfth source batch)

- **12,856 / 13,016 game functions; 51.092% code matched.** Seven unique matches add 30,509 bytes over `ac28630`; 160 functions remain. Code totals: 3,355,061 / 6,566,759 bytes.
- **32,178 / 32,178 comparisons MATCH, zero DIFF.** Expanded corrected full compile/link: `build/manager_loop_source_full_12_repaired.log`; candidate gate: `build/manager_loop_source_lvx_12_repaired.log`; registered proof: `build/manager_loop_source_registered_12.log`. Eight frozen source hashes checked before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_12_repaired.log`, `build/manager_loop_source_code_audit_12_repaired.log`).
- Seven new TUs reconstruct item status suffixes, equipment generation, HTTP news retrieval, analysis popup rendering, item removal, projectile deflection and Polymind information refresh. Native string/Point/Area/handle lifetimes and real collection ownership preserve observed behavior. News retrieval retains the retail early-return socket behavior and genuine mutable-to-const erase iterator conversion; this static reconstruction does not execute network requests.
- Older `cc_r2_10.cpp` correction changes the fixed-damage wrapper's third value from three-byte color to integer and its damage callee's final borrowed pointer to integer. The actual wrapper takes the integer argument's address, the damage callee reads its full DWORD, and the sole explosion caller forwards a full integer. Exact corrected older-TU isolated proof passed; all prior registrations pass the combined gate.
- Complete message constructor/buildText/entity-expander audit confirms three optional string pointers and two Entity handles. Corrected equipment/removal installation copies use the actual second Entity handle and real default constructor. The proposed integer fourth slot was disproved by downstream string dereference and was never installed. The removal Xom event helper takes two integers and float, returning integer status; literal false/ignored return had masked the original incorrect bool/void annotations. Raw contracts and exact-copy standard proofs support both repairs.
- Analysis popup uses actual external sixteen-byte string-owner operations instead of generating a conflicting shared string-copy helper; no fabricated body or verifier exemption. Its actual child Console is deleted through the parent removal API before creating the final analysis window. Polymind frame rendering takes a nullable Rect pointer, real three-byte RGB and two booleans; its genuine switch byte/pointer tables and child-console layout are independently reviewed.

## Previous verified checkpoint (2026-10-08, eleventh source batch)

- **12,849 / 13,016 game functions; 50.627% code matched.** Nine unique matches add 32,920 bytes over `e5f1f98`; 167 functions remain. Code totals: 3,324,552 / 6,566,759 bytes. Five genuine helper aliases at previously covered addresses add comparison rows only.
- **32,171 / 32,171 comparisons MATCH, zero DIFF.** Repaired full compile/link: `build/manager_loop_source_full_11_repaired.log`; candidate gate: `build/manager_loop_source_lvx_11_repaired.log`; registered proof: `build/manager_loop_source_registered_11.log`. Eleven frozen source hashes checked before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_11_repaired.log`, `build/manager_loop_source_code_audit_11_repaired.log`).
- Nine new TUs reconstruct Prop damage, item turn effects, news parsing, a result row constructor, Cell explosion response, map labels, record details, collision response and Parts updating. Native string/Point/handle ownership and actual nullable pointer contracts are preserved. Genuine news/effect-pair constructors use their actual bodies and compiler-inferred nothrow behavior; no fabricated storage or helper body is introduced.
- Initial full-context candidate gate exposed the old news callback placeholder and a shared type-code insertion binding. The old callback now names the actual `int(void*)` news body. The map-label type-code collection uses its actual sixteen-byte owner and external lifecycle/insertion functions, preserving buffer ownership and cleanup. Earlier failed diagnostics remain in `build/manager_loop_source_lvx_11.log`; repaired full and registered gates pass every prior match.
- Obliterator declarations now reflect actual bool, pointer, handle and integer arguments; literal call values retain identical machine code. Removed two incorrect const-char string-assignment metadata rows at `0x9af370` and `0xa00550`: raw bodies are string-copy assignment and iterator forwarding. Actual const-char assignment at `0x9af390` passed all32,157 prior comparisons in a pre-cleanup override probe (`build/manager_loop_cstr_correct_11.log`); the final combined gate validates canonical ordering.

## Previous verified checkpoint (2026-10-08, tenth source batch)

- **12,840 / 13,016 game functions; 50.126% code matched.** Four unique matches add 13,124 bytes over `2de1bfa`; 176 functions remain. Code totals: 3,291,632 / 6,566,759 bytes. Verified code coverage has passed fifty percent.
- **32,157 / 32,157 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_10.log`; candidate gate: `build/manager_loop_source_lvx_10.log`; registered proof: `build/manager_loop_source_registered_10.log`. Four frozen source hashes verified before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_10.log`, `build/manager_loop_source_code_audit_10.log`).
- Four new TUs reconstruct Exiles incidents, core-damage aftermath, multi-goal pathfinding and obliterator response. Corrected installation copies use the actual chase record-pointer return/int/bool-pointer arguments and canonical RNG declaration. Path callback cost output is an integer reference; its mutable goal/output vectors and bool return are established by all five wrapper callers. Existing raw wrapper source remains untouched and its direct relative-call binding passes the full gate.
- A subsequent Prop audit identifies the obliterator damage helper's first/third slots as bool rather than the current opaque int annotations. This caller passes literal zero in both slots, so emitted argument bits and the verified callee ABI already agree; a type-only installation correction is queued for fresh isolated proof and the next full build. Current commit preserves the exact frozen source of this all-MATCH artifact.

## Previous verified checkpoint (2026-10-08, ninth source batch)

- **12,836 / 13,016 game functions; 49.926% code matched.** Nine unique matches add 29,020 bytes over `633d885`; 180 functions remain. Code totals: 3,278,508 / 6,566,759 bytes.
- **32,153 / 32,153 comparisons MATCH, zero DIFF.** Repaired full compile/link: `build/manager_loop_source_full_09_repaired.log`; candidate gate: `build/manager_loop_source_lvx_09_repaired.log`; registered proof: `build/manager_loop_source_registered_09.log`. Nine frozen source hashes verified before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_09_repaired.log`, `build/manager_loop_source_code_audit_09_repaired.log`).
- Nine new TUs reconstruct teleport navigation, priority-frontier path search, hauler display, map-path initialization, item firing, scroll adjustment, Xom updates, AI commentary and transmission display. Real handle/Point/string lifetimes, borrowed record pointers and shared RNG declarations retain observed ABI. Corrected map-path definitions use pointer identity; corrected firing constructor uses the actual final item handle. Exact corrected installation copies have fresh standard proofs.
- Initial six-source candidate gate passed all32,150 comparisons, but raw/code audits caught scroll direction Y loads at stub+4. The actual initializer confirms eight interleaved two-int records; separate borrowed X/Y column views retain eight-byte stride at real bases `0xd015d8`/`0xd015dc`. No table changes, fabricated extent, verifier exemption or instruction padding. Frozen repair passed isolated/alias/operand checks and the repaired full build. Earlier diagnostics remain in `build/manager_loop_source_lvx_09.log` and candidate audit logs. The hauler shared string-copy constructor discrepancy from isolation resolves in the full-context gate; every previous registration passes.

## Previous verified checkpoint (2026-10-08, eighth source batch)

- **12,827 / 13,016 game functions; 49.484% code matched.** Six unique matches add 18,327 bytes over `310cdfa`; 189 functions remain. Code totals: 3,249,488 / 6,566,759 bytes.
- **32,144 / 32,144 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_08.log`; candidate gate: `build/manager_loop_source_lvx_08.log`; registered proof: `build/manager_loop_source_registered_08.log`. Six frozen source hashes verified before commit. Raw 4 KiB-slot and code-aware audits report zero interior-stub operands (`build/manager_loop_source_audit_08.log`, `build/manager_loop_source_code_audit_08.log`).
- Six new TUs reconstruct Cell terrain destruction/trap activation, bomb and escort map handlers, depth rendering and item-label formatting. Real handle/Point/string lifetimes, collection ownership and shared RNG declarations retain observed ABI. Corrected message-routing declarations identify actual optional string pointers; their exact installation sources passed fresh joint standard proof before freezing.

## Previous verified checkpoint (2026-10-08, seventh source batch)

- **12,821 / 13,016 game functions; 49.205% code matched.** Sixteen unique matches add 39,342 bytes over `b53dbdf`; 195 functions remain. Code totals: 3,231,161 / 6,566,759 bytes. A genuine mutable string-iterator subtraction alias at an already mapped address adds the seventeenth row without counting its bytes twice.
- **32,138 / 32,138 comparisons MATCH, zero DIFF.** Final full compile/link: `build/manager_loop_source_full_07_final.log`; candidate gate: `build/manager_loop_source_lvx_07_final.log`; registered proof: `build/manager_loop_source_registered_07.log`. All sixteen frozen source hashes verified before commit. Raw 4 KiB-slot and code-aware audits both report zero interior-stub operands (`build/manager_loop_source_audit_07_final.log`, `build/manager_loop_source_code_audit_07_final.log`).
- Sixteen new TUs reconstruct configuration filtering, the naturally generated Sound deleting helper, text input, squad-map display, effect initialization/update, manual construction, AI chase/reinforcement, parts swapping/removal, item targeting, layout generation, dialog display, ambient sound and map access. Partial layouts and private semantic names remain explicitly inferred. Real string/container lifetimes and shared RNG declarations preserve observed ABI.
- Initial combined gates caught configuration iterator temporary lifetime and two shared opaque-pointer insertion identities. The final configuration binding refers directly to the actual mutable iterator temporary through its const-iterator base; Comm/PartsSwap use private sixteen-byte collection views with the actual const-reference pointer-slot insertion ABI. No fabricated helper body or verifier/boundary change. Earlier failed diagnostics are retained in `build/manager_loop_source_lvx_07.log` and `_07_repaired.log`; every previously registered body survives the final link.
- Removed the shadowed bad_alloc deleting-helper row at `0x9e7060` from `op_h.csv`: its later canonical row at `0x4013c0` already superseded it. Exact effective mapping dictionaries compare equal before and after removal (`scratch/manager_loop/shadow_alias_cleanup_07.json`). The genuine generated Sound deleting helper is now registered at `0x9e7060`.

## Previous verified checkpoint (2026-10-07, sixth source batch)

- **12,805 / 13,016 game functions; 48.606% code matched.** Three unique matches add 7,374 bytes over `a03e9d2`; 211 functions remain. Code totals: 3,191,819 / 6,566,759 bytes.
- **32,121 / 32,121 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_06.log`; candidate gate: `build/manager_loop_source_lvx_06.log`; registered proof: `build/manager_loop_source_registered_06.log`. Frozen three-file hashes verified before commit. Raw 4 KiB-slot and code-aware candidate audits report zero interior-stub operands (`build/manager_loop_source_audit_06.log`, `build/manager_loop_source_code_audit_06.log`).
- Three new TUs reconstruct the protected AsciiImage loader, effect initialization and service dispatch. The image loader uses the genuine gzip-stream and MT headers; a const-reference pointer binding preserves the actual temporary before insertion into a private opaque view of the canonical `vector<XBuffer*>` layers. No inheritance or volatile storage was invented. The effect initializer preserves all three switch tables; service dispatch retains actual float data operands, handle ABI and EH lifetimes.

## Previous verified checkpoint (2026-10-07, fifth source batch)

- **12,802 / 13,016 game functions; 48.493% code matched.** Eleven unique matches add 24,269 bytes over `ad8b02d`; 214 functions remain. Code totals: 3,184,445 / 6,566,759 bytes.
- **32,118 / 32,118 comparisons MATCH, zero DIFF.** Repaired full compile/link: `build/manager_loop_source_full_05_repaired.log`; candidate gate: `build/manager_loop_source_lvx_05_repaired.log`; registered proof: `build/manager_loop_source_registered_05.log`. Frozen source hashes verified before commit.
- Ten new TUs reconstruct score upload/re-upload, Discord queue processing, effect expansion/placement/dispatch, exoskeleton rendering, drag/drop input, lore selection and Cogshop refresh. An unchanged existing iterator forwarding body contributes the eleventh registration. Genuine gzip-stream and shared RNG declarations preserve known ABI; private layouts and aliases remain identified in source.
- `team_a_23.cpp` and `team_c_32.cpp` callback references now take the actual Discord/upload implementation addresses. The initial candidate gate caught two placeholder callback operands (`build/manager_loop_source_lvx_05.log`); both repaired callers and all prior registrations pass. Discord preserves the existing thread helper prototype with a pointer-width callback cast.
- Raw 4 KiB-slot audit flags one apparent operand at effect-placement +0xae7 inside its trailing switch table (`build/manager_loop_source_audit_05_repaired.log`). The verifier independently validates all eleven table entries; its identified table starts at +0xad4. A supplementary scratch audit using those verified code/table boundaries finds **zero executable-code interior-stub operands** (`build/manager_loop_source_code_audit_05_repaired.log`). No repository verifier or boundary overrides.

## Previous verified checkpoint (2026-10-07, fourth source batch)

- **12,791 / 13,016 game functions; 48.124% code matched.** Five unique matches add 11,262 bytes over `3665981`; 225 functions remain. Code totals: 3,160,176 / 6,566,759 bytes.
- **32,107 / 32,107 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_04.log`; candidate gate: `build/manager_loop_source_lvx_04.log`; registered proof: `build/manager_loop_source_registered_04.log`. Candidate audit reports zero interior-stub operands with 4 KiB slots (`build/manager_loop_source_audit_04.log`). Frozen five-file hashes checked before commit.
- Four new TUs reconstruct two inventory replacement selectors, phrase routing and EntityAI construction. Private typed aliases retain actual comparison directions, fallback nesting, hidden handle-return ABI, object fields and member cleanup. The AI constructor uses the shared RNG declaration to pair named operands correctly.
- `op_q4a_hud.cpp` change renames locals only in six CEvasionFull trigger branches to restore MSVC stack-slot ordering. Calls, arguments, strings, condition order and the total branch are unchanged; all other registered functions pass.

## Previous verified checkpoint (2026-10-07, third source batch)

- **12,786 / 13,016 game functions; 47.952% code matched.** Eight unique matches add 10,419 bytes over `347479e`; 230 functions remain. Code totals: 3,148,914 / 6,566,759 bytes.
- **32,102 / 32,102 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_03.log`; candidate gate: `build/manager_loop_source_lvx_03.log`; registered proof: `build/manager_loop_source_registered_03.log`. Candidate audit reports zero interior-stub operands with 4 KiB slots (`build/manager_loop_source_audit_03.log`). Frozen eight-file hashes checked before commit.
- Seven new TUs reconstruct cave generation, CList construction, sensor detection, text marker replacement, group removal, message routing, and lore-list scrolling. The group-removal body only calls the reserved Overmind helper; it does not implement or alter reserved code.
- `op_v3e.cpp` change restores the actual local AchievementDef pointer in the achievement sorter at `0x7f1120`. Its existing body and all other registered functions pass the combined gate. Original callback/type declarations remain intact.

## Previous verified checkpoint (2026-10-07, second source batch)

- **12,778 / 13,016 game functions; 47.794% code matched.** Ten new unique matches add 6,277 bytes over `71d1e5f`; 238 functions remain. Code totals: 3,138,495 / 6,566,759 bytes.
- **32,094 / 32,094 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_02.log`; candidate gate: `build/manager_loop_source_lvx_02.log`; registered proof: `build/manager_loop_source_registered_02.log`. Candidate audit reports zero interior-stub operands with 4 KiB slots (`build/manager_loop_source_audit_02.log`). Ten-file frozen snapshot hashes checked before commit.
- Nine new TUs reconstruct ArenaString allocation, cropped console alpha copy, local danger, restoration, sound attenuation, explosion bounds, Xom decisions, prop marking, and achievement entry construction. The private Xom and prop-mark implementations resolve the two full-link EH mismatches deferred in the prior source batch.
- `global_strings.cpp` correction changes `gameString_d34d1c` from scalar to a one-element string array. The actual array destructor at `0xb5e770` and existing initializer at `0xb51cb0` both MATCH in the combined link; source storage remains 28 bytes. No duplicate global or synthetic cleanup wrapper.

## Previous verified checkpoint (2026-10-07, descriptor metadata correction)

- **12,768 / 13,016 game functions; 47.698% code matched.** Two existing protobuf descriptor helpers add 206 matched bytes over `31141cc`; 248 functions remain.
- **32,084 / 32,084 comparisons MATCH, zero DIFF.** Candidate gate and registration-order proof: `build/manager_loop_descriptor_gate_01.log`, `build/manager_loop_descriptor_registered_01.log`. The candidate audit reports zero interior-stub operands with 4 KiB slots (`build/manager_loop_descriptor_audit_01.log`). Uses the already verified combined artifact; no source changes.
- Removed 209 inherited false descriptor aliases from `lead_discovered.csv`, retaining the real MapType getter at `0x4dbda0`. The comparison count falls because aliases are removed; matched function counts retain one address per function. Retail serialized schema order, table bases, getter bytes, and MAP_ caller lookups establish this identity. Zero-initialized table entries had allowed shifted getter loads to appear equal. See `docs/descriptor-alias-audit.md` and local detailed proofs in `scratch/loop_alpha_02/`.
- Registered `protobuf_AssignDescriptors` at `0x4dbc40` and `AddDescriptorsImpl` at `0x4dbd20` after the cleanup gate proved the actual enum table (`0xceca80`) and message metadata table (`0xcecab0`) pairings. No schema or verifier changes.

## Previous verified checkpoint (2026-10-07, combined source batch)

- **12,766 / 13,016 game functions; 47.695% code matched.** This checkpoint adds 17 unique matches and 4,497 matched bytes over `91ac2fd`; 250 functions remain. Three additional rows are genuine constructor/destructor aliases at previously mapped addresses.
- **32,291 / 32,291 comparisons MATCH, zero DIFF.** Full compile/link: `build/manager_loop_source_full_01.log`; retained candidate gate: `build/manager_loop_source_lvx_01_retained.log`; registered proof: `build/manager_loop_source_registered_01.log`. Candidate audit reports 4 KiB slots and zero matching rows with interior-stub operands (`build/manager_loop_source_audit_01_retained.log`). The four verifier regression checks passed.
- Eleven new translation units reconstruct record construction with real private unsigned-vector array callbacks, ambient source collection, line obstruction, item destruction, AI reset, bit-vector insertion, sort/insertion wrappers, and protobuf once/static helpers. The existing Point range formatter is registered through its actual demangled symbol. Private aliases resolve the previously deferred `0x46ef00`, `0x4ff4c0`, and `0x9c35b0` full-link mismatches without editing earlier sources.
- Two proven non-prologue successor helpers (`0xb5c720`, `0xb5c8d0`) add genuine indexed starts and separate two once initializers. The function denominator increases by two and 26 bytes of inter-function padding leave the code denominator. No verifier/index overrides were introduced. Optimized retail protobuf helper bodies use scoped optimize pragmas, reset at each new TU's end.
- Deferred registrations: existing `OpS4_Xom::unknown69e700` and `BS::opw3_unknown729bc0` gain EH frames in the combined link; existing `gameString_d34d1c` cleanup compiles as a direct destructor instead of the retail array cleanup helper. Their rows were excluded and the entire retained gate rerun; original sources remain intact. Initial diagnostic gate: `build/manager_loop_source_lvx_01.log`.

## Previous verified checkpoint (2026-10-07, existing-source helpers)

- **12,749 / 13,014 game functions; 47.626% code matched.** Four newly registered existing-source helpers add 1,031 bytes over `9ea69ef`; 265 game functions remain. The fifth row is a Point-constructor callback alias at an already-mapped address.
- **32,271 / 32,271 comparisons MATCH, zero DIFF**, using the prior verified full artifact. Candidate gate: `build/manager_loop_mapping_only_01.log`; registered proof: `build/manager_loop_mapping_only_01_registered.log`; audit: `build/manager_loop_mapping_only_01_audit.log` (4 KiB slots, zero interior-stub operands).

## Previous verified checkpoint (2026-10-07, second batch)

- **12,745 / 13,014 game functions; 47.611% code bytes matched.** This batch adds **30 unique game-function matches and 4,107 matched bytes** over `29dec04`. **269 game functions remain unmatched.** Counts exclude library functions and do not count mapping aliases twice.
- **32,266 / 32,266 registered comparisons MATCH, zero DIFF.** Two serialized full builds checked the combined sources, then the retained source after a failing draft was returned to scratch. Candidate gate: `build/manager_oct08_final_lvx.log`; registered verification: `build/manager_oct08_registered.log`; final compile/link: `build/manager_oct08_final_full.log`. These artifacts are local and gitignored.
- Six new translation units reconstruct gameover constructors, entity regeneration, upgrade keyboard input, grid clear, string operators, and a private 16-byte vector instance. Four older files received lifecycle repairs: Point/string global vector types, the Point-vector assignment, Array2D construction/cleanup, and the integer-vector Dice wrapper. Existing array/protobuf/container implementations contributed additional registrations.
- Registered 32 proven rows in `config/mapping.d/codex_team_oct08.csv`: 28 previously unmapped addresses plus four aliases for already-mapped lifecycle callbacks. Two existing constructor rows now have real matched bodies. Actual generated global destructors are registered; synthetic destructor wrappers are not.
- Candidate audit uses 4 KiB stub slots and reports **zero matching rows with interior-stub operands** (`build/manager_oct08_final_stubaudit.log`). Verifier regression checks `check_map_symbols.py`, `check_literals.py`, `check_switch_tables.py`, and `check_ltcg.py` passed. These are static binary-matching checks; no game-runtime acceptance is claimed.
- Inventory/proofs are in `scratch/manager_oct08/`; probes are in `scratch/team_oct08_{alpha,bravo,charlie,delta}/`.

### Deferred from this batch

- `0x4ff4c0` (`AmbientSoundSystem::collectSources`): MATCH alone, but full-link exception handling adds 176 instruction differences. Existing source retained; no mapping registered.
- `0x9c35b0` (`vector<bool>::_Insert_x`): MATCH alone, but its full-link call at +0x6d conflicts with the established callee pairing (`0x9c8a00`). Draft returned to `scratch/team_oct08_charlie/deferred_boolvector.cpp`; no mapping registered.
- `0x65e040`: two stack-slot differences; `0x6ed660`: hidden returned-object pointer spill versus full-link exception handling. Scratch probes remain in `scratch/team_oct08_bravo/`. Previous unresolved constructor/descriptor candidates below remain deferred.

## Previous verified checkpoint (2026-10-07, first batch)

- **12,715 / 13,014 game functions; 47.548% code bytes matched.** The paused GitHub checkpoint was `5142a7c` (12,480 functions); this integrates 235 additional unique game-function matches, the pending local batch, and upstream semantic fixes through `d9b2cba`. Counts exclude library functions and count unique game addresses, not mapping aliases.
- Registered 45 previously unmapped targets in `config/mapping.d/codex_team_oct07.csv` only after combined-link verification.
- **32,232 / 32,232 comparisons MATCH, zero DIFF.** Two serialized complete builds checked the inherited batch and combined sources. The canonical-header registration wrapper's object was recompiled before the second link. Final registered verification: `build/manager_oct07_registered.log`; candidate gate: `build/manager_oct07_lvx_final.log`; full compile/link: `build/manager_oct07_full2.log`. These local build artifacts are gitignored.
- New candidate stub audit: 4 KiB slots, zero matching rows with interior-stub operands (`build/manager_oct07_stubaudit.log`). Passed `tests/check_map_symbols.py`, `check_literals.py`, `check_switch_tables.py`, and `check_ltcg.py`. No game-runtime behavior is claimed by these static matching checks.
- Fixed verifier symbol lookup: PUBLIC code wins over a same-named STATIC helper; STATIC code still wins over PUBLIC data stubs. Every copy remains in `MAP_ALL`. This exposes the correctly reconstructed wavelet functions without dropping either of the two previously verified static-only functions.

### Deferred candidates and useful next work

- **Resolved in the current checkpoint:** `0xb5ccb0`, `0xb5ccc0`, `0xb5ccd0`. Corrected the actual global vector types and registered their generated destructors together with the existing initializers; the independent wrapper aliases remain unregistered.
- `0x46ef00`: `Unknown46f1e0` constructor passes alone but has 69 EH-related differences in the full link.
- `0x6ed660`: region-selection helper passes alone but acquires an EH frame in the full link. Private alias prototypes remove the frame but also lose the `randomRoom` result-pointer spill. Scratch experiments are retained in `scratch/codex_charlie_oct07/`; source unchanged.
- `0x4dbc40`, `0x4dbd20`: registering descriptor helpers breaks the existing DifficultyType getter's global pairing. Resolve the enum descriptor array/order mismatch before registration (`0xceca80` table base versus getter load at `0xceca88`).
- **Resolved in the current checkpoint:** `0x87a570`, via a new input-handler implementation with the retail dead branch targets. `0x65e040` still has two stack-slot differences; its original source remains unchanged.
- Current candidate inventory and deferred rows: `scratch/manager_oct07/`; individual proofs: `scratch/codex_alpha_oct07/`, `scratch/codex_bravo_oct07/`, `scratch/codex_charlie_oct07/`, `scratch/codex_delta_oct07/`. 299 game functions remained unmatched; most remaining code bytes were in large bodies.

The sections below retain historical snapshots and may contain superseded workflow advice. Follow current `AGENTS.md`.

## Earlier state
- **2026-10-07 coverage push (cov_oct_*):** after rebasing on upstream, only `EntityAI::unknown581140` (0x581140, `src/op/cov_oct_a_ai.cpp`, `cov_oct_a.csv`) was new; the other 21 rows were already mapped upstream (the files are parked in `scratch/claude/cov_oct_superseded/`). Full link 32,095/32,095 MATCH. Still unmapped: 0x4209a0/0x420a50 wavelet (MATCH in try.sh, DIFF in the full link on the coefficient global), 0x500500/0x4ff4c0 (op_y3_sound.cpp, DIFF), 0x7aaee0 updateSpawns, 0x5b6850, 0x83d9b0, 0x87a570.
- **2026-10-07 astra580:** `EntityAI::unknown580ec0` (0x580ec0, 0x213 bytes) MATCHes under `tools/try.sh src/op/op_astra580.cpp -- 'EntityAI::unknown580ec0=0x580ec0'`. New source/mapping: `src/op/op_astra580.cpp`, `config/mapping.d/op_astra580.csv`. Partial record layout and semantic names remain placeholders. No full-link verification of this addition yet.
- Immediately before astra580, commit `1faa70f` passed `tools/build.sh`: 32,026/32,026 mappings MATCH; 42.092% code, 12,512/13,009 functions. The previously reported `op_t3_g.cpp` compile failure was absent in that build.
- **2026-10-06 evening: verified 30.826% code (10,966 / 13,009 funcs), 15.14% data.** op_x2..x5 and op_g1 (2 giants, 90 KB) integrated; 14 order-dependent/DIFF rows pruned. Open: op_r2_d.cpp declares 0x8979b0 as (HItem,int,int), exe takes bool (use (HItem,bool,int)); op_x5_b_c.cpp redeclares OpY7_SpecialCommands (check).
- Giants: Ghidra 12.1.4 in 3rdparty/ghidra, project build/ghidra_cogmind (~2 GB; clones p2..p5 and scratch/ are deletable), decompiles in build/ghidra_cogmind/dec/<va>.c for 41 of 44 giants (missing 0x51da30, 0x8b5250, 0x83dfa0). Semantic code for GiantDie/Move/Damage/Projectile lives in native/giants/.
- **Native (macOS) track: see docs/NATIVE.md** (tools/native_build.py, tools/callgraph.py). Data matching stat added to progress.py (tools/lverify.py `data_stats`).
- Last *verified* full link (2026-10-06): **25.813%** code bytes, 10,071 / 13,009 functions;
  29,556 / 29,561 verified lines matched; the 5 DIFF rows (op_s1c RecList::add/addAll, op_r1h add4722b0, op_s8b Fn9d4b30, lead_discovered swap<Point>) were dropped from csvs afterwards.
- To verify: run `tools/build.sh`, then `.venv/bin/python tools/lverify.py | grep DIFF`,
  drop non-matching rows from the offending csv, then `.venv/bin/python tools/progress.py`.
- build.sh must link: two TUs must not both define the same symbol. Pitfalls seen: a global defined in two TUs (use `extern`);
  a class declared WITHOUT its virtual dtor in one TU gets an implicit inline dtor emitted there, clashing with the real one in another TU (declare `virtual ~X();`).
  Scratch .cpp files in src/ get linked: keep them in build/<area>_tmp.
- 0xA044D0-0xA9xxxx (libprotobuf /O2) and CRT above are unmatchable with try.sh (q5-q8 confirmed).

## Earlier coverage (2026-10-06)
- src/op/op_y6.cpp lost 5 functions that op_r4_b.cpp now defines.
- op_w1 0x8a7370-0x8b0000 (53 funcs, 35.9 KB), op_w2 0x710000-0x720000 (78, 41.2 KB), op_w3 0x720000-0x730000
  (106, 68.0 KB), op_w4 0x730000-0x750000 (69, 37.3 KB), op_w6 0x4a0000-0x4b0000 (132, 28.8 KB), all jointly MATCH
  under try.sh. Not matched in op_w6 then: CPolymindSuspicion::getRequiredWidth 0x4a1840 (string temporary),
  CInfoTitle::CInfoTitle (14 instrs differ).
- Older file groups: op_a..op_h, op_pb (protobuf), cc_*, batch*/misc_small.

## Codegen lessons (op_w*)
- Stack-slot order is a name hash (insertion order within a bucket), per scope. To brute-force it, compile a toy file with
  the same type:name list (~1 s each).
- An exe `je` straight to the epilogue means `if (x != y) { ...rest }`, not an early return. A dead `jmp` after a return
  means `if (...) { return; } else { ... }`.
- Two identical-bodied callees where you'd write one = the original had two functions (ICF folded them). Declare both.
- Stubbed callees count as can-throw, so callers keep EH states the exe dropped. Declaring a known non-throwing callee
  `throw()` fixes it.

## Earlier state (2026-10-04)
- Then-verified: 8.061% (529,317 bytes), 3,074 / 12,948 functions, on build/cc_full copied to build/full.
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
- Overmind::/Zionmind:: functions were handled by a separate tool.
- Not touched: names.csv still has stale placeholder names for some entries.
