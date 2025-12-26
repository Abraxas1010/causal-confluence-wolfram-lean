#!/usr/bin/env python3
"""
Convert `wolfram_multiway_demo` JSON into GraphViz DOT graphs.

Input schema (see `HeytingLean.CLI.WolframMultiwayMain`):
  - nodes: Array[Array[Nat]]        (counts over a fixed basis)
  - edges: Array[{src,dst,label}]   (label includes ruleIdx and sigma)
  - levels: Array[Array[Nat]]       (node ids per depth)
  - branchial: Array[{i,j}]

Outputs (for a given prefix):
  - <prefix>_multiway.dot
  - <prefix>_branchial.dot
  - <prefix>_combined.dot
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
from typing import Any, Dict, List, Optional, Tuple


def _expr_str(expr: List[int]) -> str:
    if len(expr) == 0:
        return "[]"
    return "[" + ",".join(str(x) for x in expr) + "]"


def _basis_strings(data: Dict[str, Any]) -> Optional[List[str]]:
    basis = data.get("basis_len1_len2")
    if not isinstance(basis, list):
        return None
    out: List[str] = []
    for e in basis:
        if isinstance(e, list) and all(isinstance(x, int) for x in e):
            out.append(_expr_str(e))
        else:
            out.append("?")
    return out


def _node_label(node_id: int, counts: List[int], basis: Optional[List[str]], max_items: int = 10) -> str:
    nz: List[Tuple[int, int]] = [(i, c) for (i, c) in enumerate(counts) if isinstance(c, int) and c != 0]
    nz.sort(key=lambda p: (-p[1], p[0]))
    header = f"id={node_id}"
    if not nz:
        return header + r"\n∅"
    items: List[str] = []
    for (i, c) in nz[:max_items]:
        b = basis[i] if basis is not None and i < len(basis) else f"b{i}"
        items.append(f"{b}×{c}")
    if len(nz) > max_items:
        items.append("…")
    return header + r"\n" + r"\n".join(items)


def _depth_map(levels: Optional[List[List[int]]], n_nodes: int) -> Dict[int, int]:
    depth: Dict[int, int] = {}
    if not isinstance(levels, list):
        return depth
    for d, lvl in enumerate(levels):
        if not isinstance(lvl, list):
            continue
        for node_id in lvl:
            if isinstance(node_id, int) and node_id not in depth:
                depth[node_id] = d
    for i in range(n_nodes):
        depth.setdefault(i, 0)
    return depth


def _edge_label(edge: Dict[str, Any]) -> str:
    label = edge.get("label")
    if not isinstance(label, dict):
        return ""
    rule_idx = label.get("ruleIdx")
    sigma = label.get("sigma")
    if isinstance(rule_idx, int) and isinstance(sigma, list) and len(sigma) == 2:
        if all(isinstance(x, int) for x in sigma):
            return f"r{rule_idx} σ=({sigma[0]},{sigma[1]})"
    return ""


def _dot_header(rankdir: str = "LR") -> List[str]:
    return [
        "digraph G {",
        f'  graph [rankdir="{rankdir}", bgcolor="white"];',
        '  node  [shape="box", fontname="monospace", fontsize="10"];',
        '  edge  [fontname="monospace", fontsize="9"];',
    ]


def _dot_footer() -> List[str]:
    return ["}"]


def _emit_levels(dot: List[str], levels: Optional[List[List[int]]]) -> None:
    if not isinstance(levels, list):
        return
    for d, lvl in enumerate(levels):
        if not isinstance(lvl, list):
            continue
        nodes = [f"n{node_id}" for node_id in lvl if isinstance(node_id, int)]
        if not nodes:
            continue
        dot.append(f"  subgraph cluster_depth_{d} {{")
        dot.append('    color="lightgray"; style="rounded"; penwidth="1";')
        dot.append(f'    label="depth {d}"; fontsize="10";')
        dot.append("    " + " ".join(nodes) + ";")
        dot.append("  }")


def write_multiway_dot(data: Dict[str, Any], out_path: str, include_branchial: bool) -> None:
    nodes = data.get("nodes")
    edges = data.get("edges")
    branchial = data.get("branchial")
    levels = data.get("levels")

    if not isinstance(nodes, list) or not isinstance(edges, list):
        raise ValueError("expected keys: nodes (list), edges (list)")

    basis = _basis_strings(data)
    _depth_map(levels if isinstance(levels, list) else None, len(nodes))

    dot: List[str] = _dot_header(rankdir="LR")

    for i, cnts in enumerate(nodes):
        if not isinstance(cnts, list):
            cnts = []
        label = _node_label(i, cnts, basis)
        dot.append(f'  n{i} [label="{label}"];')

    _emit_levels(dot, levels if isinstance(levels, list) else None)

    for e in edges:
        if not isinstance(e, dict):
            continue
        src = e.get("src")
        dst = e.get("dst")
        if not isinstance(src, int) or not isinstance(dst, int):
            continue
        lab = _edge_label(e)
        if lab:
            dot.append(f'  n{src} -> n{dst} [label="{lab}"];')
        else:
            dot.append(f"  n{src} -> n{dst};")

    if include_branchial and isinstance(branchial, list):
        for be in branchial:
            if not isinstance(be, dict):
                continue
            i = be.get("i")
            j = be.get("j")
            if not isinstance(i, int) or not isinstance(j, int):
                continue
            dot.append(f'  n{i} -> n{j} [dir="none", color="royalblue", style="dashed", label="branchial"];')

    dot.extend(_dot_footer())

    os.makedirs(os.path.dirname(out_path) or ".", exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(dot) + "\n")


def write_branchial_dot(data: Dict[str, Any], out_path: str) -> None:
    nodes = data.get("nodes")
    branchial = data.get("branchial")
    levels = data.get("levels")

    if not isinstance(nodes, list) or not isinstance(branchial, list):
        raise ValueError("expected keys: nodes (list), branchial (list)")

    basis = _basis_strings(data)

    dot: List[str] = _dot_header(rankdir="LR")
    for i, cnts in enumerate(nodes):
        if not isinstance(cnts, list):
            cnts = []
        label = _node_label(i, cnts, basis)
        dot.append(f'  n{i} [label="{label}"];')

    _emit_levels(dot, levels if isinstance(levels, list) else None)

    for be in branchial:
        if not isinstance(be, dict):
            continue
        i = be.get("i")
        j = be.get("j")
        if not isinstance(i, int) or not isinstance(j, int):
            continue
        dot.append(f'  n{i} -> n{j} [dir="none", color="royalblue", style="dashed"];')

    dot.extend(_dot_footer())

    os.makedirs(os.path.dirname(out_path) or ".", exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(dot) + "\n")


def shutil_which(cmd: str) -> Optional[str]:
    for p in os.environ.get("PATH", "").split(os.pathsep):
        exe = os.path.join(p, cmd)
        if os.path.isfile(exe) and os.access(exe, os.X_OK):
            return exe
    return None


def try_render_svg(dot_path: str) -> Optional[str]:
    if not shutil_which("dot"):
        return None
    svg_path = os.path.splitext(dot_path)[0] + ".svg"
    subprocess.run(["dot", "-Tsvg", dot_path, "-o", svg_path], check=False)
    if os.path.exists(svg_path):
        return svg_path
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("input_json", help="Path to wolfram_multiway_demo JSON output")
    ap.add_argument("output_prefix", help="Output prefix path (without extension)")
    ap.add_argument("--render-svg", action="store_true", help="If GraphViz `dot` exists, also render SVGs")
    args = ap.parse_args()

    with open(args.input_json, "r", encoding="utf-8") as f:
        data = json.load(f)

    prefix = args.output_prefix
    out_multi = prefix + "_multiway.dot"
    out_branchial = prefix + "_branchial.dot"
    out_combined = prefix + "_combined.dot"

    write_multiway_dot(data, out_multi, include_branchial=False)
    write_branchial_dot(data, out_branchial)
    write_multiway_dot(data, out_combined, include_branchial=True)

    if args.render_svg:
        for p in (out_multi, out_branchial, out_combined):
            try_render_svg(p)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

