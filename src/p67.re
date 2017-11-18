/* A string representation of binary trees. */
type binary_tree('a) =
  | Leaf
  | Node('a, binary_tree('a), binary_tree('a));

let rec string_of_tree = (tree) =>
  switch tree {
  | Leaf => ""
  | Node(c, l, r) =>
    let data = String.make(1, c);
    switch (l, r) {
    | (Leaf, Leaf) => data
    | (_, _) => data ++ ("(" ++ (string_of_tree(l) ++ ("," ++ (string_of_tree(r) ++ ")"))))
    }
  };
