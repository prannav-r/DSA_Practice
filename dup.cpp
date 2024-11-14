#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#define MAX 100

int main()
{
    stack s;
    char x[MAX];
    char open = '(';
    char close = ')';
    printf("Enter the string : ");
    fgets(x, MAX, stdin);
    printf("Answer = ");
    for (int i = 0; i < strlen(x) - 1; i++)
    {
        if (s.gettop() == np)
        {
            if (x[i] == open)
            {
                s.push(x[i]);
            }
            else
                printf("invalid");
        }
        else
        {
            if (x[i] == close)
            {
                printf(" %c%c ", s.pop(), x[i]);
            }
            else if (x[i] == open)
            {
                s.push(x[i]);
            }
        }
    }
}