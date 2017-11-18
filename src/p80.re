/* Conversions. */
type edge_clause('a) = list(('a, 'a));

type graph_term('a) = {
  nodes: list('a),
  edges: list(('a, 'a))
};

module CharMap = Map.Make(Char);

type edge = (char, char);

type adjacency_list = CharMap.t(list(edge));

type human_friendly = string;
