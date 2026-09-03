/*
The prime numbers are not regularly spaced. 

For example from 2 to 3 the gap is 1. 
From 3 to 5 the gap is 2. From 7 to 11 it is 4. 
Between 2 and 50 we have the following pairs of 2-gaps primes: 3-5, 5-7, 11-13, 17-19, 29-31, 41-43

A prime gap of length n is a run of n-1 consecutive composite numbers between two successive primes

We will write a function gap with parameters:

    g (integer >= 2) which indicates the gap we are looking for

    m (integer > 2) which gives the start of the search (m inclusive)

    n (integer >= m) which gives the end of the search (n inclusive)

In the example above gap(2, 3, 50) will return { 3, 5 } which is the first pair 
between 3 and 50 with a 2-gap.

For no pair of prime numbers with a gap of `g` return [0, 0]
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

long long *gap(int g, long long m, long long n)
{
    long long *solution = malloc(2 * sizeof(long long));
    long long first_prime = 0;
    bool found;

    // find primes from m to n
    for (long long i = m; i <= n; i++)
    {
        found = true;
        for (long long div = 2; (div * div) <= i; div++)
        {
            if (i % div == 0)
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            if (i - first_prime == g)
            {
                solution[0] = first_prime;
                solution[1] = i;
                return solution;
            }
            else first_prime = i;
        }
    }
    solution[0] = 0;
    solution[1] = 0;
    return solution;
}

int main(void)
{

    return 0;
}
