# Method for the giant functions (op_g1)

## Tools (all read-only w.r.t. src/ and the matching build)
- `native/giants/tools/gdis.py 0xVA [--summary]`: CFG-carved disassembly (true extent by recursive descent, basic
  blocks `L_<off>` with predecessors, switch tables, callee/global/string/float annotations). `--summary`: callees in
  first-use order with counts, strings, globals, EH state count.
- `native/giants/tools/decls.py 0xVA`: for every direct callee, its csv names, existing declarations in src/ (reuse
  these names and signatures), and for tiny bodies the actual instructions (`[= mov eax, this; mov eax, dword ptr [eax + 8]]`).
  ICF folded many trivial getters, so a callee labelled `Protobuf::PingRequest::GetCachedSize` is really
  "return this->+0x8"; write the field access (or the real accessor if src/ has one for that class), never the folded name.
- `native/giants/tools/fields.py Class [0xOFF..]`: member names other workers gave to `Class+off` (parsed from the
  32-bit layouts in src/). Use the majority name; otherwise `unknownNN` + `// NOTE: placeholder name`.
- Ghidra 12.1.4 (3rdparty/ghidra, decompiler native binary built for arm64 from its bundled sources) with the
  project in `build/ghidra_cogmind/` (auto-analysed once, ~17 min):
  - `G1ApplyNames.java` (pre-analysis): 11.2k names from the csvs (mangled where our full link has them), so the
    MS demangler gives prototypes/`this`;
  - `G1FixConventions.java`: `__thiscall` for functions whose /Od prologue spills ECX, stack-argument counts from the
    callee purge (or highest `[ebp+8+4k]` read). Without this the decompiler drops call arguments;
  - `native/giants/ghidra/decompile.sh <project> <outdir> 0xVA..` writes `<va>.c` (one Ghidra per project dir;
    clones `build/ghidra_cogmind/p2..p5` allow 5 parallel queues). Output for all giants: `build/ghidra_cogmind/dec/`.
  - `native/giants/tools/simplify.py x.c` shortens STL spellings and drops the local declaration block.
  Ghidra types are only hints: ICF-folded names leak into parameter types (`Push_46ca50 *a3` is an HEntity), and
  stack-passed handle temporaries (`HEntity()`/`HProp()` = `RNGC::RNGC`) can be scrambled; check calls against gdis.
- `native/giants/tools/gdiff.py <ltcg outdir> 'Name=0xVA' [--all|--sem]`: compile with
  `.venv/bin/python tools/ltcg.py <outdir> file.cpp` (MSVC /Od /GL, same as try.sh). Default mode = try.sh compare
  without the 40-line cap. `--sem` = semantic check: the ordered callee sequence (both sides resolved to exe VAs;
  placeholder names `unknownXXXXXX` resolve by their address) aligned with difflib, plus string/float literal
  multisets and an instruction-shape ratio. Because /Od is near-literal, a call-sequence ratio of ~1.0 means the same
  statements in the same order with the same branch layout; remaining differences are listed.
- `native/giants/tools/lift_7a0e80.py`: example of a generator for straight-line giants.

## Writing a semantic reconstruction (native/giants/<va>_<name>.cpp)
1. `gdis --summary`, `decls`, the Ghidra `.c`; walk the Ghidra output top to bottom, checking each call against the
   disassembly (argument order, temporaries, which handle is passed).
2. One self-contained .cpp per giant: declarations copied at the top (classes with only the members the function
   touches, in offset order, each with a `// +0xNN` comment; no padding arrays, no raw-offset casts), then the
   function. Callees keep their csv names/signatures; unnamed callees are `unknown<va>` members of the class their
   `this` belongs to (or free functions), `// NOTE: placeholder name (0x<va>)`.
3. Keep the order and count of every call with side effects, especially `rng` (`RNG::rangeInt`, `RNG::chance`, ...).
   Structured control flow only (no gotos unless the original clearly had one), Kyzrati's style (docs/STYLE.md).
4. Validate: (a) MSVC compile + `gdiff.py --sem` (record call ratio and the remaining differences);
   (b) host clang `-std=c++11 -fsyntax-only` for portability.
5. Notes in `docs/giants/<va>.md`: status, call ratio, open questions, unresolved callees.
