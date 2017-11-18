/* Layout a binary tree. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let layout_binary_tree_1 = (t) => {
  let rec layout = (depth, x_left, tree) =>
    switch tree {
    | Leaf => (Leaf, x_left)
    | Node(v, l, r) =>
      let (l', l_x_max) = layout(depth + 1, x_left, l);
      let (r', r_x_max) = layout(depth + 1, l_x_max + 1, r);
      (Node((v, l_x_max, depth), l', r'), r_x_max)
    };
  fst(layout(1, 1, t))
};
