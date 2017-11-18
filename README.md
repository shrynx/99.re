# 99 Problems

Solutions to 99 Problems implemented in [Reason](https://reasonml.github.io/).

[ninety-nine lisp problems]: http://www.ic.unicamp.br/~meidanis/courses/mc336/2006s2/funcional/L-99_Ninety-Nine_Lisp_Problems.html

## Status

Currently in progress.

### Working with lists

| No. | Description          | Solution                |     | No. | Description        | Solution                |
| --- | -------------------- | ----------------------- | --- | --- | ------------------ | ----------------------- |
| 01  | Last element         | [completed](src/p01.re) |     | 15  | Replicate          | [completed](src/p15.re) |
| 02  | Last two elements    | [completed](src/p02.re) |     | 16  | Drop every N'th    | [completed](src/p16.re) |
| 03  | K'th element         | [completed](src/p03.re) |     | 17  | Split              | [completed](src/p17.re) |
| 04  | Length               | [completed](src/p04.re) |     | 18  | Slice              | [completed](src/p18.re) |
| 05  | Reverse              | [completed](src/p05.re) |     | 19  | Rotate             | [completed](src/p19.re) |
| 06  | Palindrome           | [completed](src/p06.re) |     | 20  | Remove             | [completed](src/p20.re) |
| 07  | Flatten              | [completed](src/p07.re) |     | 21  | Insert             | [completed](src/p21.re) |
| 08  | Eliminate duplicates | [completed](src/p08.re) |     | 22  | Range              | [completed](src/p22.re) |
| 09  | Pack duplicates      | [completed](src/p09.re) |     | 23  | Random select      | [completed](src/p23.re) |
| 10  | Run-length           | [completed](src/p10.re) |     | 24  | Random numbers     | [completed](src/p24.re) |
| 11  | Modified run-length  | [completed](src/p11.re) |     | 25  | Random permutation | [completed](src/p25.re) |
| 12  | Decode run-length    | [completed](src/p12.re) |     | 26  | Combinations       | [completed](src/p26.re) |
| 13  | Direct run-length    | [completed](src/p13.re) |     | 27  | Group              | [completed](src/p27.re) |
| 14  | Duplicate            | [completed](src/p14.re) |     | 28  | Sort by length     | [completed](src/p28.re) |

### Arithmetic

| No. | Description          | Solution                |     | No. | Description           | Solution                |
| --- | -------------------- | ----------------------- | --- | --- | --------------------- | ----------------------- |
| 31  | Prime                | [completed](src/p31.re) |     | 37  | Improve 32            | [completed](src/p37.re) |
| 32  | GCD                  | [completed](src/p32.re) |     | 38  | Compare 32 and 35     | [completed](src/p38.re) |
| 33  | Coprime              | [completed](src/p33.re) |     | 39  | List prime numbers    | [completed](src/p39.re) |
| 34  | Euler's totient      | [completed](src/p34.re) |     | 40  | Goldbach's conjecture | [completed](src/p40.re) |
| 35  | Prime factors        | [completed](src/p35.re) |     | 41  | Goldbach compositions | [completed](src/p41.re) |
| 36  | Prime factors (pair) | [completed](src/p36.re) |     |     |                       |                         |

### Logic and Codes

| No. | Description                              | Solution                                   |
| --- | ---------------------------------------- | ------------------------------------------ |
| 46  | Truth tables for logical expressions     | [completed](src/p46.re)                    |
| 47  | Truth tables for logical expressions (2) | [completed (combined with 46)](src/p46.re) |
| 48  | Truth tables for logical expressions (3) | [completed](src/p48.re)                    |
| 49  | Gray code                                | [completed](src/p49.re)                    |
| 50  | Huffman code                             | [completed](src/p50.re)                    |

### Binary Trees

| No. | Description         | Solution                    |     | No. | Description              | Solution                 |
| --- | ------------------- | --------------------------- | --- | --- | ------------------------ | ------------------------ |
| 54A | Check Binary Tree   | **No need as type checked** |     | 62  | Collect internals        | [completed](src/p62.re)  |
| 55  | Completely balanced | [completed](src/p55.re)     |     | 62B | Collect nodes at a level | [completed](src/p62b.re) |
| 56  | Symmetric           | [completed](src/p56.re)     |     | 63  | Complete binary tree     | [completed](src/p63.re)  |
| 57  | Binary search trees | [completed](src/p57.re)     |     | 64  | Layout 1                 | [completed](src/p64.re)  |
| 58  | Generate-and-test   | [completed](src/p58.re)     |     | 65  | Layout 2                 | [completed](src/p65.re)  |
| 59  | Height-balanced     | [completed](src/p59.re)     |     | 66  | Layout 3                 | [completed](src/p66.re)  |
| 60  | 48 with N nodes     | [completed](src/p60.re)     |     | 67A | Stringify                | [completed](src/p67.re)  |
| 61  | Count leaves        | [completed](src/p61.re)     |     | 68  | Preorder and inorder     | [completed](src/p68.re)  |
| 61A | Collect leaves      | [completed](src/p61a.re)    |     | 69  | Dotstring                | [completed](src/p69.re)  |

### Multiway Trees

| No. | Description          | Solution                    |
| --- | -------------------- | --------------------------- |
| 70B | Check Multiway Tree  | **No need as type checked** |
| 70C | Count nodes          | [completed](src/p70c.re)    |
| 70  | Node string          | [completed](src/p70.re)     |
| 71  | Internal path length | [completed](src/p71.re)     |
| 72  | Bottom-up order      | [completed](src/p72.re)     |
| 73  | Lisp-like tree       | [completed](src/p73.re)     |

### Graphs

| No. | Description           | Solution                |     | No. | Description           | Solution                |
| --- | --------------------- | ----------------------- | --- | --- | --------------------- | ----------------------- |
| 80  | Conversions           | [completed](src/p80.re) |     | 85  | Graph isomorphism     | [completed](src/p85.re) |
| 81  | Path                  | [completed](src/p81.re) |     | 86  | Graph coloration      | [completed](src/p86.re) |
| 82  | Cycle                 | [completed](src/p82.re) |     | 87  | Depth-first traversal | [completed](src/p87.re) |
| 83  | Spanning trees        | [completed](src/p83.re) |     | 88  | Connected components  | [completed](src/p88.re) |
| 84  | Minimal spanning tree | [completed](src/p84.re) |     | 89  | Bipartite graphs      | Not implemented         |

### Miscellaneous Problems

| No. | Description             | Solution                |     | No. | Description          | Solution                |
| --- | ----------------------- | ----------------------- | --- | --- | -------------------- | ----------------------- |
| 90  | Eight queens problem    | [completed](src/p90.re) |     | 95  | English number words | [completed](src/p95.re) |
| 91  | Knight's tour           | [completed](src/p91.re) |     | 96  | Syntax checker       | [completed](src/p96.re) |
| 92  | Von Koch's conjecture   | [completed](src/p92.re) |     | 97  | Sudoku               | [completed](src/p97.re) |
| 93  | An arithmetic puzzle    | [completed](src/p93.re) |     | 98  | Nonograms            | [completed](src/p98.re) |
| 94  | K-regular simple graphs | [completed](src/p94.re) |     | 99  | Crossword puzzle     | Not implemented         |

## Acknowledgement

### References

-   [99 Problems in OCaml](https://ocaml.org/learn/tutorials/99problems.html)

### Insipration

-   [99 Problems in Haskell](https://wiki.haskell.org/H-99:_Ninety-Nine_Haskell_Problems)
-   [99 Problems in Lisp](https://www.ic.unicamp.br/~meidanis/courses/mc336/2006s2/funcional/L-99_Ninety-Nine_Lisp_Problems.html)
-   [99 Problems in Prolog](https://sites.google.com/site/prologsite/prolog-problems)
