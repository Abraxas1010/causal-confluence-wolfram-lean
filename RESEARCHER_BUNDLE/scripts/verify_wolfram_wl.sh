#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

WL_BIN="${WOLFRAM_WOLFRAMSCRIPT:-}"
WL_KIND=""
if [[ -z "$WL_BIN" ]]; then
  if command -v wolframscript >/dev/null 2>&1; then
    WL_BIN="wolframscript"
    WL_KIND="wolframscript"
  elif command -v mathics >/dev/null 2>&1; then
    WL_BIN="mathics"
    WL_KIND="mathics"
  fi
else
  WL_KIND="wolframscript-override"
fi

if [[ -z "$WL_BIN" ]]; then
  echo "[verify_wolfram_wl] skipping: no WL runtime found (wolframscript or mathics)"
  exit 0
fi

echo "[verify_wolfram_wl] using WL runtime ($WL_KIND): $WL_BIN"

LEAN_CE1="artifacts/generated_ce1.json"
LEAN_CE2="artifacts/generated_ce2.json"
LEAN_WM148="artifacts/generated_wm148_wlcheck.json"
WL_CE1="artifacts/wl_generated_ce1.json"
WL_CE2="artifacts/wl_generated_ce2.json"
WL_WM148="artifacts/wl_generated_wm148.json"

if [[ ! -f "$LEAN_CE1" || ! -f "$LEAN_CE2" || ! -f "$LEAN_WM148" ]]; then
  echo "[verify_wolfram_wl] generating Lean JSON via wolfram_multiway_demo"
  lake exe wolfram_multiway_demo >"$LEAN_CE1"
  lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2 >"$LEAN_CE2"
  lake exe wolfram_wm148_demo -- --maxDepth 3 >"$LEAN_WM148"
fi

echo "[verify_wolfram_wl] generating Wolfram Language JSON via tools/wolfram_ce1_ce2.wl"
if [[ "$WL_KIND" == "wolframscript" || "$WL_KIND" == "wolframscript-override" ]]; then
  "$WL_BIN" -code 'Get["tools/wolfram_ce1_ce2.wl"]; Export["artifacts/wl_generated_ce1.json", CE1JSON[3], "JSON"]; Export["artifacts/wl_generated_ce2.json", CE2JSON[2], "JSON"]; Export["artifacts/wl_generated_wm148.json", WM148JSON[3], "JSON"]; Print["ok"];'
elif [[ "$WL_KIND" == "mathics" ]]; then
  TMP_OUT="$(mktemp)"
  "$WL_BIN" --quiet --colors None --code 'Get["tools/wolfram_ce1_ce2.wl"]; Print[HeytingLeanWolframBridge`CE1JSONString[3]]; Print[HeytingLeanWolframBridge`CE2JSONString[2]]; Print[HeytingLeanWolframBridge`WM148JSONString[3]]; Quit[];' >"$TMP_OUT"
  mapfile -t WL_LINES < <(grep -v '^[[:space:]]*$' "$TMP_OUT" || true)
  rm -f "$TMP_OUT"
  if [[ "${#WL_LINES[@]}" -lt 3 ]]; then
    echo "[verify_wolfram_wl] E: mathics did not print three JSON payloads"
    exit 1
  fi
  printf '%s\n' "${WL_LINES[0]}" >"$WL_CE1"
  printf '%s\n' "${WL_LINES[1]}" >"$WL_CE2"
  printf '%s\n' "${WL_LINES[2]}" >"$WL_WM148"
else
  echo "[verify_wolfram_wl] E: unknown WL_KIND=$WL_KIND"
  exit 1
fi

if [[ ! -f "$WL_CE1" || ! -f "$WL_CE2" || ! -f "$WL_WM148" ]]; then
  echo "[verify_wolfram_wl] E: Wolfram Language did not produce expected JSON outputs"
  echo "  missing: $WL_CE1 or $WL_CE2 or $WL_WM148"
  exit 1
fi

echo "[verify_wolfram_wl] comparing canonicalized JSON (order-insensitive object keys)"
python3 - <<'PY'
import json
import sys
from pathlib import Path

def canonical(x):
    if isinstance(x, dict):
        return {k: canonical(x[k]) for k in sorted(x.keys())}
    if isinstance(x, list):
        return [canonical(v) for v in x]
    return x

def load(p):
    return json.loads(Path(p).read_text(encoding="utf-8"))

pairs = [
    ("artifacts/generated_ce1.json", "artifacts/wl_generated_ce1.json"),
    ("artifacts/generated_ce2.json", "artifacts/wl_generated_ce2.json"),
    ("artifacts/generated_wm148_wlcheck.json", "artifacts/wl_generated_wm148.json"),
]

ok = True
for a, b in pairs:
    ja = canonical(load(a))
    jb = canonical(load(b))
    if ja != jb:
        ok = False
        print(f"E: mismatch: {a} != {b}")
        # print a tiny summary
        def keys(obj):
            return list(obj.keys()) if isinstance(obj, dict) else None
        if isinstance(ja, dict) and isinstance(jb, dict):
            ka, kb = set(ja.keys()), set(jb.keys())
            print("  key-diff:", sorted(ka ^ kb))
        break
    else:
        print(f"ok: {a} == {b}")

if not ok:
    sys.exit(1)
PY

echo "[verify_wolfram_wl] OK"
