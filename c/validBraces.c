#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validBraces(const char *braces);

char rightCurly = 0x7D;
char leftCurly = 0x7B;
char rightSquare = 0x5D;
char leftSquare = 0x5B;
char rightParen = 0x29;
char leftParen = 0x28;

int main(void)
{
    // const char *strLit = ")))";
    // printf("%zu\n", strlen(strLit));
    //
    // for (unsigned int i = 0; i <= strlen(strLit); i++)
    // {
    //     printf("%x\n", strLit[i]);
    // }
    //
    // if (rightParen == strLit[0])
    // {
    //     printf("OH YEA\n");
    // }
    // validBraces("(){}[]");
    validBraces("[(])");
    return 0;
}
bool validBraces(const char *braces)
{
    int count[3] = {0, 0, 0};
    char flags = 0b000000;
    for (unsigned int i = 0; i <= strlen(braces); i++)
    {
        if (braces[i] == 0x7B) // {
        {
            flags ^= 0b100000;
        }
        if (braces[i] == 0x7D) // }
        {
            if ()
            flags ^= 0b010000;
        }
        if (braces[i] == 0x5B) // [
        {
            flags ^= 0b001000;
        }
        if (braces[i] == 0x5D) // ]
        {
            flags ^= 0b000100;
        }
        if (braces[i] == 0x28) // (
        {
            flags ^= 0b000010;
        }
        if (braces[i] == 0x29) // )
        {
            flags ^= 0b000001;
        }
    }
}
// bool validBraces(const char *braces)
// {
//     int count[3] = {0, 0, 0};
//     char flags = 0b000;
//     for (unsigned int i = 0; i <= strlen(braces); i++)
//     {
//         if (braces[i] == 0x7B) // {
//         {
//             count[0]++;
//             flags |= 0b001;
//             printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//             printf("flags: %b\n", flags);
//         }
//         if (braces[i] == 0x7D) // }
//         {
//             count[0]--;
//             if ((flags & 0b001) && (count[0] == 0))
//             {
//                 flags ^= 0b001;
//                 printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//                 printf("flags: %b\n", flags);
//             }
//             else if (count[0])
//             {
//                 continue;
//             }
//             else
//             {
//                 printf("RETURNED FALSE IN 0x7D\n");
//                 return false;
//             }
//         }
//         if (braces[i] == 0x5B) // [
//         {
//             count[1]++;
//             flags |= 0b010;
//
//             printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//             printf("flags: %b\n", flags);
//         }
//         if (braces[i] == 0x5D) // ]
//         {
//             count[1]--;
//             printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//             printf("flags: %b\n", flags);
//             if ((flags & 0b010) && (count[1] == 0))
//             {
//                 flags ^= 0b010;
//                 printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//                 printf("flags: %b\n", flags);
//             }
//             else if (count[1])
//             {
//                 continue;
//             }
//             else
//             {
//                 printf("RETURNED FALSE IN 0x5D");
//                 return false;
//             }
//         }
//         if (braces[i] == 0x28) // (
//         {
//             count[2]++;
//             flags |= 0b100;
//             printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//             printf("flags: %b\n", flags);
//         }
//         if (braces[i] == 0x29) // )
//         {
//             count[2]--;
//             printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//             printf("flags: %b\n", flags);
//             if ((flags & 0b100) && (count[2] == 0))
//             {
//                 flags ^= 0b100;
//                 printf("count: \t%d\t%d\t%d\n", count[0], count[1], count[2]);
//                 printf("flags: %b\n", flags);
//             }
//             else if (count[2])
//             {
//                 continue;
//             }
//             else
//             {
//                 printf("RETURNED FALSE IN 0x29\n");
//                 return false;
//             }
//         }
//     }
//     if (flags & 0b111)
//     {
//         printf("RETURNED FALSE ON FLAG CHECK\n");
//         return false;
//
//     }
//     for (int i = 0; i <= 2; i++)
//     {
//         if (count[i])
//         {
//             printf("RETURNED FALSE ON COUNT CHECK\nCOUNT # %d", i);
//             return false;
//         }
//     }
//     printf("reached end\n");
//
//     return true;
// }
//
/*
 * } = 7D
 * { = 7B
 * ] = 5D
 * [ = 5B
 * ) = 29
 * ( = 28
 */
