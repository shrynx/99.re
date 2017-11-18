/* Knight's tour. */
let rec knights = (t) =>
  if (List.length(t) == 64) {
    [t]
  } else {
    let neighbours = (x, y) =>
      List.filter(
        ((x, y)) => 0 <= x && x <= 7 && 0 <= y && y <= 7,
        [
          (x + 1, y + 2),
          (x + 1, y - 2),
          (x + 2, y + 1),
          (x + 2, y - 1),
          (x - 1, y - 2),
          (x - 1, y + 2),
          (x - 2, y - 1),
          (x - 2, y + 1)
        ]
      );
    switch t {
    | [] => []
    | [(x, y), ..._] =>
      List.concat(
        List.map(
          ((xn, yn)) =>
            if (List.exists(((x, y)) => x == xn && y == yn, t)) {
              []
            } else {
              knights([(xn, yn), ...t])
            },
          neighbours(x, y)
        )
      )
    }
  };
