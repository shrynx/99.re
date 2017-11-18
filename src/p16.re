/* Drop every n'th element from a list. */
let drop = (list, n) => {
  let rec aux = (i, list) =>
    switch list {
    | [] => []
    | [x, ...xs] => i == n ? aux(1, xs) : [x, ...aux(i + 1, xs)]
    };
  aux(1, list)
};
