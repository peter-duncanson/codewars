#include <stdlib.h>
#include <stdio.h>

int **multiplication_table(int n)
{
    int **table = malloc(n * sizeof(*table));
    
    for (int k = 0; k < n; k++)
        table[k] = malloc(n * sizeof(*table[k]));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i - 1][j - 1] = i * j;
            printf("%d ", i * j);
        }
    }
    return table;
}

int main(void)
{
    multiplication_table(5);
    return 0;
}
