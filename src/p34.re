/* Calculate Euler's totient function phi(m). */
let rec gcd = (x, y) => y == 0 ? x : gcd(y, x mod y);

let coprime = (x, y) => gcd(x, y) == 1;

let phi = (n) => {
  let rec count_coprime = (acc, d) =>
    d < n ? count_coprime(coprime(n, d) ? acc + 1 : acc, d + 1) : acc;
  n == 1 ? 1 : count_coprime(0, 1)
};
