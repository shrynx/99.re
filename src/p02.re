/* Find the last but one element of a list. */
let rec last_but_one = (list) =>
  switch list {
  | []
  | [_] => None
  | [x, y] => Some((x, y))
  | [_, ...xs] => last_but_one(xs)
  };
