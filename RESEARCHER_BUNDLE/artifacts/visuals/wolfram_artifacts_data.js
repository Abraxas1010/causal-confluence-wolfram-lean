// Proof-map → artifact bridge for Wolfram/WPP formalization.
//
// Used by: `wolfram_2d.html`, `wolfram_3d.html`, `wm148_2d.html`, `wm148_3d.html`.
// Paths are relative to `RESEARCHER_BUNDLE/artifacts/visuals/`.
//
// NOTE: Keep keys in sync with Lean declaration names.

window.WOLFRAM_ARTIFACTS = {
  "HeytingLean.WPP.Wolfram.Counterexamples.confluence_causal_invariance_independent": {
    title: "Main theorem: Confluence and causal invariance are independent",
    links: [
      { label: "CE1 combined (SVG)", href: "./ce1_depth3_combined.svg" },
      { label: "CE2 combined (SVG)", href: "./ce2_depth2_combined.svg" },
      { label: "Interactive multiway viewer (CE1)", href: "../wolfram_viewer.html?demo=ce1" },
      { label: "Interactive multiway viewer (CE2)", href: "../wolfram_viewer.html?demo=ce2" }
    ]
  },

  "HeytingLean.WPP.Wolfram.Counterexamples.CE1.confluentNF": {
    title: "CE1: Confluent ∧ ¬CausalInvariant",
    preview: { src: "./ce1_depth3_combined.svg", alt: "CE1 combined multiway+branchial graph" },
    links: [
      { label: "CE1 multiway graph (SVG, depth 3)", href: "./ce1_depth3_multiway.svg" },
      { label: "CE1 branchial graph (SVG)", href: "./ce1_depth3_branchial.svg" },
      { label: "CE1 combined (SVG)", href: "./ce1_depth3_combined.svg" },
      { label: "Interactive multiway viewer (CE1)", href: "../wolfram_viewer.html?demo=ce1" },
      { label: "Lean-generated bounded multiway JSON", href: "../generated_ce1.json" }
    ]
  },
  "HeytingLean.WPP.Wolfram.Counterexamples.CE1.not_causalInvariant": {
    title: "CE1: Confluent ∧ ¬CausalInvariant",
    preview: { src: "./ce1_depth3_combined.svg", alt: "CE1 combined multiway+branchial graph" },
    links: [
      { label: "CE1 multiway graph (SVG, depth 3)", href: "./ce1_depth3_multiway.svg" },
      { label: "CE1 branchial graph (SVG)", href: "./ce1_depth3_branchial.svg" },
      { label: "CE1 combined (SVG)", href: "./ce1_depth3_combined.svg" },
      { label: "Interactive multiway viewer (CE1)", href: "../wolfram_viewer.html?demo=ce1" },
      { label: "Lean-generated bounded multiway JSON", href: "../generated_ce1.json" }
    ]
  },

  "HeytingLean.WPP.Wolfram.Counterexamples.CE2.causalInvariant": {
    title: "CE2: CausalInvariant ∧ ¬Confluent",
    preview: { src: "./ce2_depth2_combined.svg", alt: "CE2 combined multiway+branchial graph" },
    links: [
      { label: "CE2 multiway graph (SVG, depth 2)", href: "./ce2_depth2_multiway.svg" },
      { label: "CE2 branchial graph (SVG)", href: "./ce2_depth2_branchial.svg" },
      { label: "CE2 combined (SVG)", href: "./ce2_depth2_combined.svg" },
      { label: "Interactive multiway viewer (CE2)", href: "../wolfram_viewer.html?demo=ce2" },
      { label: "Lean-generated bounded multiway JSON", href: "../generated_ce2.json" }
    ]
  },
  "HeytingLean.WPP.Wolfram.Counterexamples.CE2.not_confluentNF": {
    title: "CE2: CausalInvariant ∧ ¬Confluent",
    preview: { src: "./ce2_depth2_combined.svg", alt: "CE2 combined multiway+branchial graph" },
    links: [
      { label: "CE2 multiway graph (SVG, depth 2)", href: "./ce2_depth2_multiway.svg" },
      { label: "CE2 branchial graph (SVG)", href: "./ce2_depth2_branchial.svg" },
      { label: "CE2 combined (SVG)", href: "./ce2_depth2_combined.svg" },
      { label: "Interactive multiway viewer (CE2)", href: "../wolfram_viewer.html?demo=ce2" },
      { label: "Lean-generated bounded multiway JSON", href: "../generated_ce2.json" }
    ]
  },

  "HeytingLean.WPP.Wolfram.WM148.causalInvariant": {
    title: "WM148: causal invariance (fresh-vertex semantics)",
    preview: { src: "./wm148_depth3_multiway.svg", alt: "WM148 bounded multiway graph (depth 3)" },
    links: [
      { label: "WM148 multiway graph (SVG, depth 3)", href: "./wm148_depth3_multiway.svg" },
      { label: "WM148 import graph (SVG)", href: "./wm148_import_graph.svg" },
      { label: "WM148 import graph (HTML)", href: "./wm148_import_graph.html" },
      { label: "Interactive multiway viewer (WM148)", href: "../wolfram_viewer.html?demo=wm148" },
      { label: "Lean-generated bounded multiway JSON", href: "../generated_wm148_depth3.json" }
    ]
  },
  "HeytingLean.WPP.Wolfram.SystemFresh.CausalInvariant": {
    title: "Fresh-vertex semantics: causal invariance predicate",
    links: [
      { label: "WM148 multiway graph (SVG, depth 3)", href: "./wm148_depth3_multiway.svg" },
      { label: "Interactive multiway viewer (WM148)", href: "../wolfram_viewer.html?demo=wm148" }
    ]
  },

  // Included once `wolfram_proofs.json` is regenerated with the GC modules.
  "HeytingLean.WPP.Wolfram.Counterexamples.CE1.causalGraphGC_iso_short_long": {
    title: "CE1: Observable-event (GC) causal graphs are isomorphic",
    links: [
      { label: "CE1 combined (SVG)", href: "./ce1_depth3_combined.svg" },
      { label: "Interactive multiway viewer (CE1)", href: "../wolfram_viewer.html?demo=ce1" }
    ]
  }
};
