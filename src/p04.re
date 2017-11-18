/* Find the number of elements of a list. */
let rec length = (list) =>
  switch list {
  | [] => 0
  | [_, ...xs] => 1 + length(xs)
  };
