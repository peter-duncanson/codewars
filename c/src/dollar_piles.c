/*
In front of you, there are n piles of $1 bills.

Your assistant will perform the following operations until one of the piles is empty:

    1) Calculate the greatest common divisor of the amounts of money in the piles.
    2) Take out that amount of bills from each pile and give them to you.

You want to know: When one of the piles is emptied, how much money have you received in total?

Write a function calc which will return the total money you have received at the end of all 
operations.

You will be given an array of size n, the number of $1 bills in each pile. 
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long calc(size_t length, const unsigned int array[length]);

int main(void)
{

    return 0;
}


unsigned long long calc(size_t length, const unsigned int array[length])
{
    unsigned long long result = 0;

    unsigned int base = array[0];
    unsigned int gcd = 1;
    const unsigned int *p;

    // find the smallest number in the array, one of its divisors has to be the GCD of
    // the entire array
    for (p = array + 1; p < array + length; p++)
    {
        if (*p < base) base = *p;
    }

    gcd = base;

    while (base)
    {
        for (p = array; p < array + length; p++)
        {
            result += gcd;
        }
        base -= gcd;
    }

    return result;    
}

