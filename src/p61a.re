/* Collect the leaves of a binary tree in a list. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec leaves = (tree) =>
  switch tree {
  | Leaf => []
  | Node(c, Leaf, Leaf) => [c]
  | Node(_, l, r) => leaves(l) @ leaves(r)
  };
