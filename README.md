# Linear Equation Solver
This C script is intended to solve linear/arithmetic (sequences with a constatn difference) sequences.
* It does this by getting the formula for the Nth term of the sequence.
* It uses the formula: Tn = a + (n - 1)d
(a=starting term,  d=difference)
* It supports any positive or negative whole numbers.

# Example Usage
```sh
$ cc LinearEquationSolver.c
$ ./a.out
Please type the linear sequence with a space in-between each term and then press enter
Please enter at least two terms
(The program will only use the first 10 terms!)

13 9 5 1 -3 -7
13, 9, 5, 1, -3, -7
d = -4 (difference)
a = 13 (starting term)
Tn=17-4n
$
```
