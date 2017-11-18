/* Remove the K'th element from a list. */
let rec remove_at = (list, n) =>
  switch list {
  | [] => []
  | [x, ...xs] => n == 0 ? xs : [x, ...remove_at(xs, n - 1)]
  };
