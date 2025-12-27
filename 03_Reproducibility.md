# Reproducibility (local)

These are the commands a researcher can run to reproduce the formal and runtime checks.

## One-command researcher bundle (recommended)

This paper pack includes a standalone Lake project that pins its dependencies and can be verified
independently of the rest of the repo:

```bash
cd RESEARCHER_BUNDLE
./scripts/verify_wolfram.sh
```

If you are offline but already have dependencies present under `RESEARCHER_BUNDLE/.lake/packages/`, you can skip `lake update`:

```bash
cd RESEARCHER_BUNDLE
WOLFRAM_SKIP_UPDATE=1 ./scripts/verify_wolfram.sh
```

This performs:
- `lake update` (fetch pinned dependencies)
- Strict build with `-DwarningAsError=true` (treats proof holes as errors)
- Runs `wolfram_multiway_demo` for both CE1 and CE2
- Runs `wolfram_bundle_demo` to emit LambdaIR → MiniC → C and compiles the emitted C program
- Greps for `axiom`/`sorry`/`admit` in sources
- Generates SHA256 checksums
- Collects compiler artifacts (`.olean`, IR)

The bundle also ships offline visuals (no build step required):

- `RESEARCHER_BUNDLE/artifacts/visuals/index.html`

## Prerequisites

- `elan` installed (Lean toolchain manager).
- System toolchain for Lean executables:
  - C compiler (`cc`), linker toolchain.
  - `bash`, `python3`.
  - Optional: `graphviz` (`dot`) for SVG rendering from DOT files.
  - Optional: `jq`, `ldd` for some QA scripts.

Lean version is pinned by `lean-toolchain` (see `04_Dependencies.md`).

## Build only the Wolfram modules (fast)

From repo root:

```bash
cd lean
lake build HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance -- -DwarningAsError=true
```

## Build the full library strictly (incremental)

```bash
cd lean
lake build -- -DwarningAsError=true
```

## Build all executables (C backend + linking)

From repo root:

```bash
scripts/build_all_exes.sh --strict
```

## Run executables (happy path)

```bash
# Default (CE1, depth 3)
cd lean && lake exe wolfram_multiway_demo

# CE2 (depth 2)
cd lean && lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2
```

Or from repo root:

```bash
scripts/run_all_exes.sh
```

## Optional: Wolfram Language replication (no Lean required)

If you have Mathematica / Wolfram Engine available, the researcher bundle includes a pure Wolfram Language script
that reproduces the CE1/CE2 bounded multiway JSON format emitted by `wolfram_multiway_demo`:

```wl
Get["RESEARCHER_BUNDLE/tools/wolfram_ce1_ce2.wl"];
Export["ce1_from_wl.json", CE1JSON[3], "JSON"];
Export["ce2_from_wl.json", CE2JSON[2], "JSON"];
```

Compare to:

- `RESEARCHER_BUNDLE/artifacts/generated_ce1.json`
- `RESEARCHER_BUNDLE/artifacts/generated_ce2.json`

## Robustness checks (missing files/env/PATH)

```bash
scripts/qa_robustness_all.sh
```

## Portability (dynamic dependencies)

```bash
scripts/qa_portability.sh
```

## Optional: regenerate visuals (offline)

From the repo root (requires `python3`; SVG rendering additionally uses GraphViz `dot`):

```bash
# Generate DOT + SVG for CE1
python3 RESEARCHER_BUNDLE/scripts/wolfram_json_to_dot.py \
  RESEARCHER_BUNDLE/artifacts/ce1_multiway_depth3.json \
  RESEARCHER_BUNDLE/artifacts/visuals/ce1_depth3 \
  --render-svg

# Generate DOT + SVG for CE2
python3 RESEARCHER_BUNDLE/scripts/wolfram_json_to_dot.py \
  RESEARCHER_BUNDLE/artifacts/ce2_multiway_depth2.json \
  RESEARCHER_BUNDLE/artifacts/visuals/ce2_depth2 \
  --render-svg
```

## Optional: generate UMAP proof maps

From repo root (requires Node.js):

```bash
node server/scripts/export_wolfram_viz.js
```

This generates `wolfram_proofs.json` and `wolfram_proofs_data.js` for the 2D/3D viewers.

## Full local QA (repo contract)

From the repo root:

1. `cd lean && lake build -- -DwarningAsError=true`
   - (This flag makes `sorry` a hard error, since `sorry` emits a warning.)
2. `./scripts/build_all_exes.sh --strict`
3. `./scripts/run_all_exes.sh`
4. `./scripts/qa_robustness_all.sh`
5. `./scripts/qa_portability.sh`
