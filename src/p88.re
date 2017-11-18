/* Connected components. */
type grpah('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

let depth_traversal = (g, v) => {
  let rec neighbours = (v, acc, list) =>
    switch list {
    | [] => acc
    | [(x, y), ...tl] =>
      if (x == v) {
        neighbours(v, [y, ...acc], tl)
      } else if (y == v) {
        neighbours(v, [x, ...acc], tl)
      } else {
        neighbours(v, acc, tl)
      }
    };
  let rec travel = (s, (m, p)) =>
    if (List.mem(s, m)) {
      (m, p)
    } else {
      List.fold_left(
        ((m, p), x) => travel(x, (m, p)),
        ([s, ...m], [s, ...p]),
        neighbours(s, [], g.edges)
      )
    };
  travel(v, ([], [])) |> snd
};

let (--) = (l1, l2) => List.filter((x) => ! List.mem(x, l2), l1);

let connected_components = (g) => {
  let rec collect = (acc, list) =>
    switch list {
    | [] => acc
    | [v, ...vs] =>
      let p = depth_traversal(g, v);
      collect([p, ...acc], vs -- p)
    };
  collect([], g.nodes)
};
