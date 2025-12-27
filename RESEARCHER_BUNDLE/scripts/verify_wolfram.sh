#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

mkdir -p reports artifacts artifacts/compiler/ir artifacts/compiler/olean
mkdir -p artifacts/compiler/bin artifacts/compiler/c artifacts/visuals

TRANSCRIPT="reports/BUILD_TRANSCRIPT_STRICT.txt"
GREP_OUT="reports/GREP_AXIOM_SORRY_ADMIT.txt"
AXIOMS_OUT="reports/AXIOMS_PRINT.txt"
SHA_OUT="reports/SHA256SUMS.txt"
GITCFG="reports/GITCONFIG_EFFECTIVE.txt"

STRICT_FLAGS=(-- -DwarningAsError=true -Dno sorry)

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
  if [[ "${WOLFRAM_SKIP_UPDATE:-0}" == "1" ]]; then
    echo "skipping: WOLFRAM_SKIP_UPDATE=1"
  else
    lake update
  fi

  echo
  echo "[strict_flags] ${STRICT_FLAGS[*]}"

  echo
  echo "[lake] build Wolfram modules (strict)"
  lake build HeytingLean.WPP.MultiwayRel "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.FreshSupply "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.RewriteFresh "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.SimpleHypergraph "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.MultiwayBridge "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.MultiwayRel "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.Branchial "${STRICT_FLAGS[@]}"
  lake build HeytingLean.WPP.Wolfram.CausalGraphLabeled "${STRICT_FLAGS[@]}"
  lake build wolfram_multiway_demo "${STRICT_FLAGS[@]}"
  lake build wolfram_bundle_demo "${STRICT_FLAGS[@]}"

  echo
  echo "[run] wolfram_multiway_demo (CE1 default)"
  lake exe wolfram_multiway_demo > artifacts/generated_ce1.json
  echo "[run] wolfram_multiway_demo (CE2)"
  lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2 > artifacts/generated_ce2.json

  echo
  echo "[run] wolfram_bundle_demo (LambdaIR → MiniC → C artifacts)"
  rm -rf artifacts/compiler || true
  mkdir -p artifacts/compiler/ir artifacts/compiler/c artifacts/compiler/bin
  lake exe wolfram_bundle_demo

  echo
  echo "[cc] compile emitted C"
  test -f artifacts/compiler/ir/wpp_add1.lambdair.txt
  test -f artifacts/compiler/ir/wpp_add1.minic.txt
  test -f artifacts/compiler/c/wpp_add1.c
  cc artifacts/compiler/c/wpp_add1.c -O2 -std=c11 -o artifacts/compiler/bin/wpp_add1

  echo
  echo "[run] emitted C binary"
  C_OUT="$(./artifacts/compiler/bin/wpp_add1 | tr -d '\r\n')"
  echo "wpp_add1 output=$C_OUT"
  if [[ "$C_OUT" != "42" ]]; then
    echo "E: unexpected output from emitted C binary (expected 42)"
    exit 1
  fi

  echo
  echo "[visuals] DOT/SVG exports (optional)"
  if command -v python3 >/dev/null 2>&1; then
    python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce1.json artifacts/visuals/generated_ce1 --render-svg || true
    python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce2.json artifacts/visuals/generated_ce2 --render-svg || true
  else
    echo "skipping: python3 not found"
  fi

  echo
  echo "[robustness] minimal environment"
  env -i PATH="" "$ROOT_DIR/.lake/build/bin/wolfram_bundle_demo" || exit 1

  echo
  echo "[robustness] unwritable artifacts/compiler (expect nonzero, no crash)"
  chmod -R a-w artifacts/compiler || true
  set +e
  "$ROOT_DIR/.lake/build/bin/wolfram_bundle_demo"
  RC=$?
  set -e
  chmod -R u+w artifacts/compiler || true
  if [[ "$RC" -eq 0 ]]; then
    echo "E: expected nonzero exit when artifacts/compiler is unwritable"
    exit 1
  fi

  echo
  echo "[portability] dynamic deps (best effort)"
  if command -v ldd >/dev/null 2>&1; then
    ldd "$ROOT_DIR/.lake/build/bin/wolfram_multiway_demo" | tee reports/LDD_wolfram_multiway_demo.txt
    ldd "$ROOT_DIR/.lake/build/bin/wolfram_bundle_demo" | tee reports/LDD_wolfram_bundle_demo.txt
    ldd "$ROOT_DIR/artifacts/compiler/bin/wpp_add1" | tee reports/LDD_wpp_add1.txt
  else
    echo "skipping: ldd not found"
  fi

  echo
  echo "[audit] print axioms (kernel footprint)"
  lake env lean HeytingLean/WPP/Wolfram/AxiomsAudit.lean | tee "$AXIOMS_OUT"
} 2>&1 | tee -a "$TRANSCRIPT"

