/* Node degree and graph coloration. */
type grpah('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

let degree = (g, v) => List.filter(((x, y)) => x == v || y == v, g.edges) |> List.length;

let sorted_vs_dg = (g) =>
  List.map((v) => (v, degree(g, v)), g.nodes) |> List.sort(((_, d1), (_, d2)) => - compare(d1, d2));

let rec (><) = (i, j) =>
  if (i > j) {
    j >< i
  } else {
    let rec aux = (acc, k) =>
      if (k < i) {
        acc
      } else {
        aux([k, ...acc], k - 1)
      };
    aux([], j)
  };

let (--) = (l1, x) => List.filter((!=)(x), l1);

let rec cbinding = (v, list) =>
  switch list {
  | [] => None
  | [(x, c), ...tl] =>
    if (x == v) {
      Some((x, c))
    } else {
      cbinding(v, tl)
    }
  };

let coloring = (g) => {
  let sv = sorted_vs_dg(g);
  let (_, d) = List.hd(sv);
  let colors = 1 >< d + 1;
  let rec min_color = (cl, v, vs, list) =>
    switch list {
    | [] => List.hd(cl)
    | [(x, y), ...tl] =>
      if (v != x && v != y) {
        min_color(cl, v, vs, tl)
      } else {
        let vk =
          if (v == x) {
            y
          } else {
            x
          };
        let c = cbinding(vk, vs);
        switch c {
        | None => min_color(cl, v, vs, tl)
        | Some((_, c)) => min_color(cl -- c, v, vs, tl)
        }
      }
    };
  let rec give_color = (vs, es, list) =>
    switch list {
    | [] => vs
    | [(v, _), ...tl] => give_color([(v, min_color(colors, v, vs, es)), ...vs], es, tl)
    };
  give_color([], g.edges, sv) |> List.sort(((_, c1), (_, c2)) => compare(c1, c2))
};
