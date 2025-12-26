# Wolfram (SetReplace) Verification (Self-Contained Bundle)

## A) System prerequisites

- Lean is managed by `elan`; `lake` will fetch deps.
- Linux/macOS expected.
- Network access is required unless `vendor/git/` is provided.

## B) One-command verification

```bash
./scripts/verify_wolfram.sh
```

## C) What it checks

- strict builds (`-Dno sorry -DwarningAsError=true`)
- builds and runs `wolfram_multiway_demo`
- grep audit for `axiom`/`sorry`/`admit`
- collects compiler artifacts (`.olean`, C IR) for the Wolfram modules
- reproducible hashes (excluding `.lake/`, `build/`, `vendor/`)

## D) Where to look

- `reports/BUILD_TRANSCRIPT_STRICT.txt`
- `reports/GREP_AXIOM_SORRY_ADMIT.txt`
- `reports/SHA256SUMS.txt`
- `reports/Wolfram_TECHNICAL_REPORT.md`
- `artifacts/generated_ce1.json`, `artifacts/generated_ce2.json`
- `artifacts/wolfram_viewer.html` (offline viewer)
- `artifacts/visuals/` (GraphViz DOT + SVG exports)
