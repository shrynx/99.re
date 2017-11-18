/* Decode a run-length encoded list. */
type rle('a) =
  | One('a)
  | Many(int, 'a);

let decode = (list) => {
  let rec many = (acc, n, x) => n == 0 ? acc : many([x, ...acc], n - 1, x);
  let rec aux = (acc, list) =>
    switch list {
    | [] => []
    | [One(x), ...xs] => aux([x, ...acc], xs)
    | [Many(n, x), ...xs] => aux(many(acc, n, x), xs)
    };
  aux([], List.rev(list))
};
