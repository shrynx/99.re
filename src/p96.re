/* Syntax checker. */
let identifier = {
  let is_letter = (c) => 'a' <= c && c <= 'z';
  let is_letter_or_digit = (c) => is_letter(c) || '0' <= c && c <= '9';
  let rec is_valid = (s, i, not_after_dash) =>
    if (i < 0) {
      not_after_dash
    } else if (is_letter_or_digit(s.[i])) {
      is_valid(s, i - 1, true)
    } else if (s.[i] == '-' && not_after_dash) {
      is_valid(s, i - 1, false)
    } else {
      false
    };
  (s) => {
    let n = String.length(s);
    n > 0 && is_letter(s.[n - 1]) && is_valid(s, n - 2, true)
  }
};
