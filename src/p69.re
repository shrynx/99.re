/* Dotstring representation of binary trees. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec dotstring = (t) =>
  switch t {
  | Leaf => ""
  | Node(c, l, r) => c ++ dotstring(l) ++ dotstring(r) ++ ".."
  };
