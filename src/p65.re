/* Layout a binary tree. (alternate) */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let layout_binary_tree_2 = (t) => {
  let rec height = (tree) =>
    switch tree {
    | Leaf => 0
    | Node(_, l, r) => 1 + max(height(l), height(r))
    };
  let tree_height = height(t);
  let rec find_missing_left = (depth, tree) =>
    switch tree {
    | Leaf => tree_height - depth
    | Node(_, l, _) => find_missing_left(depth + 1, l)
    };
  let translate_dst = 1 lsl find_missing_left(0, t) - 1;
  let rec layout = (depth, x_root, tree) =>
    switch tree {
    | Leaf => Leaf
    | Node(x, l, r) =>
      let spacing = 1 lsl (tree_height - depth - 1);
      let l' = layout(depth + 1, x_root - spacing, l)
      and r' = layout(depth + 1, x_root + spacing, r);
      Node((x, x_root, depth), l', r')
    };
  layout(1, 1 lsl (tree_height - 1) - translate_dst, t)
};
