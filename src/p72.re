/* Construct the bottom-up order sequence of the tree nodes. */
type mult_tree('a) =
  | T('a, list(mult_tree('a)));

let rec prepend_bottom_up = (T(c, sub), l) =>
  List.fold_right((t, l) => prepend_bottom_up(t, l), sub, [c, ...l]);

let bottom_up = (t) => prepend_bottom_up(t, []);
