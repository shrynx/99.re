/* Replicate the elements of a list a given number of times. */
let replicate = (list, n) => {
  let rec prepend = (n, acc, x) => n == 0 ? acc : prepend(n - 1, [x, ...acc], x);
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [x, ...xs] => aux(prepend(n, acc, x), xs)
    };
  aux([], List.rev(list))
};
