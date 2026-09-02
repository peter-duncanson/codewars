#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*
Given a positive number n > 1 find the prime factor decomposition of n.
The result will be a heap allocated string with the following form:

 "(p1**n1)(p2**n2)...(pk**nk)"

with the p(i) in increasing order and n(i) empty if n(i) is 1.

Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*/

char *factors(int n)
{
    size_t array_size = 100;
    size_t *primes = calloc(array_size, sizeof(size_t));
    size_t *prime_counts = calloc(array_size, sizeof(size_t));
    size_t div = 2, i = 0, count = 0;
    char *sol = malloc(array_size * sizeof(char)), buffer[100];
    
    while (primes[0] == 0)
    {
        if (n % div == 0)
        {
            primes[i++] = div;
        }
        else div++;
    }

    while (n > 1)
    {
        if (n % div == 0)
        {
            if (div != primes[i - 1])
            {
                primes[i] = div;
                prime_counts[i - 1] = count;
                count = 0;
                i++;
            }
            else
            {
                ++count;
                n /= div;
            }
        }
        else div++;
    }

    for (size_t k = 0; k < i; k++)
    {
        if (prime_counts[k] == 0) prime_counts[k] = 1;
        if (prime_counts[k] == 1)
        {
            int len = snprintf(buffer, (size_t) 99, "(%ld)", primes[k]);
            sol = strncat(sol, buffer, (size_t) len); 
        }

        else
        {
            int len = snprintf(buffer, (size_t) 99, "(%ld**%ld)", primes[k], prime_counts[k]);
            sol = strncat(sol, buffer, (size_t) len); 
        }

    }

    return sol;
}

int main(void)
{
    char *a = factors(2);
    char *b = factors(435480599);
    char *c = factors(86240);
    printf("%s\n\n", a);
    printf("%s\n\n", b);
    printf("%s\n\n", c);

    return 0;
}
