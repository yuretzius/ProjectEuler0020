# ProjectEuler0020
My work on 

[problem #20 of projecteuler.net](https://projecteuler.net/problem=20):

### Factorial Digit Sum

$n!$ means $n \times (n - 1) \times \cdots \times 3 \times 2 \times 1$.

For example, $10! = 10 \times 9 \times \cdots \times 3 \times 2 \times 1 = 3628800$,<br>
and the sum of the digits in the number $10!$ is $3 + 6 + 2 + 8 + 8 + 0 + 0 = 27$.

Find the sum of the digits in the number $100!$.

*Completed on Sun, 21 Feb 2021, 02:07*

> [!NOTE]
> Project Euler's policy allows publication of solutions for the first 100 problems, that's why I am sharing my work here for reference and educational purposes.

Nothing much to tell about the python version. Directly compute the factorial, using recursion and python's native (big) ints. Convert the result to a string, cycle through it digit by digit and add them up. $N = 100$ takes $96 \\, \mu\text{s}$, $N = 1000$ takes $2$ ms

