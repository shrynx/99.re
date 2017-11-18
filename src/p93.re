/* An arithmetic puzzle. */
type op =
  | Add
  | Sub
  | Mul
  | Div;

type expr =
  | Num(int)
  | App(expr, op, expr);

let string_of_op = (op) =>
  switch op {
  | Add => "+"
  | Sub => "-"
  | Mul => "*"
  | Div => "/"
  };

let rec string_of_expr = (expr) =>
  switch expr {
  | Num(x) => string_of_int(x)
  | App(e1, op, e2) =>
    Printf.sprintf("(%s %s %s)", string_of_expr(e1), string_of_op(op), string_of_expr(e2))
  };

let rev_flatten = (l) =>
  List.fold_left((acc, x) => List.fold_left((acc, y) => [y, ...acc], acc, x), [], l);

let ops = [Add, Sub, Mul, Div];

let apply = (x, op, y) =>
  switch op {
  | Add => x + y
  | Sub => x - y
  | Mul => x * y
  | Div => x / y
  };

let rec value = (expr) =>
  switch expr {
  | Num(x) => x
  | App(x, op, y) => apply(value(x), op, value(y))
  };

let legal = (x, op, y) =>
  switch op {
  | Add => true
  | Sub => true
  | Mul => true
  | Div => y != 0 && x mod y == 0
  };

let splits = (l) => {
  let rec split = (front, acc, list) =>
    switch list {
    | []
    | [_] => acc
    | [hd, ...tl] =>
      let new_front = [hd, ...front];
      split(new_front, [(List.rev(new_front), tl), ...acc], tl)
    };
  split([], [], l)
};

let combine = ((e1, v1), (e2, v2)) => {
  let rec comb = (acc, list) =>
    switch list {
    | [] => acc
    | [op, ...tl] when legal(v1, op, v2) =>
      comb([(App(e1, op, e2), apply(v1, op, v2)), ...acc], tl)
    | [_, ...tl] => comb(acc, tl)
    };
  comb([], ops)
};

let fuse = (f, l1, l2) =>
  List.rev_map((x) => List.rev_map((y) => f(x, y), l2) |> rev_flatten, l1) |> rev_flatten;

let rec make_expr = (list) =>
  switch list {
  | [] => []
  | [x] => [(Num(x), x)]
  | _ as l =>
    splits(l) |> List.rev_map(((a, b)) => fuse(combine, make_expr(a), make_expr(b))) |> rev_flatten
  };

let eq = ((e1, v1), (e2, v2)) => v1 == v2 ? [Some((e1, e2, v1))] : [None];

let find_eq = (l) =>
  splits(l)
  |> List.rev_map(((a, b)) => fuse(eq, make_expr(a), make_expr(b)) |> List.filter((!=)(None)))
  |> rev_flatten
  |> List.fold_left(
       (acc, x) =>
         switch x {
         | None => acc
         | Some(v) => [v, ...acc]
         },
       []
     )
  |> List.iter(((e1, e2, _)) => Printf.printf("%s = %s\n", string_of_expr(e1), string_of_expr(e2)));
