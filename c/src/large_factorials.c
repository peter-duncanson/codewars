#include <stdlib.h>
#include <stdio.h>

typedef struct number {
    char *num;
    size_t digits;
} BigNum;

void free_num(BigNum *n)
{
    free(n->num);
    free(n);
}

void print_num(BigNum *n)
{
    for (size_t i = n->digits; i != 0; i--) {
        printf("%d", n->num[i - 1]);
    }
    puts("");
}

size_t get_num_digits(int n)
{
    size_t num_digits = 0;
    while (n) {
        if (n) {
            num_digits++;
            n /= 10;
        }
    }
    return num_digits;
}

char *extract_digits(int n, size_t num_digits)
{
    char *digits = calloc(num_digits, sizeof(char));
    for (size_t i = 0; i < num_digits; i++) {
        digits[i] = (char)(n % 10);
        n -= digits[i];
        n /= 10;
    }
    return digits;
}

BigNum *new_num(int n)
{
    BigNum *new = malloc(sizeof(BigNum));
    size_t num_digits = get_num_digits(n);
    new->num = extract_digits(n, num_digits);
    new->digits = num_digits;
    return new;
}

BigNum *big_mult(BigNum *a, BigNum *b)
{
    BigNum *result = malloc(sizeof(BigNum));
    result->digits = a->digits + b->digits;
    result->num = calloc(result->digits, sizeof(char));

    char *carries = calloc(a->digits + b->digits, sizeof(char));

    for (size_t i2 = 0; i2 < b->digits; i2++) {
        for (size_t i1 = 0; i1 < a->digits; i1++) {
            char m = a->num[i1] * b->num[i2] + carries[i1];
            carries[i1] = 0;
            result->num[i1 + i2] += m;
            if (result->num[i1 + i2] > 9) {
                result->num[i1 + i2 + 1] += result->num[i1 + i2] / 10;
                result->num[i1 + i2] %= 10;
            }
        }
    }

    free_num(a);
    free_num(b);
    free(carries);
    return result;
}


char *factorial(int n)
{
    char *output = calloc(2, sizeof(char));
    if (n < 0)
        return output;
    if (n < 2) {
        *output = '1';
        return output;
    }

    BigNum *ans = new_num(n);
    while (n >= 2) {
        ans = big_mult(ans, new_num(--n));
    }

     
    char *p = ans->num + ans->digits - 1;
    size_t result_buffer_size = 0;
    while (*p == 0) {
        result_buffer_size++;
        p--;
    }

    result_buffer_size = ans->digits - result_buffer_size + 1;
    output = realloc(output, result_buffer_size);

    for (size_t i = 0; i < result_buffer_size - 1; i++) {
        output[i] = (*p-- + 48);
    }
    *p = '\0';
    free_num(ans);
    return output;
}

int main(void)
{
    char *t = factorial(143);
    printf("%s\n", t);
    return 0;
}
