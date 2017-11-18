/* Depth-first order graph traversal. */
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
  travel(v, ([], [])) |> snd |> List.rev
};
