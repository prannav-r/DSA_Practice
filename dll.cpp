#include <stdio.h>
#include <stdlib.h>
#define np 0

class dll
{
    struct node
    {
        int data;
        struct node *next, *prev;
    } *head, *tail;

public:
    dll()
    {
        head = NULL;
        tail = NULL;
    }
    void ins_end(int);
    void disk(int num);
};

void dll::ins_end(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
        printf("Inserted");
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    printf("Inserted");
}

void dll ::disk(int k)
{
    if (k == 1)
    {
        printf("Reversed = %d", head->data);
    }
    printf("Reversed = ");
    struct node *temp = head;
    int i = 1;
    while (i != k)
    {
        temp = temp->next;
        i++;
    }
    while (temp->prev != NULL)
    {
        printf("%d ,", temp->data);
        temp = temp->prev;
    }
    printf("%d", temp->data);
}

int main()
{
    dll l;
    int num, i = 0;
    while (i != 5)
    {
        printf("no to insert_end =");
        scanf("%d", &num);
        l.ins_end(num);
        i++;
    }
    printf("Enter k : ");
    scanf("%d", &num);
    l.disk(num);
}