# Wolfram Project — Reproducibility (Self-Contained Bundle)

This folder is a standalone Lake project intended to be verifiable without the full
HeytingLean repository.

## One-command verification (recommended)

From this folder:

1. `./scripts/verify_wolfram.sh`

If you are offline but already have dependencies present under `.lake/packages/`, you can skip `lake update`:

- `WOLFRAM_SKIP_UPDATE=1 ./scripts/verify_wolfram.sh`

## Manual verification (strict)

From this folder:

1. `lake update`
2. `lake build HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance -- -DwarningAsError=true`
3. `lake build wolfram_multiway_demo -- -DwarningAsError=true`
4. `lake exe wolfram_multiway_demo > artifacts/generated_ce1.json`
5. `lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2 > artifacts/generated_ce2.json`
6. `lake build wolfram_bundle_demo -- -DwarningAsError=true`
7. `lake exe wolfram_bundle_demo`
8. `cc artifacts/compiler/c/wpp_add1.c -O2 -std=c11 -o artifacts/compiler/bin/wpp_add1`
9. `./artifacts/compiler/bin/wpp_add1` (expected output: `42`)

## Optional: regenerate visuals (offline)

From this folder (requires `python3`; SVG rendering additionally uses GraphViz `dot`):

1. `python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce1.json artifacts/visuals/generated_ce1 --render-svg`
2. `python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce2.json artifacts/visuals/generated_ce2 --render-svg`
3. Open `artifacts/wolfram_viewer.html` and load the JSON file(s).
