/*
Alright, detective, one of our colleagues successfully observed our target person,
Robby the robber. We followed him to a secret warehouse, where we assume to find 
all the stolen stuff. The door to this warehouse is secured by an electronic 
combination lock. Unfortunately our spy isn't sure about the PIN he saw, when 
Robby entered it.

The keypad has the following layout:

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘

He noted the PIN 1357, but he also said, it is possible that each of the digits 
he saw could actually be another adjacent digit (horizontally or vertically, but 
not diagonally). E.g. instead of the 1 it could also be the 2 or 4. And instead 
of the 5 it could also be the 2, 4, 6 or 8.

He also mentioned, he knows this kind of locks. You can enter an unlimited amount 
of wrong PINs, they never finally lock the system or sound the alarm. That's why 
we can try out all possible (*) variations.

* possible in sense of: the observed PIN itself and all variations considering 
* the adjacent digits

Can you help us to find all those variations? It would be nice to have a function, 
that returns an array of all variations for an observed PIN with a length of 1 to 
8 digits. We could name the function get_pins. But please note that all PINs, the 
observed one and also the results, must be strings, because of potentially leading 
'0's. We already prepared some test cases for you.

Detective, we are counting on you!

The function should return an array of C strings with all possible PINs
It must allocate all required memory, but there are no requirements as to
how it should be done. It must be possible to free allocated memory with a
call to free_pins.
Upon return, count should contain the amount of returned PINs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

const char adj[10][6] = {           // observed
    { '0', '8', '\0', '\0', '\0', '\0' }, // 0
    { '1', '2', '4', '\0', '\0', '\0'  }, // 1
    { '1', '2', '3', '5', '\0', '\0'   }, // 2
    { '2', '3', '6', '\0', '\0', '\0'  }, // 3
    { '1', '4', '5', '7', '\0', '\0'   }, // 4
    { '2', '4', '5', '6', '8', '\0'    }, // 5
    { '3', '5', '6', '9', '\0', '\0'   }, // 6
    { '4', '7', '8', '\0', '\0', '\0'  }, // 7
    { '5', '7', '8', '9', '0', '\0'   }, // 8
    { '6', '8', '9', '\0', '\0', '\0'  }, // 9
};

size_t idx = 0;

void dfs(size_t depth, size_t len, char *current, const char *observed, char **pins)
{
    if (depth == len)
    {
        current[depth] = '\0';
        strcpy(pins[idx++], current);
        return;
    }

    for (const char *c = adj[observed[depth] - '0']; *c; c++)
    {
        current[depth] = *c;
        dfs(depth + 1, len, current, observed, pins);
    }
}

char **get_pins(const char *observed, size_t *count)
{
    size_t len = strlen(observed);

    *count = 1;
    for (const char *p = observed; *p; p++)
        *count *= strlen(adj[*p - '0']);

    char **pins = malloc(sizeof(char *) * (*count));
    for (size_t n = 0; n < *count; n++)
        pins[n] = malloc(len + 1);

    char *current = malloc(len + 1);
    dfs(0, len, current, observed, pins); 
    free(current);

    return pins;
}

void free_pins(char **pins, size_t *count)
{
    for (size_t i = 0; i < *count; i++)
        free(pins[i]);
    free(pins);
    return;
}


int main(void)
{
    size_t count;
    char **pins = get_pins("8", &count);

    for (size_t i = 0; i < count; i++)
        printf("%s\n", pins[i]);

    free_pins((char **)pins, &count);

    return 0;
}
