#include <stdio.h>
#include <stdlib.h>


void test_func(int **a, size_t cols, size_t rows);

int main(void)
{
    int **arr = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++) {
        arr[i] = malloc(sizeof(int) * 4);
    }
    
    test_func(arr, 4, 4);

    for (int i = 0; i < 4; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void test_func(int **a, size_t cols, size_t rows)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
}
