/* Determine whether a given integer number is prime. */
let is_prime = (n) => {
  let n = abs(n);
  let rec is_not_divisor = (d) => d * d > n || n mod d != 0 && is_not_divisor(d + 1);
  n != 1 && is_not_divisor(2)
};
