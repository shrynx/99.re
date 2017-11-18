/* Sorting a list of lists according to length of sublists
      a) sort the elements of this list according to their length.
      b) sort the elements of this list according to their length frequency
   */
let rec insert = (cmp, e, list) =>
  switch list {
  | [] => [e]
  | [x, ...xs] as z => cmp(e, x) <= 0 ? [e, ...z] : [x, ...insert(cmp, e, xs)]
  };

let rec sort = (cmp, list) =>
  switch list {
  | [] => []
  | [x, ...xs] => insert(cmp, x, sort(cmp, xs))
  };

/* Sorting according to length : prepend length, sort, remove length */
let length_sort = (lists) => {
  let lists = List.map((list) => (List.length(list), list), lists);
  let lists = sort((a, b) => compare(fst(a), fst(b)), lists);
  List.map(snd, lists)
};

let rle = (list) => {
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => [] /* Can only be reached if original list is Leaf */
    | [x] => [(x, count + 1), ...acc]
    | [x, ...[y, ..._] as z] =>
      x == y ? aux(count + 1, acc, z) : aux(0, [(x, count + 1), ...acc], z)
    };
  aux(0, [], list)
};

let frequency_sort = (lists) => {
  let lengths = List.map(List.length, lists);
  let freq = rle(sort(compare, lengths));
  let by_freq = List.map((list) => (List.assoc(List.length(list), freq), list), lists);
  let sorted = sort((a, b) => compare(fst(a), fst(b)), by_freq);
  List.map(snd, sorted)
};
