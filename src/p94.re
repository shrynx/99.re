/* K-regular simple graphs. */
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
  | l => rev_concat_map((x) => List.rev_map((y) => [x, ...y], permutation(l -- x)), l)
  };

let mappings = (l1, l2) => permutation(l2) |> List.rev_map(List.combine(l1));

let f = (mapping, x) => List.assoc(x, mapping);

let is_isomorphism = (g1, g2) =>
  if (List.length(g1.nodes) == List.length(g2.nodes)
      && List.length(g1.edges) == List.length(g2.edges)) {
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
  } else {
    false
  };

/* for k-regular */
let rev_concat_map = (f, l) => List.fold_left((acc, x) => List.rev_append(f(x), acc), [], l);

let rm_dup = (f, l) => {
  let rec rm = (x, acc, list) =>
    switch list {
    | [] => List.rev(acc)
    | [hd, ...tl] when f(x, hd) => rm(x, acc, tl)
    | [hd, ...tl] => rm(x, [hd, ...acc], tl)
    };
  let rec collect = (acc, list) =>
    switch list {
    | [] => List.rev(acc)
    | [hd, ...tl] => collect([hd, ...acc], rm(hd, [], tl))
    };
  collect([], l)
};

let singleton = (l) => List.rev_map((x) => (x, []), l);

let rec pick = (m, list) =>
  switch list {
  | [] => []
  | l when m == 1 => List.rev_map((x) => [x], l)
  | [hd, ...tl] => List.map((x) => [hd, ...x], pick(m - 1, tl)) @ pick(m, tl)
  };

let rec is_valid = (k, v, nvs, es, list) =>
  switch list {
  | [] => true
  | [hd, ...tl] when List.mem(hd, nvs) => false
  | [hd, ...tl] =>
    let l = List.assoc(hd, es);
    ! List.mem(v, l) && 1 + List.length(l) <= k && is_valid(k, v, nvs, es, tl)
  };

let link = (v, p, es) =>
  List.fold_left(
    (acc, (x, ys)) =>
      if (x == v) {
        [(v, List.rev_append(ys, p)), ...acc]
      } else if (List.mem(x, p)) {
        [(x, [v, ...ys]), ...acc]
      } else {
        [(x, ys), ...acc]
      },
    [],
    es
  );

let add = (l, k, v, es) => {
  let nvs = List.assoc(v, es);
  let nvs_len = List.length(nvs);
  if (nvs_len == k) {
    [es]
  } else {
    let picks = pick(k - nvs_len, l -- v) |> List.filter((p) => is_valid(k, v, nvs, es, p));
    List.rev_map((p) => link(v, p, es), picks)
  }
};

let create_edges = (l) => {
  let sl = List.sort(compare, l);
  let rec collect = (acc, list) =>
    switch list {
    | [] => List.sort(compare, acc)
    | [(x, ys), ...tl] =>
      collect(
        List.fold_left(
          (acc, y) =>
            if (List.mem((x, y), acc) || List.mem((y, x), acc)) {
              acc
            } else {
              [(x, y), ...acc]
            },
          acc,
          ys
        ),
        tl
      )
    };
  collect([], sl)
};

let dummy_nl = (n) => {
  let rec collect = (acc, k) =>
    if (k == 0) {
      acc
    } else {
      collect([k, ...acc], k - 1)
    };
  collect([], n)
};

let k_regular = (n, k) =>
  if (k > n - 1) {
    0
  } else {
    let l = dummy_nl(n);
    let rec build = (ess, list) =>
      switch list {
      | [] => ess
      | [v, ...vs] => build(rev_concat_map(add(l, k, v), ess), vs)
      };
    build([singleton(l)], l)
    |> List.rev_map((x) => {nodes: l, edges: create_edges(x)})
    |> rm_dup(is_isomorphism)
    |> List.length
  };
