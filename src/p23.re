/* Extract a given number of randomly selected elements from a list. */
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
