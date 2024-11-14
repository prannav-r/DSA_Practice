#include <stdio.h>
#include <stdlib.h>
#define np 0

class cll
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    cll()
    {
        head = NULL;
    }
    void ins_beg(int);
    void disk(int);
    void display();
};

void cll ::ins_beg(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        printf("Inserted");
        return;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
    printf("Inserted");
}

void cll ::disk(int num)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct node *temp = head;
    while (true)
    {
        if (temp->data == num)
        {
            printf("Key is present\n");
            return;
        }
        else if (temp->next == head)
        {
            printf("Key is valid\n");
            break;
        }
        temp = temp->next;
    }
}

void cll ::display()
{
    if (head == NULL)
    {
        printf("Empty CLL");
        return;
    }

    printf("Linked List = ");
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int main()
{
    cll l;
    int i, x, pos, num;
    i = 0;
    while (i != 5)
    {
        printf("num to ins_beg =");
        scanf("%d", &num);
        l.ins_beg(num);
        l.display();
        i++;
    }
    scanf("%d", &num);
    l.disk(num);
}