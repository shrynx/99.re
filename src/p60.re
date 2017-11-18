/* Construct height-balanced binary trees with a given number of nodes. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let min_height = (n) => int_of_float(ceil(log(float(n + 1)) /. log(2.)));

let rec min_nodes = (h) =>
  if (h <= 0) {
    0
  } else if (h == 1) {
    1
  } else {
    min_nodes(h - 1) + min_nodes(h - 2) + 1
  };

let max_nodes = (h) => 1 lsl h - 1;

let rec fold_range = (~f, ~init, n0, n1) =>
  if (n0 > n1) {
    init
  } else {
    fold_range(~f, ~init=f(init, n0), n0 + 1, n1)
  };

let rec max_height_search = (h, n) =>
  if (min_nodes(h) <= n) {
    max_height_search(h + 1, n)
  } else {
    h - 1
  };

let max_height = (n) => max_height_search(0, n);

let add_swap_left_right = (trees) =>
  List.fold_left(
    (a, n) =>
      switch n {
      | Node(v, t1, t2) => [Node(v, t2, t1), ...a]
      | Leaf => a
      },
    trees,
    trees
  );

let rec hbal_tree_nodes_height = (h, n) => {
  assert (min_nodes(h) <= n && n <= max_nodes(h));
  if (h == 0) {
    [Leaf]
  } else {
    let acc = add_hbal_tree_node([], h - 1, h - 2, n);
    let acc = add_swap_left_right(acc);
    add_hbal_tree_node(acc, h - 1, h - 1, n)
  }
}
and add_hbal_tree_node = (l, h1, h2, n) => {
  let min_n1 = max(min_nodes(h1), n - 1 - max_nodes(h2));
  let max_n1 = min(max_nodes(h1), n - 1 - min_nodes(h2));
  fold_range(
    min_n1,
    max_n1,
    ~init=l,
    ~f=
      (l, n1) => {
        let t1 = hbal_tree_nodes_height(h1, n1);
        let t2 = hbal_tree_nodes_height(h2, n - 1 - n1);
        List.fold_left(
          (l, t1) => List.fold_left((l, t2) => [Node('x', t1, t2), ...l], l, t2),
          l,
          t1
        )
      }
  )
};

let hbal_tree_nodes = (n) =>
  fold_range(
    min_height(n),
    max_height(n),
    ~init=[],
    ~f=(l, h) => List.rev_append(hbal_tree_nodes_height(h, n), l)
  );
