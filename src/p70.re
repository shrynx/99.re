/* Tree construction from a node string. */
type mult_tree('a) =
  | T('a, list(mult_tree('a)));

let rec add_string_of_tree = (buf, T(c, sub)) => {
  Buffer.add_char(buf, c);
  List.iter(add_string_of_tree(buf), sub);
  Buffer.add_char(buf, '^')
};

let string_of_tree = (t) => {
  let buf = Buffer.create(128);
  add_string_of_tree(buf, t);
  Buffer.contents(buf)
};

let rec tree_of_substring = (t, s, i, len) =>
  if (i >= len || s.[i] == '^') {
    (List.rev(t), i + 1)
  } else {
    let (sub, j) = tree_of_substring([], s, i + 1, len);
    tree_of_substring([T(s.[i], sub), ...t], s, j, len)
  };

let tree_of_string = (s) =>
  switch (tree_of_substring([], s, 0, String.length(s))) {
  | ([t], _) => t
  | _ => failwith("tree_of_string")
  };
