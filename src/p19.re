/* Rotate a list N places to the left. */
let split = (list, n) => {
  let rec aux = (i, acc, list) =>
    switch list {
    | [] => (List.rev(acc), [])
    | [h, ...t] as l => i == 0 ? (List.rev(acc), l) : aux(i - 1, [h, ...acc], t)
    };
  aux(n, [], list)
};

let rotate = (list, n) => {
  let len = List.length(list);
  let n = len == 0 ? 0 : (n mod len + len) mod len;
  n == 0 ?
    list :
    {
      let (a, b) = split(list, n);
      b @ a
    }
};
