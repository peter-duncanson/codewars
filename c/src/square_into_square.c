/*
My little sister came back home from school with the following task:
Given a squared sheet of paper she has to cut it in pieces which, when 
assembled, give squares the sides of which form an increasing sequence 
of numbers. At the beginning it was lot of fun but little by little we
were tired of seeing the pile of torn paper. So we decided to write a
program that could help us and protects trees.

Given a positive integer number n, return a strictly increasing 
char array of numbers, so that the sum of the squares is equal to n².

If there are multiple solutions (and there will be), return as far as 
possible the result with the largest possible values.

Examples:
decompose(11) must return "[1, 2, 4, 10]". Note that there are actually
two ways to decompose 11², 
11² = 121 = 1 + 4 + 16 + 100 = 1² + 2² + 4² + 10²
but don't return "[2, 6, 9]", since 9 is smaller than 10.

For decompose(50) don't return "[1, 1, 4, 9, 49]" but "[1, 3, 5, 8, 49]"
since "[1, 1, 4, 9, 49]" doesn't form a strictly increasing sequence.

Note:
Neither [n] nor [1, 1, 1, … , 1] are valid solutions. If no valid solution
exists, return "[]"

The function "decompose" will take a positive integer n and return the
decomposition of N = n² as "[x1, x2, ... , xk]"

Hint:
Very often xk will be n-1.
*/

#include <stdlib.h>
#include <stdio.h>

#define SOLUTION_SIZE 100

char *decompose(long long n)
{
    char *solution = calloc(SOLUTION_SIZE, sizeof(char));

    long long xk = n - 1;
    long long a = (n * n) - (xk * xk);
    printf("%lld\n", a);

    return solution;
}

int main(void)
{
    decompose(50);


    return 0;
}

