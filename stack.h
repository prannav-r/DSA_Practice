#include <stdio.h>
#include <stdlib.h>
#define np '0'

class stack
{
    struct node
    {
        int data;
        struct node *next;
    } *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(char);
    char pop();
    char gettop();
};

void stack ::push(char x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

char stack ::pop()
{
    if (top == NULL)
    {
        return np;
    }
    struct node *temp = top;
    char val = top->data;
    top = temp->next;
    free(temp);
    return val;
}

char stack ::gettop()
{
    if (top == NULL)
        return np;

    return top->data;
}
