#include <stdlib.h>
#include <stdio.h>

char *factorial(int n)
{
    // allocate solution buffer 
    char *sol = malloc(1000);
    // if the input is negative, return empty string
    if (n < 0) {
        *sol = '\0';
        return sol;
    }

    // save location of start of buffer
    char *p = sol;

    



    return sol;
}

char num_to_char(int n)
{
    return (n % 10) + 48;
}

int main(void)
{
    // int a = 8;
    // char c = to_char(a);
    // printf("%c\n", c);
    char buffer[100];
    sprintf(buffer, "Hello, world!");

    printf("%s\n", buffer);

    return 0;
}