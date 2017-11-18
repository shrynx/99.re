/* Determine whether two positive integer numbers are coprime. */
let rec gcd = (x, y) => y == 0 ? x : gcd(y, x mod y);

let coprime = (x, y) => gcd(x, y) == 1;
