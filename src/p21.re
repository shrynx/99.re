/* Insert an element at a given position into a list. */
let rec insert_at = (ele, n, list) =>
  switch list {
  | [] => []
  | [x, ...xs] as z => n == 0 ? [ele, ...z] : [x, ...insert_at(ele, n - 1, xs)]
  };
