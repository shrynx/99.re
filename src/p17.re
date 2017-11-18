/* Split a list into two parts; the length of the first part is given. */
let split = (list, n) => {
  let rec aux = (i, acc, list) =>
    switch list {
    | [] => (List.rev(acc), [])
    | [x, ...xs] as z => i == 0 ? (List.rev(acc), z) : aux(i - 1, [x, ...acc], xs)
    };
  aux(n, [], list)
};
