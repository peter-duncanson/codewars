/*




*/


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// char *factorial(int n)
// {
//     if (n < 0) return "";

//     uint32_t *a = calloc(10, sizeof(uint32_t));

//     uint32_t strn = (uint32_t)n;

//     uint64_t hilo;

//     *a = strn--;

//     hilo = *a * strn;
//     a[0] = (uint32_t)hilo;
//     a[1] = (hilo >> 32);

//     // printf("%X\n%X\n", a[0], a[1]);
//     for (size_t i = 0; i < 10; i++) {
//         printf("%u\n", a[i]);
//     }
//     free(a);
//     return "";
// }
typedef uint32_t u32;
typedef uint64_t u64;
typedef struct {
    u32 value;
    u32 shift;
} BigInt;

int main(void)
{
    BigInt *big_arr = malloc(10 * sizeof(BigInt *));
    for (u32 i = 0; i < 10; i++) {
        big_arr[i].value = 0;
        big_arr[i].shift = i;
    }

    




    return 0;
}





    // u32 size = 10;
    // u32 *arr = calloc(size, sizeof(u32));
    // for (u32 i = 0; i < size; i++) {
    //     arr[i] = 1;
    // }

    // u32 n = 0x7FFFFFFF;
    // *arr = n--;
    // u64 hold;
    // u32 res;
    // while (n != 1) {
    //     hold = (u64)*arr * n--;
    //     u32 i = 1;
    //     while (1) {
    //         if ((hold >> 32) != 0) {
    //             res = hold >> 32;
    //             // printf("%X\n", res);
    //             arr[i] *= res;
    //             hold = (u64)arr[i++] * res;
    //             // hold *= (u64)arr[i++];
    //         } else break;
    //     }
    // }
    // u32 a = 0x7FFFFFFF;
    // u32 b = 0x7FFFFFFE;
    // *arr = a;
    // u64 hold = (u64)*arr * b;
    // arr[0] = hold;
    // arr[1] = hold >> 32;
    // b -= 1;
    // hold = (u64)*arr * b;
    // arr[0] = hold;
    // arr[1] = hold >> 32;

    // for (u32 i = 0; i < size; i++)
    //     printf("%X\n", arr[i]);
    // u32 a = 1 & 0;
    // printf("a: %u\n", a);
    // free(arr);