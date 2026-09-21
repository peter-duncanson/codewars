/*
Given two different positions on a chess board, 
find the least number of moves it would take a 
knight to get from one to the other. The
positions will be passed as two arguments in 
algebraic notation. 
For example, knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.

8
7
6
5
4
3
2
1
  a b c d e f g h

char '1' to short 1 -> '1' - 48
char 'a' to short 1 -> 'a' - 97
*/

#include <stdio.h>
#include <stdbool.h>

short move_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
short move_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool legal(short x, short y)
{
    return (x > 0 && x <= 8 && y > 0 && y <= 8);
}

short knight(const char *p1, const char *p2)
{
    // distance in x and y direction, need to find some way to get these in terms of sum
    // of the elements of move_x and move_y respectively
    // short dx = *p2 - *p1, dy = *++p2 - *++p1, moves = 0;
    short end_x = *++p1 - 48, end_y = *++p2 - 48;
    short moves = 0;

    for (int i = 0; i < 8; i++)
    {
        short x = *p1 - 97, y = *p2 - 97;
        x += move_x[i];
        y += move_y[i];

        if (legal(x, y))
        {
            moves++;
        }
        else
        {
            x -= move_x[i];
            y -= move_y[i];
            continue;
        }


        for (int j = 0; j < 8; j++)
        {
            x += move_x[j];
            y += move_y[j];
            if (legal(x, y))
            {
                moves++;
                if (x == end_x && y == end_y)
                    return moves;
                else continue;
            }
            else
            {
                x -= move_x[j];
                y -= move_y[j];
                continue;
            }
        }
    }
    return -1000;
}

int main(void)
{
    printf("a3 -> b5: %d moves.\n", knight("a3", "b5"));
    printf("h3 -> a7: %d moves.\n", knight("h3", "a7"));
    printf("g6 -> e3: %d moves.\n", knight("g6", "e3"));
    printf("c6 -> b5: %d moves.\n", knight("c6", "b5"));
    printf("a3 -> g4: %d moves.\n", knight("a3", "g4"));
    printf("c6 -> b7: %d moves.\n", knight("c6", "b7"));
    printf("d1 -> c7: %d moves.\n", knight("d1", "c7"));

    return 0;
}
// short dx = (short)(*p2 - 97) - (short)(*p1 - 97);
// short dy = (short)(*++p2 - 48) - (short)(*++p1 - 48);
// dx = (dx > 0) ? dx : dx * -1;
// dy = (dy > 0) ? dy : dy * -1;
// short result = dx - dy;
// return (result > 0) ? result : (result * -1);
