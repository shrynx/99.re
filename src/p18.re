/* Extract a slice from a list. */
let slice = (list, i, k) => {
  let rec take = (n, list) =>
    switch list {
    | [] => []
    | [x, ...xs] => n == 0 ? [] : [x, ...take(n - 1, xs)]
    };
  let rec drop = (n, list) =>
    switch list {
    | [] => []
    | [_, ...xs] as z => n == 0 ? z : drop(n - 1, xs)
    };
  take(k - i + 1, drop(i, list))
};
