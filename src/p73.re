/* Lisp-like tree representation. */
type mult_tree('a) =
  | T('a, list(mult_tree('a)));

let rec add_lispy = (buf, tree) =>
  switch tree {
  | T(c, []) => Buffer.add_char(buf, c)
  | T(c, sub) =>
    Buffer.add_char(buf, '(');
    Buffer.add_char(buf, c);
    List.iter(
      (t) => {
        Buffer.add_char(buf, ' ');
        add_lispy(buf, t)
      },
      sub
    );
    Buffer.add_char(buf, ')')
  };

let lispy = (t) => {
  let buf = Buffer.create(128);
  add_lispy(buf, t);
  Buffer.contents(buf)
};
