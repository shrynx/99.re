/* Flatten a nested list structure. */
type node('a) =
  | One('a)
  | Many(list(node('a)));

let flatten = (list) => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [One(x), ...xs] => aux([x, ...acc], xs)
    | [Many(x), ...xs] => aux(aux(acc, x), xs)
    };
  List.rev(aux([], list))
};
