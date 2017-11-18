/* Reverse a list. */
let reverse = (list) => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [x, ...xs] => aux([x, ...acc], xs)
    };
  aux([], list)
};
