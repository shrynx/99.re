/* Symmetric binary trees. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

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
