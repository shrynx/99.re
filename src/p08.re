/* Eliminate consecutive duplicates of list elements. */
let rec compress = (list) =>
  switch list {
  | [] => []
  | [x] => [x]
  | [x, ...[y, ..._] as z] => x == y ? compress(z) : [x, ...compress(z)]
  };
