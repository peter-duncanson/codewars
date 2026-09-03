#include <stdlib.h>
#include <stdio.h>
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
    char *sol = calloc(100, sizeof(char));
    char buffer[100];

    for (int div = 2; div * div <= n; div++)
    {
        if (n % div != 0) continue;

        int count = 0;

        while (n % div == 0)
        {
            n /= div;
            count++;
        }

        if (count == 1) snprintf(buffer, sizeof(buffer), "(%d)", div);
        else snprintf(buffer, sizeof(buffer), "(%d**%d)", div, count);

        strcat(sol, buffer);
    }

    if (n > 1)
    {
        snprintf(buffer, sizeof(buffer), "(%d)", n);
        strcat(sol, buffer);
    }

    return sol;
}

int main(void)
{

    return 0;
}
