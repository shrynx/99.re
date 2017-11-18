/* Construct all spanning trees. */
type graph('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

let split = (v, tvs, es) =>
  List.partition(((x, y)) => List.mem(x, tvs) && y == v || List.mem(y, tvs) && x == v, es);

let add_edge = (e, list) =>
  switch list {
  | [] => [[e]]
  | es => List.rev_map((x) => [e, ...x], es)
  };

let s_tree = (g) => {
  let rec collect = (acc, tvs, es, list) =>
    switch list {
    | [] => acc
    | [v, ...tl] =>
      let (ps, qs) = split(v, tvs, es);
      if (ps == []) {
        []
      } else {
        collect(
          List.fold_left((new_acc, p) => List.rev_append(add_edge(p, acc), new_acc), [], ps),
          [v, ...tvs],
          qs,
          tl
        )
      }
    };
  collect([], [List.hd(g.nodes)], g.edges, List.tl(g.nodes))
};
