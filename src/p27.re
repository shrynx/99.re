/* Group the elements of a set into disjoint subsets. */
let group = (list, sizes) => {
  let initial = List.map((size) => (size, []), sizes);
  let prepend = (p, list) => {
    let emit = (l, acc) => [l, ...acc];
    let rec aux = (emit, acc, list) =>
      switch list {
      | [] => emit([], acc)
      | [(n, l) as h, ...t] =>
        let acc = n > 0 ? emit([(n - 1, [p, ...l]), ...t], acc) : acc;
        aux((l, acc) => emit([h, ...l], acc), acc, t)
      };
    aux(emit, [], list)
  };
  let rec aux = (list) =>
    switch list {
    | [] => [initial]
    | [x, ...xs] => List.concat(List.map(prepend(x), aux(xs)))
    };
  let all = aux(list);
  let complete = List.filter(List.for_all(((x, _)) => x == 0), all);
  List.map(List.map(snd), complete)
};
