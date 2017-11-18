/* Von Koch's conjecture */
let get_nodes =
  List.fold_left(
    (l, (x, y)) =>
      (
        if (List.mem(x, l)) {
          []
        } else {
          [x]
        }
      )
      @ (
        if (List.mem(y, l)) {
          l
        } else {
          [y, ...l]
        }
      ),
    []
  );

let gen_list = (n) => {
  let rec gen_list = (n, l) =>
    if (n < 1) {
      l
    } else {
      gen_list(n - 1, [n, ...l])
    };
  gen_list(n, [])
};

let rem_mem = (x) =>
  List.fold_left(
    (l, y) =>
      if (x == y) {
        l
      } else {
        [y, ...l]
      },
    []
  );

let iter_rmd = (f) => {
  let rec iter_rmd = (f, p, l) =>
    switch l {
    | [] => ()
    | [h, ...t] =>
      f(p, h, t);
      iter_rmd(f, p @ [h], t)
    };
  iter_rmd(f, [])
};

let vankoch = (tree) => {
  let nodes = get_nodes(tree);
  let edges = gen_list(List.length(nodes) - 1);
  /* tree, current node, current number, visited edges, nodes and edges left */
  let rec vankoch = (t, v, n, e, enum) =>
    if (t == []) {
      List.iter(((i, n)) => Printf.printf("(%d,%d) ", i, n), enum);
      Printf.printf("\n");
      flush(stdout)
    } else {
      let (x, y) = List.find(((x, y)) => List.mem(x, v) || List.mem(y, v), t);
      let rem_edges =
        List.fold_left(
          (t, (u, v)) =>
            if (x == u && y == v) {
              t
            } else {
              [(u, v), ...t]
            },
          [],
          t
        );
      let (x, y) =
        if (List.mem(x, v)) {
          (x, y)
        } else {
          (y, x)
        };
      let i =
        List.fold_left(
          (i, (z, h)) =>
            if (z == x) {
              h
            } else {
              i
            },
          0,
          enum
        );
      iter_rmd(
        (p, h, t) => {
          let d = abs(i - h);
          if (List.mem(d, e)) {
            vankoch(rem_edges, [y, ...v], p @ t, rem_mem(d, e), [(y, h), ...enum])
          } else {
            ()
          }
        },
        n
      )
    };
  if (tree == []) {
    ()
  } else {
    iter_rmd(
      (p, h, t) => vankoch(tree, [List.hd(nodes)], p @ t, edges, [(List.hd(nodes), h)]),
      nodes
    )
  }
};
