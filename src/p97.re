/* Sudoku. */
open Printf;

module Board = {
  type t = array(int);
  let is_valid = (c) => c >= 1;
  let get = (b: t, (x, y)) => b[x + y * 9];
  let get_as_string = (b: t, pos) => {
    let i = get(b, pos);
    if (is_valid(i)) {
      string_of_int(i)
    } else {
      "."
    }
  };
  let with_val = (b: t, (x, y), v) => {
    let b = Array.copy(b);
    b[x + y * 9] = v;
    b
  };
  let of_list = (l) : t => {
    let b = Array.make(81, 0);
    List.iteri(
      (y, r) =>
        List.iteri(
          (x, e) =>
            b[x + y * 9] = (
              if (e >= 0 && e <= 9) {
                e
              } else {
                0
              }
            ),
          r
        ),
      l
    );
    b
  };
  let print = (b) =>
    for (y in 0 to 8) {
      for (x in 0 to 8) {
        printf(
          if (x == 0) {
            "%s"
          } else if (x mod 3 == 0) {
            " | %s"
          } else {
            "  %s"
          },
          get_as_string(b, (x, y))
        )
      };
      if (y < 8) {
        if (y mod 3 == 2) {
          printf("\n--------+---------+--------\n")
        } else {
          printf("\n        |         |        \n")
        }
      } else {
        printf("\n")
      }
    };
  let available = (b, (x, y)) => {
    let avail = Array.make(10, true);
    for (i in 0 to 8) {
      avail[get(b, (x, i))] = false;
      avail[get(b, (i, y))] = false
    };
    let sq_x = x - x mod 3
    and sq_y = y - y mod 3;
    for (x in sq_x to sq_x + 2) {
      for (y in sq_y to sq_y + 2) {
        avail[get(b, (x, y))] = false
      }
    };
    let av = ref([]);
    for (i in 1 to 9) {
      if (avail[i]) {
        av := [i, ...av^]
      }
    };
    av^
  };
  let next = ((x, y)) =>
    if (x < 8) {
      (x + 1, y)
    } else {
      (0, y + 1)
    };
  let rec fill = (b, (_x, y) as pos) =>
    if (y > 8) {
      Some(b)
    } else if (is_valid(get(b, pos))) {
      fill(b, next(pos))
    } else {
      switch (available(b, pos)) {
      | [] => None
      | l => try_values(b, pos, l)
      }
    }
  and try_values = (b, pos, list) =>
    switch list {
    | [v, ...l] =>
      switch (fill(with_val(b, pos, v), next(pos))) {
      | Some(_) as res => res
      | None => try_values(b, pos, l)
      }
    | [] => None
    };
};

let sudoku = (b) =>
  switch (Board.fill(b, (0, 0))) {
  | Some(b) => b
  | None => failwith("sudoku: no solution")
  };

let print = Board.print;
