#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

WL_BIN="${WOLFRAM_WOLFRAMSCRIPT:-}"
if [[ -z "$WL_BIN" ]]; then
  if command -v wolframscript >/dev/null 2>&1; then
    WL_BIN="wolframscript"
  fi
fi

if [[ -z "$WL_BIN" ]]; then
  echo "[verify_wolfram_wl] skipping: wolframscript not found (set WOLFRAM_WOLFRAMSCRIPT=... to override)"
  exit 0
fi

echo "[verify_wolfram_wl] using wolframscript: $WL_BIN"

LEAN_CE1="artifacts/generated_ce1.json"
LEAN_CE2="artifacts/generated_ce2.json"
WL_CE1="artifacts/wl_generated_ce1.json"
WL_CE2="artifacts/wl_generated_ce2.json"

if [[ ! -f "$LEAN_CE1" || ! -f "$LEAN_CE2" ]]; then
  echo "[verify_wolfram_wl] generating Lean JSON via wolfram_multiway_demo"
  lake exe wolfram_multiway_demo >"$LEAN_CE1"
  lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2 >"$LEAN_CE2"
fi

echo "[verify_wolfram_wl] generating Wolfram Language JSON via tools/wolfram_ce1_ce2.wl"
"$WL_BIN" -code 'Get["tools/wolfram_ce1_ce2.wl"]; Export["artifacts/wl_generated_ce1.json", CE1JSON[3], "JSON"]; Export["artifacts/wl_generated_ce2.json", CE2JSON[2], "JSON"]; Print["ok"];'

if [[ ! -f "$WL_CE1" || ! -f "$WL_CE2" ]]; then
  echo "[verify_wolfram_wl] E: Wolfram Language did not produce expected JSON outputs"
  echo "  missing: $WL_CE1 or $WL_CE2"
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

