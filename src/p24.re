/* Lotto: Draw N different random numbers from the set 1..M. */
let range = (i, j) => {
  let rec aux = (i, j) => i > j ? [] : [i, ...aux(i + 1, j)];
  i > j ? List.rev(aux(j, i)) : aux(i, j)
};

let rand_select = (list, n) => {
  let rec extract = (acc, n, list) =>
    switch list {
    | [] => raise(Not_found)
    | [x, ...xs] => n == 0 ? (x, acc @ xs) : extract([x, ...acc], n - 1, xs)
    };
  let extract_rand = (list, len) => extract([], Random.int(len), list);
  let rec aux = (n, acc, list, len) =>
    n == 0 ?
      acc :
      {
        let (picked, rest) = extract_rand(list, len);
        aux(n - 1, [picked, ...acc], rest, len - 1)
      };
  let len = List.length(list);
  aux(min(n, len), [], list, len)
};

let lotto_select = (i, j) => rand_select(range(1, j), i);
