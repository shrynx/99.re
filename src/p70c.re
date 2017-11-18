/* Count the nodes of a multiway tree. */
type mult_tree('a) =
  | T('a, list(mult_tree('a)));

let rec count_nodes = (T(_, sub)) => List.fold_left((n, t) => n + count_nodes(t), 1, sub);
