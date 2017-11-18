/* A list of prime numbers. */
let is_prime = (n) => {
  let n = max(n, - n);
  let rec is_not_divisor = (d) => d * d > n || n mod d != 0 && is_not_divisor(d + 1);
  is_not_divisor(2)
};

let rec all_primes = (a, b) =>
  if (a > b) {
    []
  } else {
    let rest = all_primes(a + 1, b);
    if (is_prime(a)) {
      [a, ...rest]
    } else {
      rest
    }
  };
