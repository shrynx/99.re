/* Generate a random permutation of the elements of a list. */
let permutation = (list) => {
  let rec extract = (acc, n, list) =>
    switch list {
    | [] => raise(Not_found)
    | [x, ...xs] => n == 0 ? (x, acc @ xs) : extract([x, ...acc], n - 1, xs)
    };
  let extract_rand = (list, len) => extract([], Random.int(len), list);
  let rec aux = (acc, list, len) =>
    len == 0 ?
      acc :
      {
        let (picked, rest) = extract_rand(list, len);
        aux([picked, ...acc], rest, len - 1)
      };
  aux([], list, List.length(list))
};
