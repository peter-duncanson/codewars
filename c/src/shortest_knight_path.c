/*
Given two different positions on a chess board, 
find the least number of moves it would take a 
knight to get from one to the other. The
positions will be passed as two arguments in 
algebraic notation. 
For example, knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    short x;
    short y;
    short step;
    struct node *next;
} BoardSquare;

// helper function to check if a move is in bounds
bool legal_move(short x, short y)
{
    return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

short knight(const char *p1, const char *p2)
{
    BoardSquare *tip = NULL;
    BoardSquare *tail = NULL;

    // arrays to hold displacement for knight moves and visited squares
    short dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    short dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    bool visited[8][8] = { { false } };

    // convert from algebraic notation to base 0 indexing
    short end_x = p2[0] - 'a';
    short end_y = p2[1] - '1';

    short start_x = p1[0] - 'a';
    short start_y = p1[1] - '1';

    visited[start_x][start_y] = true;

    // create the first node as the starting position
    BoardSquare *start = malloc(sizeof(BoardSquare));
    start->x = start_x;
    start->y = start_y;
    start->step = 0;
    start->next = NULL;

    // initialize the queue to for tip and tail to point to start
    tip = start;
    tail = start;

    for (;;)
    {
        // iterate throgh all possible moves array
        for (short i = 0; i < 8; i++)
        {
            // set new position as the x, y of the tip of the queue + valid move
            short x = tip->x + dx[i];
            short y = tip->y + dy[i];

            if (legal_move(x, y) && !(visited[x][y]))
            {
                // add the news square to the queue and set as tail
                BoardSquare *new = malloc(sizeof(BoardSquare));
                new->x = x;
                new->y = y;
                new->step = tip->step + 1;
                new->next = NULL;

                visited[x][y] = true;

                if (new->x == end_x && new->y == end_y)
                {
                    short result = new->step;

                    // free all the memory and return the steps
                    while (tip != NULL)
                    {
                        BoardSquare *temp = tip;
                        tip = tip->next;
                        free(temp);
                    }

                    return result;
                }
                
                // tail pointer now points to the new node
                tail->next = new;
                tail = new;
            }

            else continue;
        }
        
        // pop the tip off the queue and free its memory
        BoardSquare *temp = tip;
        tip = tip->next;
        free(temp);

        // largest possible amount of moves is 6
        if (tip->step > 6)
            break;
    }
    return -1;
}

int main(void)
{
    printf("a3 -> b5: %d moves. 1\n", knight("a3", "b5"));
    printf("h3 -> a7: %d moves. 5\n", knight("h3", "a7"));
    printf("g6 -> e3: %d moves. 3\n", knight("g6", "e3"));
    printf("c6 -> b5: %d moves. 2\n", knight("c6", "b5"));
    printf("a3 -> g4: %d moves. 3\n", knight("a3", "g4"));
    printf("c6 -> b7: %d moves. 2\n", knight("c6", "b7"));
    printf("d1 -> c7: %d moves. 3\n", knight("d1", "c7"));

    return 0;
}
