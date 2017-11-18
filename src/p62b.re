/* Collect the nodes at a given level in a list. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec at_level = (tree, l) =>
  switch tree {
  | Leaf => []
  | Node(c, left, right) => l == 1 ? [c] : at_level(left, l - 1) @ at_level(right, l - 1)
  };
