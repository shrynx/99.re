/* Determine the prime factors of a given positive integer.
   Construct a list containing the prime factors and their multiplicity. */
let factors = (n) => {
  let rec aux = (d, n) =>
    if (n == 1) {
      []
    } else if (n mod d == 0) {
      switch (aux(d, n / d)) {
      | [(x, n), ...xs] when x == d => [(x, n + 1), ...xs]
      | z => [(d, 1), ...z]
      }
    } else {
      aux(d + 1, n)
    };
  aux(2, n)
};
