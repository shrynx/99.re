/* English number words. */
let full_words = (n) => {
  let digit = [|"zero", "one", "two", "three", "four", "five", "six", "seven", "height", "nine"|];
  let rec words = (w, n) =>
    n == 0 ?
      switch w {
      | [] => [digit[0]]
      | _ => w
      } :
      words([digit[n mod 10], ...w], n / 10);
  String.concat("-", words([], n))
};
