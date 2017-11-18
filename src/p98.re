/* Nonograms. */
type element =
  | Empty
  | X;

let rec is_set_range = (row, col0, col1) =>
  col0 >= col1 || row[col0] == X && is_set_range(row, col0 + 1, col1);

let is_set_sub = (row, col0, width) =>
  col0 + width <= Array.length(row) && is_set_range(row, col0, col0 + width);

let rec check_row = (row, col0, patt_row) =>
  if (col0 >= Array.length(row)) {
    patt_row == []
  } else {
    switch row[col0] {
    | Empty => check_row(row, col0 + 1, patt_row)
    | X =>
      switch patt_row {
      | [] => false
      | [nX, ...tl] =>
        if (is_set_sub(row, col0, nX)) {
          let col0 = col0 + nX;
          (col0 >= Array.length(row) || row[col0] == Empty) && check_row(row, col0 + 1, tl)
        } else {
          false
        }
      }
    }
  };

let rec check_rows = (table, row0, patts_row) =>
  row0 >= Array.length(table)
  || (
    switch patts_row {
    | [patt_row, ...tl] => check_row(table[row0], 0, patt_row) && check_rows(table, row0 + 1, tl)
    | [] => assert false
    }
  );

let char_of_element = (ele) =>
  switch ele {
  | Empty => '_'
  | X => 'X'
  };

let print_tbl = (table) => {
  let print_row = (r) => {
    Array.iter(
      (e) => {
        print_char('|');
        print_char(char_of_element(e))
      },
      r
    );
    print_string("|\n")
  };
  Array.iter(print_row, table)
};

let solve = (patts_row, patts_col) => {
  let height = List.length(patts_row)
  and width = List.length(patts_col);
  let table = Array.make_matrix(height, width, Empty);
  let rec gen = (col, row, patts_col) =>
    if (col >= width) {
      if (check_rows(table, 0, patts_row)) {
        print_tbl(table)
      }
    } else {
      switch patts_col {
      | [[], ...rest_patt] => gen(col + 1, 0, rest_patt)
      | [[nX, ...tl], ...rest_patt] =>
        assert (nX > 0);
        if (row + nX <= height) {
          for (r in row to row + nX - 1) {
            table[r][col] = X
          };
          gen(col, row + nX + 1, [tl, ...rest_patt]);
          for (r in row to row + nX - 1) {
            table[r][col] = Empty
          };
          gen(col, row + 1, patts_col)
        }
      | [] => assert false
      }
    };
  gen(0, 0, patts_col)
};
