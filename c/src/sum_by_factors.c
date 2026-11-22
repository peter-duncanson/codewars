#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_largest(const int numbers[], int count)
{
    int largest = (numbers[0] >= 0) ? numbers[0] : numbers[0] * -1;

    for (int i = 1; i < count; i++) {
        int test = (numbers[i] >= 0) ? numbers[i] : numbers[i] * -1;
        if (test > largest)
            largest = test;
    }
    return largest;
}

// return an array of all primes up to n inclusive if n prime
// n >= 2 else returns NULL
// sieve of Eratosthenes algorithm.
int *get_primes(int n, int *prime_count)
{
    if (n < 2)
        return NULL;

    const int range_len = n + 1;
    int *range = malloc(sizeof(int) * range_len);

    // write 0 - n to the range array
    for (int i = 0; i < range_len; i++)
        range[i] = i;

    for (int i = 2; i < range_len; i++) {
        // if the value isnt zero, it must be prime
        if (range[i] != 0) {
            *prime_count += 1;
            // clear all multiples of this number since they are not prime
            for (int j = i + i; j < range_len; j += i) {
                range[j] = 0;
            }
        }
    }

    int *result = malloc(sizeof(int) * *prime_count);
    int *p = result;

    for (int i = 2; i <= n; i++) {
        if (range[i] != 0)
            *p++ = range[i];
    }

    free(range);
    return result;
}

// return largest integer a such that a * a <= n
int get_sqrt(int n)
{
    int a;
    for (int i = 1; ; i++) {
        if (i * i > n)
            break;
        a = i;
    }
    return a;
}

char *sumOfDivided(const int numbers[], int count)
{
    char *result = calloc(1000, sizeof(char));
    if (count == 0) {
        result = realloc(result, 1);
        return result;
    }

    bool has_factor = false;
    int prime_count = 0;
    int largest = get_largest(numbers, count);
    int *primes = get_primes(largest, &prime_count);
    // if (primes == NULL) exit(1);

    char *buffer = calloc(80, sizeof(char));
    char *p = result;

    for (int i = 0; i < prime_count; i++) {
        int sum_of_factors = 0;
        for (int n = 0; n < count; n++) {
            if ((numbers[n] % primes[i]) == 0) {
                has_factor = true;
                sum_of_factors += numbers[n];
            }
        }
        if (has_factor) {
            // printf("for prime %d\nsum of factors is %d\n", primes[i], sum_of_factors);
            sprintf(buffer, "(%d %d)", primes[i], sum_of_factors);
            memcpy(p, buffer, strlen(buffer));
            p += strlen(buffer);
            memset(buffer, 0, 80);
            has_factor = false;
        }
    }
    free(primes);
    return result;

}

int main(void)
{
    const int a[] = { 12, 15 };
    // "(2 12)(3 27)(5 15)"
    
    const int b[] = { 15, 21, 24, 30, 45};
    // "(2 54)(3 135)(5 90)(7 21)"

    const int c[] = { 107, 158, 204, 100, 118, 123, 126, 110, 116, 100 };
    //"(2 1032)(3 453)(5 310)(7 126)(11 110)(17 204)(29 116)(41 123)
    // (59 118)(79 158)(107 107)"

    
    const int d[] = { -29804, -4209, -28265, -72769, -31744 };
    // "(2 -61548)(3 -4209)(5 -28265)(23 -4209)(31 -31744)
    //  (53 -72769)(61 -4209)(1373 -72769)(5653 -28265)(7451 -29804)"
    
    const int e[] = { 17, -17, 51, -51 };
    //"(3 0)(17 0)"

    const int f[] = { 173471 };
    // "(41 173471)(4231 173471)"

    char *p_a = sumOfDivided(a, 2);
    printf("a: %s\n", p_a);

    char *p_b = sumOfDivided(b, 5);
    printf("b: %s\n", p_b);

    char *p_c = sumOfDivided(c, 10);
    printf("c: %s\n", p_c);

    char *p_d = sumOfDivided(d, 5);
    printf("d: %s\n", p_d);

    char *p_e = sumOfDivided(e, 4);
    printf("e: %s\n", p_e);

    char *p_f = sumOfDivided(f, 1);
    printf("f: %s\n", p_f);



    // int x;
    // int *p = get_primes(173471, &x);
    // for (int i = 0; i < x; i++) {
    //     printf("%d\n", p[i]);
    // }
    return 0;
}
