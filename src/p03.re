/* Find the K'th element of a list. The first element in the list is number 1. */
let rec element_at = (k, list) =>
  switch list {
  | [] => None
  | [x, ...xs] => k == 1 ? Some(x) : element_at(k - 1, xs)
  };
