/* Construct the minimal spanning tree. */
type graph('a) = {
  nodes: list('a),
  edges: list(('a, 'a, int))
};

let split = (v, tvs, es) =>
  List.partition(((x, y, _)) => List.mem(x, tvs) && y == v || List.mem(y, tvs) && x == v, es);

let compare_weight = ((_, _, w1), (_, _, w2)) => compare(w1, w2);

let min_weight = (l) =>
  List.fold_left(
    (min, x) =>
      if (compare_weight(x, min) < 0) {
        x
      } else {
        min
      },
    List.hd(l),
    List.tl(l)
  );

let add_edge = (e, list) =>
  switch list {
  | [] => [[e]]
  | es => List.rev_map((x) => [e, ...x], es)
  };

let ms_tree = (g) => {
  let rec collect = (acc, tvs, es, list) =>
    switch list {
    | [] => acc
    | [v, ...tl] =>
      let (ps, qs) = split(v, tvs, es);
      if (ps == []) {
        []
      } else {
        collect(add_edge(min_weight(ps), acc), [v, ...tvs], qs, tl)
      }
    };
  collect([], [List.hd(g.nodes)], g.edges, List.tl(g.nodes))
};
