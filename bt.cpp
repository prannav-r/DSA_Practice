#include <stdio.h>
#include <stdlib.h>

class bt
{
    struct node
    {
        int data;
        struct node *left, *right;
    } *root;

public:
    bt()
    {
        root = NULL;
    }

    void insert(int);
};

void bt ::insert(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (root == NULL)
    {
        root = newnode;
        printf("Inserted %d", num);
        return;
    }
    int s;
    printf("Left (1) or Right (2) :");
    scanf("%d", &s);
    struct node *temp = root;
    while (1)
    {
    }
}

int main()
{
    bt b;
    int num, ch;
    while (1)
    {
        printf("Enter Number to insert");
        scanf("%d", &num);
    }
}