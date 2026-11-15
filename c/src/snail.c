#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The numbers of rows and cols are passed separately for historical reasons
// Return a heap allocated array, report the size in *outsz
//
// 0,1
// 1,0
// 0,-1
// -1,0
// for 4x4 once we get 3 first outer edges out of the way
//
// 0,0  0,1  0,2  0,3
// 1,0  1,1  1,2  1,3
// 2,0  2,1  2,2  2,3
// 3,0  3,1  3,2  3,3
//
// 2,0
// 1,0
//
// 1,1
// 1,2
//
// 2,2
//
// 2,1
//
// we switch between fixing x and y
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols)
{
    int *outarr = malloc(sizeof(int) * rows * cols);
  
    int di[4] = { 1, 0, -1, 0 };
    int dj[4] = { 0, 1, 0, -1 };
  
    int visited[rows][cols];
    memset(visited, 0, sizeof(visited));

    size_t count = 0;
    int turns = 0, i = 0, j = 0;
    bool turn_flag = false;

    while (count != rows * cols) {
        if (visited[i][j] == 0) {
            printf("i = %d j = %d\n", i, j);
            outarr[count++] = mx[i][j];
            visited[i][j] = 1;
            i += di[turns % 3];
            j += dj[turns % 3];
            if (i == rows)
                i = rows - 1
            if (i == rows || j == cols || i < 0 || j < 0) {
                if (i == rows)
                    i = rows - 1;
                if (j == cols)
                    j = cols - 1;
                if (i < 0)
                    i = 0;
                if (j < 0)
                    j = 0;
                turns += 1;
                i += di[turns % 4];
                j += dj[turns % 4];
            }
        } else {
            i -= di[turns % 4];
            j -= dj[turns % 4];
            turns += 1;
            i += di[turns % 4];
            j += dj[turns % 4];
        }
    }

    *outsz = count;
    return outarr;
}

int main(void)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t size = 0;
    const int *arr[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = malloc(sizeof(int) * cols);
    
    int *ans = snail(&size, arr, rows, cols);





    return 0;
}
