/* Modified run-length encoding. */
type rle('a) =
  | One('a)
  | Many(int, 'a);

let modified_encode = (list) => {
  let create_tuple = (count, elem) => count == 1 ? One(elem) : Many(count, elem);
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => []
    | [x] => [create_tuple(count + 1, x), ...acc]
    | [x, ...[y, ..._] as z] =>
      x == y ? aux(count + 1, acc, z) : aux(0, [create_tuple(count + 1, x), ...acc], z)
    };
  List.rev(aux(0, [], list))
};
