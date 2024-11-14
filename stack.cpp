#include <stdio.h>
#include <stdlib.h>
#define np 0

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

    void push(int);
    int pop();
    int gettop();
};

void stack ::push(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = top;
    top = newnode;
    printf("Inserted %d\n", num);
}

int stack ::pop()
{
    if (top == NULL)
    {
        return np;
    }
    struct node *temp = top;
    int val = top->data;
    top = temp->next;
    free(temp);
    return val;
}

int stack ::gettop()
{
    if (top == NULL)
        return np;

    return top->data;
}

int main()
{
    stack s;
    int num, ch, x;
    while (1)
    {
        printf("ch = ");
        scanf("%d", &ch);
        switch (ch)
        {
            {
            case 1:
                printf("no to insert = ");
                scanf("%d", &num);
                s.push(num);
                break;

            case 2:
                x = s.pop();
                if (x == np)
                {
                    printf("Empty Stack\n");
                    break;
                }
                printf("Pop value = %d\n", x);
                break;

            case 3:
                x = s.gettop();
                if (x == np)
                {
                    printf("Top is NULL\n");
                    break;
                }
                printf("Top = %d\n", x);
                break;

            default:
                break;
            }
        }
    }
}