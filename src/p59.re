/* Construct height-balanced binary trees. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let add_trees_with = (left, right, all) => {
  let add_right_tree = (all, l) => List.fold_left((a, r) => [Node('x', l, r), ...a], all, right);
  List.fold_left(add_right_tree, all, left)
};

let rec hbal_tree = (n) =>
  if (n == 0) {
    [Leaf]
  } else if (n == 1) {
    [Node('x', Leaf, Leaf)]
  } else {
    /* [add_trees_with left right trees] is defined in a question above. */
    let t1 = hbal_tree(n - 1)
    and t2 = hbal_tree(n - 2);
    add_trees_with(t1, t1, add_trees_with(t1, t2, add_trees_with(t2, t1, [])))
  };
