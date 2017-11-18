/* Count the leaves of a binary tree. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec count_leaves = (tree) =>
  switch tree {
  | Leaf => 0
  | Node(_, Leaf, Leaf) => 1
  | Node(_, l, r) => count_leaves(l) + count_leaves(r)
  };
