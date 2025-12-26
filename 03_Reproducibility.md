# Wolfram Project — Reproducibility

This project is designed to satisfy the local QA contract from `AGENTS.md`:

1. Strict Lean build (no sorries/warnings)
2. Build all `lean_exe` targets
3. Run executables
4. Robustness checks (IO/env/path)
5. (Optional) portability checks

## Minimal local verification (Wolfram modules only)

From the repo root:

1. `./scripts/guard_no_sorry.sh`
2. `cd lean && lake build HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance -- -Dno sorry -DwarningAsError=true`
3. `cd lean && lake build wolfram_multiway_demo -- -Dno sorry -DwarningAsError=true`
4. `cd lean && lake exe wolfram_multiway_demo` (CE1 default; prints JSON)
5. `cd lean && lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2` (prints JSON)

## Optional: regenerate visuals (offline)

From the repo root (requires `python3`; SVG rendering additionally uses GraphViz `dot`):

1. `python3 WIP/Wolfram_PaperPack/tools/wolfram_json_to_dot.py WIP/Wolfram_PaperPack/artifacts/ce1_multiway_depth3.json WIP/Wolfram_PaperPack/artifacts/visuals/ce1_depth3 --render-svg`
2. `python3 WIP/Wolfram_PaperPack/tools/wolfram_json_to_dot.py WIP/Wolfram_PaperPack/artifacts/ce2_multiway_depth2.json WIP/Wolfram_PaperPack/artifacts/visuals/ce2_depth2 --render-svg`
3. Open `WIP/Wolfram_PaperPack/artifacts/wolfram_viewer.html` and load the JSON file(s).

## Full local QA (repo contract)

From the repo root:

1. `cd lean && lake build -- -Dno sorry -DwarningAsError=true`
2. `./scripts/build_all_exes.sh --strict`
3. `./scripts/run_all_exes.sh`
4. `./scripts/qa_robustness_all.sh`
5. `./scripts/qa_portability.sh`
