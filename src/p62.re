/* Collect the internal nodes of a binary tree in a list. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec internals = (tree) =>
  switch tree {
  | Leaf
  | Node(_, Leaf, Leaf) => []
  | Node(c, l, r) => internals(l) @ [c, ...internals(r)]
  };
