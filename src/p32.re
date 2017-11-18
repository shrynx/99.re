/* Determine the greatest common divisor of two positive integer numbers. */
let rec gcd = (x, y) => y == 0 ? x : gcd(y, x mod y);
