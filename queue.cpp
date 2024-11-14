#include <stdio.h>
#include <stdlib.h>
#define np 0

class q
{
    struct node
    {
        int data;
        struct node *next;
    } *front, *rear;

public:
    q()
    {
        front = rear = NULL;
    }

    void enqueue(int);
    int dequeue();
};

void q ::enqueue(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if (front == NULL && rear == NULL)
    {
        newnode->next = NULL;
        front = rear = newnode;
    }
}