#include <stdio.h>
#include <stdlib.h>
#define np 0

class queue
{
    struct node
    {
        int data;
        struct node *next, *prev;
    } *head, *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    int isempty();
    int enqueue(int);
    int dequeue();
    void peek();
    void display();
};

int queue ::isempty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int queue ::enqueue(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    newnode->prev = NULL;

    if (isempty())
    {
        head = newnode;
        tail = newnode;
        return 1;
    }

    head = newnode;
    (newnode->next)->prev = newnode;
    return 1;
}

int queue ::dequeue()
{
    int data;
    if (isempty())
        return np;

    else if (head->next == NULL)
    {
        data = head->data;
        head = NULL;
        tail = NULL;
        return data;
    }

    data = tail->data;
    tail = tail->prev;
    return data;
}

void queue ::peek()
{
    if (isempty())
        printf("Queue is Empty!\n");

    else
        printf("Front Element is: %d", tail->data);
}

void queue ::display()
{
    if (isempty())
        printf("Queue is Empty");

    struct node *temp = head;
    while (temp != tail)
    {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    free(temp);
}

int main()
{
    queue l1;
    int ch;
    int num;
    int ans;
    while (true)
    {

        printf("\n Queue \n");
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Display \n 5.Exit \n");
        printf("\n Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number: ");
            scanf(" %d", &num);
            if (l1.enqueue(num))
            {
                printf("\n Inserted %d successfully.\n", num);
            }
            else
            {
                printf("\n Insertion unsuccessful. Array is Full.\n");
            }
            break;

        case 2:
            ans = l1.dequeue();

            if (ans != np)
                printf("\n Dequeued %d", ans);

            else
                printf("\n Queue empty.\n");

            break;

        case 3:
            l1.peek();
            break;

        case 4:
            l1.display();

        case 5:
            return 0;

        default:
            printf("Enter a valid choice!");
        }
    }
}