/* Generate-and-test paradigm. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let add_trees_with = (left, right, all) => {
  let add_right_tree = (all, l) => List.fold_left((a, r) => [Node('x', l, r), ...a], all, right);
  List.fold_left(add_right_tree, all, left)
};

let rec cbal_tree = (n) =>
  if (n == 0) {
    [Leaf]
  } else if (n mod 2 == 1) {
    let t = cbal_tree(n / 2);
    add_trees_with(t, t, [])
  } else {
    /* n even: n-1 nodes for the left & right subtrees altogether. */
    let t1 = cbal_tree(n / 2 - 1);
    let t2 = cbal_tree(n / 2);
    add_trees_with(t1, t2, add_trees_with(t2, t1, []))
  };

let rec is_mirror = (t1, t2) =>
  switch (t1, t2) {
  | (Leaf, Leaf) => true
  | (Node(_, l1, r1), Node(_, l2, r2)) => is_mirror(l1, r2) && is_mirror(r1, l2)
  | _ => false
  };

let is_symmetric = (tree) =>
  switch tree {
  | Leaf => true
  | Node(_, l, r) => is_mirror(l, r)
  };

let sym_cbal_trees = (n) => List.filter(is_symmetric, cbal_tree(n));
