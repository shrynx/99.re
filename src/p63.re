/* Construct a complete binary tree */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec split_n = (lst, acc, n) =>
  switch (n, lst) {
  | (0, _) => (List.rev(acc), lst)
  | (_, []) => (List.rev(acc), [])
  | (_, [h, ...t]) => split_n(t, [h, ...acc], n - 1)
  };

let rec myflatten = (p, c) =>
  switch (p, c) {
  | (p, []) => List.map((x) => Node(x, Leaf, Leaf), p)
  | ([x, ...t], [y]) => [Node(x, y, Leaf), ...myflatten(t, [])]
  | ([ph, ...pt], [x, y, ...t]) => [Node(ph, x, y), ...myflatten(pt, t)]
  | _ => invalid_arg("myflatten")
  };

let complete_binary_tree = (list) =>
  switch list {
  | [] => Leaf
  | lst =>
    let rec aux = (l, list) =>
      switch list {
      | [] => []
      | lst =>
        let (p, c) = split_n(lst, [], 1 lsl l);
        myflatten(p, aux(l + 1, c))
      };
    List.hd(aux(0, lst))
  };
