/* Determine the internal path length of a tree.  */
type mult_tree('a) =
  | T('a, list(mult_tree('a)));

let rec ipl_sub = (len, T(_, sub)) =>
  List.fold_left((sum, t) => sum + ipl_sub(len + 1, t), len, sub);

let ipl = (t) => ipl_sub(0, t);
