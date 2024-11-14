#include <stdio.h>
#include <stdlib.h>
#define np 0

class ll
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    ll()
    {
        head = NULL;
    }

    void ins_beg(int);
    void ins_end(int);
    void ins_pos(int, int);
    int del_beg();
    int del_end();
    int del_pos(int);
    void display();
};

void ll ::ins_beg(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    printf("%d Insertion Success\n", num);
}

void ll ::ins_end(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = num;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    printf("%d Success", num);
}

void ll ::ins_pos(int num, int pos)
{
    if (pos == 0)
    {
        ins_beg(num);
        return;
    }
    int i = 1;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = num;
    while (i != pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("%d Inserted\n", num);
}

int ll ::del_beg()
{
    if (head == NULL)
    {
        return np;
    }
    struct node *temp = head;
    head = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

int ll ::del_end()
{
    if (head == NULL)
        return np;

    else if (head->next == NULL)
    {
        return del_beg();
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int data = (temp->next)->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}

int ll::del_pos(int pos)
{
    if (head == NULL)
        return np;

    else if (pos == 0)
        return del_beg();

    int i = 1;
    struct node *temp = head;
    while (i != pos)
    {
        temp = temp->next;
        i++;
    }
    int data = temp->next->data;
    temp->next = temp->next->next;
    return data;
}

void ll::display()
{
    struct node *temp = head;
    printf("Linked List = ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    ll l1;
    int num, x, i, pos;
    while (true)
    {
        printf("Enter element to insert: ");
        scanf("%d", &num);
        l1.ins_beg(num);
        l1.display();
        printf("Enter element to insert at end :");
        scanf("%d", &num);
        l1.ins_end(num);
        l1.display();
        printf("element= ");
        scanf("%d", &num);
        printf("Position =");
        scanf("%d", &pos);
        l1.ins_pos(num, pos);
        l1.display();
        x = l1.del_beg();
        if (x == np)
        {
            printf("Can't delete");
            break;
        }
        printf("%d del_beg\n", x);
        l1.display();
        x = l1.del_end();
        if (x == np)
        {
            printf("Can't delete");
            break;
        }
        printf("%d del_end\n", x);
        l1.display();
        x = l1.del_end();
        /* if (x == np)
        {
            printf("Can't delete");
            break;
        }
        printf("%d del_end\n", x);
        l1.display();
        break; */
    }
}