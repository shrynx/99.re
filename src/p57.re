/* Binary search trees (dictionaries). */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec insert = (tree, x) =>
  switch tree {
  | Leaf => Node(x, Leaf, Leaf)
  | Node(y, l, r) =>
    if (x == y) {
      tree
    } else if (x < y) {
      Node(y, insert(l, x), r)
    } else {
      Node(y, l, insert(r, x))
    }
  };

let construct = (l) => List.fold_left(insert, Leaf, l);
