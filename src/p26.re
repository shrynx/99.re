/* Generate the combinations of K distinct objects chosen from the N elements of a list. */
let rec extract = (k, list) =>
  k <= 0 ?
    [[]] :
    (
      switch list {
      | [] => []
      | [x, ...xs] =>
        let base = List.map((z) => [x, ...z], extract(k - 1, xs));
        let rest = extract(k, xs);
        base @ rest
      }
    );
