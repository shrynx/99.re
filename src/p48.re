/* Truth tables for logical expressions. */
type bool_expr =
  | Var(string)
  | Not(bool_expr)
  | And(bool_expr, bool_expr)
  | Or(bool_expr, bool_expr);

let rec eval = (val_vars, exp) =>
  switch exp {
  | Var(x) => List.assoc(x, val_vars)
  | Not(e) => ! eval(val_vars, e)
  | And(e1, e2) => eval(val_vars, e1) && eval(val_vars, e2)
  | Or(e1, e2) => eval(val_vars, e1) || eval(val_vars, e2)
  };

/* Again, this is an easy and short implementation rather than an
   efficient one. */
let rec table_make = (val_vars, vars, expr) =>
  switch vars {
  | [] => [(List.rev(val_vars), eval(val_vars, expr))]
  | [v, ...tl] =>
    table_make([(v, true), ...val_vars], tl, expr)
    @ table_make([(v, false), ...val_vars], tl, expr)
  };

let table = (vars, expr) => table_make([], vars, expr);
