#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_func(int **a, size_t cols, size_t rows);

int main(void)
{
    int a[5][5];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 || j == 0 || i == 4 || j == 4)
                a[i][j] = 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }

    return 0;
}
