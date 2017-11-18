/* Huffman codes. */
module Pq = {
  type t('a) = {
    data: array(list('a)),
    mutable first: int
  };
  let make = () => {data: Array.make(101, []), first: 101};
  let add = (q, p, x) => {
    q.data[p] = [x, ...q.data[p]];
    q.first = min(p, q.first)
  };
  let get_min = (q) =>
    if (q.first == 101) {
      None
    } else {
      switch q.data[q.first] {
      | [] => assert false
      | [x, ...tl] =>
        let p = q.first;
        q.data[q.first] = tl;
        while (q.first < 101 && q.data[q.first] == []) {
          q.first = q.first + 1
        };
        Some((p, x))
      }
    };
};

type tree =
  | Leaf(string)
  | Node(tree, tree);

let rec huffman_tree = (q) =>
  switch (Pq.get_min(q), Pq.get_min(q)) {
  | (Some((p1, t1)), Some((p2, t2))) =>
    Pq.add(q, p1 + p2, Node(t1, t2));
    huffman_tree(q)
  | (Some((_, t)), None)
  | (None, Some((_, t))) => t
  | (None, None) => assert false
  };

let rec prefixes_of_tree = (prefix, tree) =>
  switch tree {
  | Leaf(s) => [(s, prefix)]
  | Node(t0, t1) => prefixes_of_tree(prefix ++ "0", t0) @ prefixes_of_tree(prefix ++ "1", t1)
  };

let huffman = (fs) => {
  if (List.fold_left((s, (_, p)) => s + p, 0, fs) != 100) {
    failwith("huffman: sum of weights must be 100")
  };
  let q = Pq.make();
  List.iter(((s, f)) => Pq.add(q, f, Leaf(s)), fs);
  prefixes_of_tree("", huffman_tree(q))
};
