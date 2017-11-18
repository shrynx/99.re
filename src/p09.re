/*  Pack consecutive duplicates of list elements into sublists. */
let pack = (list) => {
  let rec aux = (curr, acc, list) =>
    switch list {
    | [] => []
    | [x] => [[x, ...curr], ...acc]
    | [x, ...[y, ..._] as z] =>
      x == y ? aux([x, ...curr], acc, z) : aux([], [[x, ...curr], ...acc], z)
    };
  List.rev(aux([], [], list))
};
