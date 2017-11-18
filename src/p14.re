/* Duplicate the elements of a list. */
let rec duplicate = (list) =>
  switch list {
  | [] => []
  | [x, ...xs] => [x, x, ...duplicate(xs)]
  };
