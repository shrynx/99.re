/* Calculate Euler's totient function phi(m) (improved). */
let rec pow = (n, p) =>
  if (p < 1) {
    1
  } else {
    n * pow(n, p - 1)
  };

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

let phi_improved = (n) => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [(x, m), ...xs] => aux((x - 1) * pow(x, m - 1) * acc, xs)
    };
  aux(1, factors(n))
};
