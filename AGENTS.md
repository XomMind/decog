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
- `tools/discover.py <ltcg dir> [filter]`: finds exe functions that code you already built matches by accident.
- `tools/build.sh`: full build + verify + progress (about 3.5 min, writes `build/full`). Only one may run at a
  time. For a private full check: `.venv/bin/python tools/ltcg.py build/full_X $(.venv/bin/python tools/sources.py) && .venv/bin/python tools/lverify.py --dir build/full_X`.
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

## Matching tips (`/Od`)
- Code gen is literal: the order of statements, temporaries, `for` vs `while`, `++i` vs `i++` on iterators,
  pass-by-value vs reference, and `bool` vs `int` all show up. Locals' stack offsets follow declaration order.
- Exception-handling state numbers (`mov byte/dword ptr [ebp-4], N`) count objects with destructors, so
  temporaries (e.g. `string` built from `+`) must appear in the same order as in the exe.
- `this` arrives in `ecx` (thiscall); member offsets come from `[reg+off]`: pad classes with `char pad[N]`.
- `??__E` / `??__F` are a global's dynamic initializer / atexit destructor; they sit near the end of `.text`
  (0xb2xxxx-0xb6xxxx), one per global, ordered by translation unit.
