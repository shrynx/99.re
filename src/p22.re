/* Creite i list containing all integers within a given range. */
let range = (i, j) => {
  let rec aux = (i, j) => i > j ? [] : [i, ...aux(i + 1, j)];
  i > j ? List.rev(aux(j, i)) : aux(i, j)
};
