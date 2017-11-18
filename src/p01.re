/* Find the last element of a list. */
let rec last = (list) =>
  switch list {
  | [] => None
  | [x] => Some(x)
  | [_, ...xs] => last(xs)
  };
