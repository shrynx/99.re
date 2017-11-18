/* Run-length encoding of a list (direct solution). */
type rle('a) =
  | One('a)
  | Many(int, 'a);

let encode = (list) => {
  let rle = (count, elem) => count == 0 ? One(elem) : Many(count + 1, elem);
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => []
    | [x] => [rle(count, x), ...acc]
    | [x, ...[y, ..._] as z] =>
      x == y ? aux(count + 1, acc, z) : aux(0, [rle(count, x), ...acc], z)
    };
  List.rev(aux(0, [], list))
};
