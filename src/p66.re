/* Layout a binary tree (another). */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let layout_binary_tree_3 = {
  let rec translate_x = (d, tree) =>
    switch tree {
    | Leaf => Leaf
    | Node((v, x, y), l, r) => Node((v, x + d, y), translate_x(d, l), translate_x(d, r))
    };
  let rec dist = (lr, rl) =>
    switch (lr, rl) {
    | ([lrx, ...ltl], [rlx, ...rtl]) => max(lrx - rlx, dist(ltl, rtl))
    | ([], _)
    | (_, []) => 0
    };
  let rec merge_profiles = (p1, p2) =>
    switch (p1, p2) {
    | ([x1, ...tl1], [_, ...tl2]) => [x1, ...merge_profiles(tl1, tl2)]
    | ([], _) => p2
    | (_, []) => p1
    };
  let rec layout = (depth, tree) =>
    switch tree {
    | Leaf => ([], Leaf, [])
    | Node(v, l, r) =>
      let (ll, l', lr) = layout(depth + 1, l);
      let (rl, r', rr) = layout(depth + 1, r);
      let d = 1 + dist(lr, rl) / 2;
      let ll = List.map((x) => x - d, ll)
      and lr = List.map((x) => x - d, lr)
      and rl = List.map((+)(d), rl)
      and rr = List.map((+)(d), rr);
      (
        [0, ...merge_profiles(ll, rl)],
        Node((v, 0, depth), translate_x(- d, l'), translate_x(d, r')),
        [0, ...merge_profiles(rr, lr)]
      )
    };
  (t) => {
    let (l, t', _) = layout(1, t);
    let x_min = List.fold_left(min, 0, l);
    translate_x(1 - x_min, t')
  }
};
