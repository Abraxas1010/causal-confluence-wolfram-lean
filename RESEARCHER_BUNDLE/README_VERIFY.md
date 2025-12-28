# Wolfram (SetReplace) Verification (Self-Contained Bundle)

## A) System prerequisites

- Lean is managed by `elan`; `lake` will fetch deps.
- Linux/macOS expected.
- Network access is required unless `vendor/git/` is provided.

## B) One-command verification

```bash
./scripts/verify_wolfram.sh
```

If you are offline but already have dependencies present under `.lake/packages/`, you can skip `lake update`:

```bash
WOLFRAM_SKIP_UPDATE=1 ./scripts/verify_wolfram.sh
```

## C) What it checks

- strict builds (warnings as errors; proof-hole markers are forbidden)
- builds and runs `wolfram_multiway_demo`
- builds and runs `wolfram_bundle_demo` (emits LambdaIR → MiniC → C)
- builds and runs `wolfram_wm148_demo` (WM148 bounded multiway; fresh-vertex semantics)
- optional: if `wolframscript` **or** `mathics` is available, runs a Wolfram Language cross-check for CE1/CE2 + WM148 JSON
- compiles and runs the emitted C program (`cc`, then run output check)
- grep audit for `axiom`/`sorry`/`admit` in the bundle Lean sources
- collects compiler artifacts (`.olean`, C IR) for the Wolfram + compiler modules
- reproducible hashes (excluding `.lake/`, `build/`, `vendor/`)

## D) Where to look

- `reports/BUILD_TRANSCRIPT_STRICT.txt`
- `reports/GREP_AXIOM_SORRY_ADMIT.txt`
- `reports/SHA256SUMS.txt`
- `reports/Wolfram_TECHNICAL_REPORT.md`
- `artifacts/generated_ce1.json`, `artifacts/generated_ce2.json`, `artifacts/generated_wm148.json`
- `artifacts/generated_wm148_wlcheck.json` (small WM148 JSON used by the WL cross-check)
- `artifacts/wolfram_viewer.html` (offline viewer)
- `artifacts/visuals/` (GraphViz DOT + SVG exports)
- `artifacts/visuals/wl_crosscheck_pipeline.svg` (WL cross-check pipeline diagram)
- `tools/wolfram_ce1_ce2.wl` (Wolfram Language replication of CE1/CE2 + WM148 bounded multiway JSON)
- `scripts/verify_wolfram_wl.sh` (optional automated WL cross-check; skips if no WL runtime is installed)
- `artifacts/compiler/ir/wpp_add1.lambdair.txt`
- `artifacts/compiler/ir/wpp_add1.minic.txt`
- `artifacts/compiler/c/wpp_add1.c`
