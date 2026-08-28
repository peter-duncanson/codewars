#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *data;
    int top;
} Stack;

bool valid_braces(const char *braces)
{
    Stack s;
    size_t len = strlen(braces);
    s.data = calloc(len, sizeof(char));
    s.top = 0;

    for (const char *p = braces; p < braces + len; p++)
    {
        switch (*p)
        {
            case '(':
            case '[':
            case '{':
                s.data[s.top++] = *p;
                break;
            case ')':
                switch (s.data[s.top - 1])
                {
                    case '(':
                        s.top--;
                        continue;
                    default:
                        return false;
                }
            case '}':
                switch (s.data[s.top - 1])
                {
                    case '{':
                        s.top--;
                        continue;
                    default:
                        return false;
                    continue;
                }
            case ']':
                switch (s.data[s.top - 1])
                {
                    case '[':
                        s.top--;
                        continue;
                    default:
                        return false;
                }
        }
    }
    if (s.top) return false;
    return true;
}


int main(void)
{
    const char *test1 = "(){}[]";       // true
    const char *test2 = "([{}])";       // true
    const char *test3 = "(}";           // false
    const char *test4 = "[(])";         // false
    const char *test5 = "[({})](]";     // false
    
    const char *tests[] = { test1, test2, test3, test4, test5 };

    for (int i = 0; i < 5; i++)
    {
        if (valid_braces(tests[i])) puts("true");
        else puts("false");
    }

    return 0;
}
