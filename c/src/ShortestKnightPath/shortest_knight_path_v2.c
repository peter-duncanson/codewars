// Array based implimentation
#include <stdbool.h>

typedef struct
{
    short x;
    short y;
    short step;
} BoardSquare;

BoardSquare queue[64];

bool legal_move(short x, short y)
{
    return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

short knight(const char *p1, const char *p2)
{
    short dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    short dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool visited[8][8] = { { false } };

    short head = 0, tail = 0;
    short end_x = p2[0] - 'a';
    short end_y = p2[1] - '1';
    short start_x = p1[0] - 'a';
    short start_y = p1[1] - '1';

    visited[start_x][start_y] = true;

    queue[tail++] = (BoardSquare){ start_x, start_y, 0 };

    while (head < tail)
    {
        BoardSquare current = queue[head++];
        for (short i = 0; i < 8; i++)
        {
            short x = current.x + dx[i];
            short y = current.y + dy[i];
            
            if (legal_move(x, y) && !visited[x][y])
            {
                visited[x][y] = true;

                if (x == end_x && y == end_y)
                    return current.step;

                queue[tail++] = (BoardSquare){ x, y, current.step + 1 };
            }
        }
    }
    return -1;
}
