/* Run-length encoding of a list. */
let encode = (list) => {
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => []
    | [x] => [(count + 1, x), ...acc]
    | [x, ...[y, ..._] as z] =>
      x == y ? aux(count + 1, acc, z) : aux(0, [(count + 1, x), ...acc], z)
    };
  List.rev(aux(0, [], list))
};
