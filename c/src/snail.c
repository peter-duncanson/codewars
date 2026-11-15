#include <stdlib.h>
#include <string.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols)
{
    int *outarr = malloc(sizeof(int) * rows * cols);
    int di[4] = { 0, 1, 0, -1 };
    int dj[4] = { 1, 0, -1, 0 };
    int visited[rows + 2][cols + 2];
    int turns = 0, i = 1, j = 1, n = rows;
    size_t count = 0;
    memset(visited, 0, sizeof(visited));
    // create hedge around visited array
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                visited[i][j] = 1;
        }
    }

    while (count != rows * cols) {
        if (visited[i][j] == 0) {
            outarr[count++] = mx[i - 1][j - 1];
            visited[i][j] = 1;
            i += di[turns % 4];
            j += dj[turns % 4];
        } else {
            i -= di[turns % 4];
            j -= dj[turns % 4];
            turns++;
            i += di[turns % 4];
            j += dj[turns % 4];
        }
    }
    *outsz = count;
    return outarr;
}