/* Gray codes. */
let prepend = (c, s) => String.make(1, c) ++ s;

let rec gray = (n) =>
  n <= 1 ?
    ["0", "1"] :
    {
      let g = gray(n - 1);
      List.map(prepend('0'), g) @ List.rev_map(prepend('1'), g)
    };
