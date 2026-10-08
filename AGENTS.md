# Cogmind decomp: working loop

Goal: C++ that VS2010 SP1 (`/Od /GL`, LTCG link) compiles to byte-identical code for functions of
`resources/COGMIND.exe` (Beta 17.1). Setup is in `cogmind-kit/SETUP.md`; wine and the toolchain must already work.

## Layout
- `src/**.cpp`, `harness/*.cpp`: every file is compiled and linked into `build/full/match.dll`. Files are
  self-contained: they declare partial classes and placeholder externs as needed (see `src/game/batch10.cpp`).
- `config/mapping.d/<area>.csv`: `name,va,size` for every reconstructed function. `name` is `Class::member`
  (demangled, as `common.demangle` prints it) or the full mangled name when overloaded or templated.
  Only rows that MATCH belong here. `size` = `fn_size(va)` (the size `fdis.py` prints).
- `config/names.csv` (identified, not reconstructed), `globals.csv`, `library*.csv`.

## Tools (run from the repo root with `.venv/bin/python`)
- `tools/fdis.py <va> [n]`: disassemble n consecutive exe functions, with known names labelled.
- `tools/xref.py <va> ...`: name, callers, callees, vtable slot, and referenced strings for a function.
- `tools/try.sh a.cpp [b.cpp] -- 'Name=0xVA' ...`: compile + LTCG link in a private temp dir and compare.
  Safe to run in parallel; about 20 s. `Name` is `Class::member` or mangled. Unknown callees and globals are
  stubbed automatically, so you only need declarations for them.
- `tools/lvx.py <build dir> <extra.csv> [name-to-drop ...]`: lverify with candidate rows injected (or rows dropped)
  without touching `config/`. Never put unproven rows in `config/mapping.d/`: main auto-commits only all-MATCH builds.
