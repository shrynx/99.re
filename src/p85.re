/* Graph isomorphism. */
type graph('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

let rev_concat_map = (f, l) => List.fold_left((acc, x) => List.rev_append(f(x), acc), [], l);

let (--) = (l, x) => List.filter((!=)(x), l);

let rec permutation = (list) =>
  switch list {
  | [] => []
  | [x] => [[x]]
  | l => rev_concat_map((x) => List.map((y) => [x, ...y], permutation(l -- x)), l)
  };

let mappings = (l1, l2) => permutation(l2) |> List.map(List.combine(l1));

let f = (mapping, x) => List.assoc(x, mapping);

let is_isomorphism = (g1, g2) =>
  List.length(g1.nodes) == List.length(g2.nodes) && List.length(g1.edges) == List.length(g2.edges) ?
    {
      let ms = mappings(g1.nodes, g2.nodes);
      let test = (m, (a, b), es2) =>
        List.mem((f(m, a), f(m, b)), es2) || List.mem((f(m, b), f(m, a)), es2);
      let rec test_all = (m, es2, list) =>
        switch list {
        | [] => true
        | [e, ...es1] => test(m, e, es2) && test_all(m, es2, es1)
        };
      let rec test_all_mappings = (list) =>
        switch list {
        | [] => false
        | [m, ...ms] => test_all(m, g2.edges, g1.edges) || test_all_mappings(ms)
        };
      test_all_mappings(ms)
    } :
    false;
