/* Determine the prime factors of a given positive integer.
   Construct a flat list containing the prime factors in ascending order. */
let factors = (n) => {
  let rec aux = (d, n) =>
    if (n == 1) {
      []
    } else if (n mod d == 0) {
      [d, ...aux(d, n / d)]
    } else {
      aux(d + 1, n)
    };
  aux(2, n)
};
