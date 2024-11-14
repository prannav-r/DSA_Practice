#include <stdio.h>
#include <stdlib.h>
#define np 0

class cll
{
    struct node
    {
        int data;
        struct node *next;
    } *head, *tail;

public:
    cll()
    {
        head = NULL;
        tail = NULL;
    }
    void ins_end(int);
    void dis();
    int del_end();
};

void cll ::ins_end(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (head == NULL && tail == NULL)
    {
        newnode->next = newnode;
        head = tail = newnode;
        printf("Inserted %d\n", num);
        return;
    }
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
    printf("Inserted %d\n", num);
}

void cll ::dis()
{
    if (head == NULL && tail == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    struct node *temp = head;
    printf("List = ");
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int cll ::del_end()
{
    if (head == NULL && tail == NULL)
    {
        return np;
    }
    else if (head == tail)
    {
        int data = head->data;
        head = tail = NULL;
        return data;
    }
    struct node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    tail = temp;
    int data = temp->next->data;
    tail->next = head;
    return data;
}

int main()
{
    cll l;
    int num, x;
    int i = 0;
    while (1)
    {
        printf("ch = ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Num to ins = ");
            scanf("%d", &num);
            l.ins_end(num);
            break;

        case 2:
            x = l.del_end();
            if (x != np)
            {
                printf("DEleted %d\n", x);
                break;
            }
            printf("Unsuccerss\n");
            break;

        case 3:
            l.dis();
            break;

        case 4:
            break;
        }
    }
}