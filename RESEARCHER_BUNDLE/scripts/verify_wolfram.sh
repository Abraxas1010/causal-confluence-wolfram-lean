#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

mkdir -p reports artifacts artifacts/compiler/ir artifacts/compiler/olean

TRANSCRIPT="reports/BUILD_TRANSCRIPT_STRICT.txt"
GREP_OUT="reports/GREP_AXIOM_SORRY_ADMIT.txt"
SHA_OUT="reports/SHA256SUMS.txt"
GITCFG="reports/GITCONFIG_EFFECTIVE.txt"

echo "[verify_wolfram] root=$ROOT_DIR" | tee "$TRANSCRIPT"

{
  echo
  echo "[versions] lean"
  lean --version
  echo
  echo "[versions] lake"
  lake --version

  echo
  echo "[env] disable mathlib cache on update (for portability)"
  export MATHLIB_NO_CACHE_ON_UPDATE="${MATHLIB_NO_CACHE_ON_UPDATE:-1}"
  echo "MATHLIB_NO_CACHE_ON_UPDATE=$MATHLIB_NO_CACHE_ON_UPDATE"

  echo
  echo "[git] configure URL policy"
  if [[ "${WOLFRAM_DISABLE_VENDOR:-0}" != "1" ]] && \
     [[ -d "$ROOT_DIR/vendor/git/github.com/leanprover-community/mathlib4" ]]; then
    echo "[git] using vendor mirrors under vendor/git/ (offline-capable)"
    cat >"$GITCFG" <<EOF
[url "vendor/git/github.com/"]
  insteadOf = https://github.com/
EOF
  else
    if [[ "${WOLFRAM_DISABLE_VENDOR:-0}" == "1" ]]; then
      echo "[git] vendor mirrors disabled by WOLFRAM_DISABLE_VENDOR=1; using network URLs"
    else
      echo "[git] no vendor mirrors found; using network URLs"
    fi
    cat >"$GITCFG" <<EOF
# no URL rewrites
EOF
  fi
  export GIT_CONFIG_GLOBAL="$ROOT_DIR/$GITCFG"
  export GIT_CONFIG_NOSYSTEM=1
  echo "GIT_CONFIG_GLOBAL=$GIT_CONFIG_GLOBAL"
  echo "GIT_CONFIG_NOSYSTEM=$GIT_CONFIG_NOSYSTEM"
  echo
  echo "[gitconfig]"
  cat "$GITCFG"

  echo
  echo "[lake] update"
  lake update

  echo
  echo "[lake] build Wolfram modules (strict)"
  lake build HeytingLean.WPP.MultiwayRel -- -DwarningAsError=true -Dno sorry
  lake build HeytingLean.WPP.Wolfram.MultiwayBridge -- -DwarningAsError=true -Dno sorry
  lake build HeytingLean.WPP.Wolfram.MultiwayRel -- -DwarningAsError=true -Dno sorry
  lake build HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance -- -DwarningAsError=true -Dno sorry
  lake build HeytingLean.WPP.Wolfram.Branchial -- -DwarningAsError=true -Dno sorry
  lake build HeytingLean.WPP.Wolfram.CausalGraphLabeled -- -DwarningAsError=true -Dno sorry
  lake build wolfram_multiway_demo -- -DwarningAsError=true -Dno sorry

  echo
  echo "[run] wolfram_multiway_demo (CE1 default)"
  lake exe wolfram_multiway_demo > artifacts/generated_ce1.json
  echo "[run] wolfram_multiway_demo (CE2)"
  lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2 > artifacts/generated_ce2.json

  echo
  echo "[visuals] DOT/SVG exports (optional)"
  if command -v python3 >/dev/null 2>&1; then
    python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce1.json artifacts/visuals/generated_ce1 --render-svg || true
    python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce2.json artifacts/visuals/generated_ce2 --render-svg || true
  else
    echo "skipping: python3 not found"
  fi
} 2>&1 | tee -a "$TRANSCRIPT"

echo "[audit] grep for markers under HeytingLean/" | tee "$GREP_OUT"
rg -n --type lean -S "\\b(axiom|sorry|admit)\\b" HeytingLean >>"$GREP_OUT" 2>&1 || true

if rg -n --type lean -S "\\b(axiom|sorry|admit)\\b" HeytingLean >/dev/null 2>&1; then
  echo "[audit] FAILED: found forbidden markers" | tee -a "$TRANSCRIPT"
  exit 1
fi

echo "[artifacts] collect compiler outputs (olean + C IR)" | tee -a "$TRANSCRIPT"
rm -rf artifacts/compiler/ir/HeytingLean/WPP/Wolfram artifacts/compiler/olean/HeytingLean/WPP/Wolfram
rm -rf artifacts/compiler/ir/HeytingLean/CLI artifacts/compiler/olean/HeytingLean/CLI
mkdir -p artifacts/compiler/ir/HeytingLean/WPP/Wolfram artifacts/compiler/olean/HeytingLean/WPP/Wolfram
mkdir -p artifacts/compiler/ir/HeytingLean/CLI artifacts/compiler/olean/HeytingLean/CLI

if [[ -d .lake/build/ir/HeytingLean/WPP/Wolfram ]]; then
  cp -a .lake/build/ir/HeytingLean/WPP/Wolfram/. artifacts/compiler/ir/HeytingLean/WPP/Wolfram/
fi
if [[ -d .lake/build/ir/HeytingLean/CLI ]]; then
  cp -a .lake/build/ir/HeytingLean/CLI/. artifacts/compiler/ir/HeytingLean/CLI/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/WPP/Wolfram ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/WPP/Wolfram/. artifacts/compiler/olean/HeytingLean/WPP/Wolfram/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/CLI ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/CLI/. artifacts/compiler/olean/HeytingLean/CLI/
fi

echo "[hashes] sha256 over bundle (excluding .lake/, build/, vendor/)" | tee -a "$TRANSCRIPT"
rm -f "$SHA_OUT"
(
  cd "$ROOT_DIR"
  find . -type f \
    -not -path './.lake/*' \
    -not -path './build/*' \
    -not -path './vendor/*' \
    -not -path './reports/SHA256SUMS.txt' \
    -print0 \
    | sort -z \
    | xargs -0 sha256sum
) >"$SHA_OUT"

echo "[verify_wolfram] OK" | tee -a "$TRANSCRIPT"
