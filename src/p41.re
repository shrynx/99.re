/* Given a range of integers by its lower and upper limit,
   print a list of all even numbers and their Goldbach composition. */
let is_prime = (n) => {
  let n = max(n, - n);
  let rec is_not_divisor = (d) => d * d > n || n mod d != 0 && is_not_divisor(d + 1);
  is_not_divisor(2)
};

let goldbach = (n) => {
  let rec aux = (d) =>
    if (is_prime(d) && is_prime(n - d)) {
      (d, n - d)
    } else {
      aux(d + 1)
    };
  aux(2)
};

let rec goldbach_list = (a, b) =>
  if (a > b) {
    []
  } else if (a mod 2 == 1) {
    goldbach_list(a + 1, b)
  } else {
    [(a, goldbach(a)), ...goldbach_list(a + 2, b)]
  };

let goldbach_limit = (a, b, lim) =>
  List.filter(((_, (a, b))) => a > lim && b > lim, goldbach_list(a, b));