- `tools/stubaudit.py <build dir>`: rows whose operands sit inside a stub at a non-zero offset. Stubs are 4 KiB `.bss`
  slots (`STUB_SLOT` env; 16 = old layout, which disables lverify's interior-pairing check).
- `tools/discover.py <ltcg dir> [filter]`: finds exe functions that code you already built matches by accident.
- `tools/fullbuild.sh <build/full_X> [lverify args]`: THE way to run a private full build. A machine-wide lock allows
  only one full build at a time (several at once ran a 48 GB machine out of memory) and waits for 12 GB free.
  Never call `tools/ltcg.py` on all sources directly. Normally don't run private full builds at all: the
  integration loop rebuilds ALL of `src/` into `build/full` every cycle, so put try.sh-verified code in `src/`, keep
  candidate rows in `scratch/`, and install them once `tools/lvx.py build/full <cand.csv>` passes on a build that
  includes your files. Private full builds only for tool changes that need a before/after comparison.
- `tools/build.sh`: full build + verify + progress (about 3.5 min, writes `build/full`). Only one may run at a
  time. For a private full check use `tools/fullbuild.sh build/full_X`.
- `build/rtti.csv` (vtables -> class + slots), `build/namestrings.csv` ("Class::method()" strings -> function),
  `build/callgraph.json`. Regenerate with `tools/rtti.py`, `tools/namestrings.py`, `tools/callgraph.py`.

## Rules
1. Work on files that are not in `src/` until they compile. `sources.py` globs all of `src/`, so a file that
   does not compile breaks everyone's build. Draft in `scratch/<you>/` (gitignored) and move the file into
   `src/<dir>/` only when every function it maps MATCHes in `try.sh`.
2. Only add new files. Don't edit another area's `.cpp`/`.csv` without coordinating; the LTCG link order
   (`config/link_order.txt`) affects EH state numbering in other functions.
3. One definition rule across the whole link: before you define a non-inline function or a global, grep `src/`
   for its name and for its exe address. A placeholder name carries the exe address (`unknown4544e0`, `vec_d33d38`),
   which keeps names unique and lets `lverify` pair placeholder globals with their exe address.
4. Mark guesses: `// NOTE: placeholder name` / `// NOTE: placeholder layout`.
5. Never commit `resources/*.exe` or anything from `dls/`.
6. Claim before you start: `.venv/bin/python tools/claim.py claim <va> <owner> "<what>"` pushes a line to the shared
   `config/claims.txt` on origin (other people work on this repo too). If it says the VA is claimed or already mapped,
   pick something else. Release a claim you abandon with `tools/claim.py release <va>`; claims of matched functions are
   released automatically after the integration push. `tools/claim.py list` shows all claims. Hold ONE active claim at
   a time (plus any that only wait for their lvx check); claiming a queue of functions blocks other people.

## Matching tips (`/Od`)
- Code gen is literal: the order of statements, temporaries, `for` vs `while`, `++i` vs `i++` on iterators,
  pass-by-value vs reference, and `bool` vs `int` all show up. Locals' stack offsets depend on their names (below).
- Exception-handling state numbers (`mov byte/dword ptr [ebp-4], N`) count objects with destructors, so
  temporaries (e.g. `string` built from `+`) must appear in the same order as in the exe.
- `this` arrives in `ecx` (thiscall); member offsets come from `[reg+off]`: pad classes with `char pad[N]`.
- `??__E` / `??__F` are a global's dynamic initializer / atexit destructor; they sit near the end of `.text`
  (0xb2xxxx-0xb6xxxx), one per global, ordered by translation unit.
- See every local's frame offset directly: `tools/cl.sh cl /c /Od /EHsc /GS /FAs <file.cpp>` writes a `.asm` listing
  with `_name$ = -N` per local. Much faster than guessing from diffs.
- Stack slots of locals are NOT in declaration order: within a scope, VS2010 `/Od` orders locals by a 16-bucket
  hash of the *name* (lower bucket = higher address, closer to ebp; same bucket: later-declared sits higher;
  outer scopes before inner). When only `[ebp-x]` offsets differ, rename locals. Measured buckets for ~450 common
  names: `docs/local-name-buckets.txt` (probe: `tools/probe/`). Generating many name variants in one `try.sh`
  file is quick.
- LTCG adds an EH frame when *any* TU declares a callee without `throw()`. If the exe has no EH frame but the full
  build does, declare the callees under names unique to your file with `throw()` (they stub and pair by address).
- lverify pairs each of our symbols with one exe address. With identical code folded by ICF in the exe, a row can
  pass in `try.sh` yet DIFF (or break older rows) in the full verify; prove mapping-only rows with a private full build.
- Extra stack slot around `new` (memory slot, ctor result, *extra slot*, then the variable or argument) with no EH
  states: VS2010 gives every `new` of a ctor that might throw a result temporary; when LTCG later proves the ctor
  nothrow it deletes the EH state stores but keeps the slot. LTCG can prove it only if the ctor is declared WITHOUT
  `throw()` and is defined in the link together with everything it calls (one stub in the chain = "may throw").
  Recipe: for an unmapped/folded ctor, declare a placeholder class (your own name) whose ctor has no `throw()` and
  define it in your file with a trivial body; lverify pairs it by address. Use `throw()` only where the exe has
  neither EH states nor the extra slot. Probes: `scratch/delta/newtemp/`.
- Register rotation (eax/ecx/edx) off by one after an `if`: an empty `if (0) {}` / `if (false) {}` right after it
  shifts the allocator without emitting code. Consecutive stores that rotate wrong (`a = f; b = f; c = f;`) may need
  one comma statement (`a = f, b = f, c = f;`). A trailing dead `jmp` after a switch dispatch: `break;` before the first `case`.
- A new TU can change LTCG nothrow inference for files linked after it (and break their EH states); files in
  `src/util/` sort last in the link, which is a workable home for such TUs (note why at the top of the file).
- Stubbed externs are 16-byte slots: an access at `[sym + 0x30]` can land on the *start of an unrelated stub* and
  pair wrongly (or "match" by luck when the exe bytes are zero). For table/column accesses at non-zero offsets,
  declare one extern per column so each access is at offset 0 of its own symbol.
- Negative offsets into a stub (`table[i - 1]` -> `[i*4 + sym-4]`) land in the PREVIOUS stub's slot and poison its
  learned pairing (later calls DIFF). Declare a separate extern for the `sym-4` base.
- `fmul dword ptr [const]`: write the constant as an `extern const float` (a literal `0.1f` can become a qword).
  `vector::assign(16u, 0)` (size_type) vs `assign(16, 0)` (iterator template). Vectors whose `clear()` are distinct
  exe functions need distinct element types.
- Pass-by-value `Point` built in place in the outgoing arg slot needs a declared `Point(const Point&) throw()`;
  without it you get a temporary plus a copy. A returned handle copied with `mov` must have no user copy ctor.
- One shared `return false;` at the end (`if (a && b) { ... } return false;`) vs early returns; `for (;;)` and
  `while (true)` differ.
- Tooling: macOS `sed` has no `\b`; use `perl -pe` for word-boundary renames (sed silently does nothing).
- Temporaries: class temps > 8 bytes go in the early pool (top of frame), a 12-byte one can land in the late pool
  after ternary-result slots and a 16-byte one in the early pool: get struct sizes right before chasing offsets.
  Locals that look "out of scope order" are often declared uninitialized at the top of their block.
- `""` (and other short) literals in `cond ? "x" : ""` are tail-merged at different exe addresses per site; use a
  named `extern const char empty_<addr>[]` per site.
- Constant-index reads of string arrays (`mov eax, imm`) hit the stub-offset issue too: reference the real array
  (`configOptionNames[195]`, global_string_arrays.cpp). Constants that print as `(double)3.14159265f` are double
  literals in source (`1.0 - x`, not `1 - x`). A struct holding `int[2]` triggers /GS; spell the fields out.
- An int literal in x87 math (`a - 100 / b * c`) gives `fsubr mem`; `100.0` doesn't. Implicit conversion
  (`f = Pos(-1)` into a member) vs an explicit ctor call temp differ in register use.
- throw() specs merge across the whole link: if ANY TU declares a callee without `throw()` (or LTCG sees a real
  definition it can't prove nothrow), callers get EH frames. try.sh can pass while the full build fails. Fixes: a
  private alias declared `throw()` used only at that call site (`HProp::get_9b64f0()` instead of `operator->`), or
  file-unique placeholder callee names that stay stubs in the full build.
- In a scope holding a /GS buffer (any std::string), scalars are split around it by name bucket: buckets lower than
  the buffer's sit above the cookie, higher ones below the string.
- Never create symlinks under `src/` (sources.py follows them recursively).
- `new` whose result is pushed via an extra copy slot with no EH state: `v.push_back(static_cast<T*&&>(new X(...)))`.
  A global string array element passed by value gets the pre-loaded address only at a non-zero index (`arr[1]`).
  Frame-offset-insensitive diffing and offset->local-name helpers: `scratch/delta2/tools/` (sdiff.py, offmap.py, chk.sh).
- `new` with the temp-copy pattern but no EH state write: the ctor body is empty and LTCG proved it nothrow; give the
  private type an inline `T() {}` (declaring it `throw()` removes the temp). A stray EH state inside a `new` region usually
  comes from a stub called while building the arguments: mark that stub `throw()`.
- `if (!f(string("x"), out)) ;` gives the "store !result to a temp, never read" pattern; `push_back(+i)` picks the `&&`
  overload with no extra code; unreferenced gaps in a scope's locals need dummy `int x[1]` / `char x[4]` declarations.
- `vector<T>` members already pinned to another address by another TU (e.g. `src/lead/stl_a`) pass in try.sh but DIFF in
  the full build: use private element types (`struct E6Hit : vector<int> {}`).
- Frame layout for big functions: `scratch/lima/` (best: scopes.py parses scopes, bk.py measures name buckets with a
  probe compile and caches ~6900 names in buckets_extra.json, solve.py picks the fewest renames per scope, om.py/loc.py
  compare offsets; placed 689 locals of a 119 KB function). Older: `scratch/echo/`, `scratch/india/names.py`.
- ebp-insensitive diffs hide real bugs (swapped receiver/argument) and EH-state differences: also check EH sequences.
- Giants with long regular sections (command tables): generate that source from the disassembly (`scratch/hotel/gen.py`).
- Checking whether a VA is already matched: grep mapping rows only (`git grep -h ",<va>," origin/main -- config/mapping.d`);
  `config/names.csv` lists named-but-unmatched functions and gives false positives.
- A template instance over a type that other files define differently (e.g. XColor) can silently use another
  file's copy; give such instances private element types.

## References
- `XomMind/cogbench` `notes/b17.1-luigiai.md` (branch `retail-build-support`; local copy in `scratch/ref/`): runtime RE
  notes for this exact build: LuigiAi struct/globals, the map object at 0xCFD44C, the Cell layout (+0x30 coord,
  +0x3A doorOpen, +0x44 prop, +0x48 entity, +0x4C items), Scorekeeper functions (0x474b90 outputScoresheet,
  0x47f450 scorehistory append, 0x480270 createProtobuf), cellAt 0x9cf7d0, updateLuigiAiMapTile 0x9f2ce0.
  Useful for names and layouts; it is a research log, so later rounds supersede earlier ones.
