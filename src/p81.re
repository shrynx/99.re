/* Path from one node to another one. */
type graph_term('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

let neighbors = (g, a, cond) => {
  let edge = (l, (b, c)) =>
    if (b == a && cond(c)) {
      [c, ...l]
    } else if (c == a && cond(b)) {
      [b, ...l]
    } else {
      l
    };
  List.fold_left(edge, [], g.edges)
};

let rec list_path = (g, a, to_b) =>
  switch to_b {
  | [] => assert false /* [to_b] contains the path to [b]. */
  | [a', ..._] =>
    if (a' == a) {
      [to_b]
    } else {
      let n = neighbors(g, a', (c) => ! List.mem(c, to_b));
      List.concat(List.map((c) => list_path(g, a, [c, ...to_b]), n))
    }
  };

let paths = (g, a, b) => {
  assert (a != b);
  list_path(g, a, [b])
};