echo "[audit] grep for markers under HeytingLean/" | tee "$GREP_OUT"
rg -n --type lean -S "\\b(axiom|sorry|admit)\\b" HeytingLean >>"$GREP_OUT" 2>&1 || true

if rg -n --type lean -S "\\b(axiom|sorry|admit)\\b" HeytingLean >/dev/null 2>&1; then
  echo "[audit] FAILED: found forbidden markers" | tee -a "$TRANSCRIPT"
  exit 1
fi

echo "[artifacts] collect compiler outputs (olean + C IR)" | tee -a "$TRANSCRIPT"
rm -rf artifacts/compiler/ir/HeytingLean/WPP/Wolfram artifacts/compiler/olean/HeytingLean/WPP/Wolfram
rm -rf artifacts/compiler/ir/HeytingLean/WPP artifacts/compiler/olean/HeytingLean/WPP
rm -rf artifacts/compiler/ir/HeytingLean/CLI artifacts/compiler/olean/HeytingLean/CLI
rm -rf artifacts/compiler/ir/HeytingLean/Core artifacts/compiler/olean/HeytingLean/Core
rm -rf artifacts/compiler/ir/HeytingLean/LambdaIR artifacts/compiler/olean/HeytingLean/LambdaIR
rm -rf artifacts/compiler/ir/HeytingLean/MiniC artifacts/compiler/olean/HeytingLean/MiniC
rm -rf artifacts/compiler/ir/HeytingLean/C artifacts/compiler/olean/HeytingLean/C
mkdir -p artifacts/compiler/ir/HeytingLean/WPP/Wolfram artifacts/compiler/olean/HeytingLean/WPP/Wolfram
mkdir -p artifacts/compiler/ir/HeytingLean/WPP artifacts/compiler/olean/HeytingLean/WPP
mkdir -p artifacts/compiler/ir/HeytingLean/CLI artifacts/compiler/olean/HeytingLean/CLI
mkdir -p artifacts/compiler/ir/HeytingLean/Core artifacts/compiler/olean/HeytingLean/Core
mkdir -p artifacts/compiler/ir/HeytingLean/LambdaIR artifacts/compiler/olean/HeytingLean/LambdaIR
mkdir -p artifacts/compiler/ir/HeytingLean/MiniC artifacts/compiler/olean/HeytingLean/MiniC
mkdir -p artifacts/compiler/ir/HeytingLean/C artifacts/compiler/olean/HeytingLean/C

if [[ -d .lake/build/ir/HeytingLean/WPP/Wolfram ]]; then
  cp -a .lake/build/ir/HeytingLean/WPP/Wolfram/. artifacts/compiler/ir/HeytingLean/WPP/Wolfram/
fi
if [[ -d .lake/build/ir/HeytingLean/WPP ]]; then
  cp -a .lake/build/ir/HeytingLean/WPP/. artifacts/compiler/ir/HeytingLean/WPP/
fi
if [[ -d .lake/build/ir/HeytingLean/CLI ]]; then
  cp -a .lake/build/ir/HeytingLean/CLI/. artifacts/compiler/ir/HeytingLean/CLI/
fi
if [[ -d .lake/build/ir/HeytingLean/Core ]]; then
  cp -a .lake/build/ir/HeytingLean/Core/. artifacts/compiler/ir/HeytingLean/Core/
fi
if [[ -d .lake/build/ir/HeytingLean/LambdaIR ]]; then
  cp -a .lake/build/ir/HeytingLean/LambdaIR/. artifacts/compiler/ir/HeytingLean/LambdaIR/
fi
if [[ -d .lake/build/ir/HeytingLean/MiniC ]]; then
  cp -a .lake/build/ir/HeytingLean/MiniC/. artifacts/compiler/ir/HeytingLean/MiniC/
fi
if [[ -d .lake/build/ir/HeytingLean/C ]]; then
  cp -a .lake/build/ir/HeytingLean/C/. artifacts/compiler/ir/HeytingLean/C/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/WPP/Wolfram ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/WPP/Wolfram/. artifacts/compiler/olean/HeytingLean/WPP/Wolfram/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/WPP ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/WPP/. artifacts/compiler/olean/HeytingLean/WPP/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/CLI ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/CLI/. artifacts/compiler/olean/HeytingLean/CLI/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/Core ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/Core/. artifacts/compiler/olean/HeytingLean/Core/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/LambdaIR ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/LambdaIR/. artifacts/compiler/olean/HeytingLean/LambdaIR/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/MiniC ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/MiniC/. artifacts/compiler/olean/HeytingLean/MiniC/
fi
if [[ -d .lake/build/lib/lean/HeytingLean/C ]]; then
  cp -a .lake/build/lib/lean/HeytingLean/C/. artifacts/compiler/olean/HeytingLean/C/
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
