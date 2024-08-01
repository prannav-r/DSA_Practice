//Array implementation of List ADT
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
class List
{
    int arr[SIZE];
    int cur;
    public:
        List()
        {
            cur = -1;
        }
        int insbeg(int);
        void display();
};

int main()
{
    List l1;
    int choice, num;
    while (1)
    {
        getchar();
        getchar();
        system("clear");
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the number insert:");
            scanf("%d",&num);
            if(l1.insbeg(num))
            {
                printf("\n %d successfully inserted.",num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.",num);
            }
            break;
        case 8:
            l1.display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\n Enter a valid choice\n");
            break;
        }

    }
    return 0;
}

//Method to insert a number in begining of the list
int List::insbeg(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(cur==-1)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {
        for(int i=cur;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[0]=num;
        return 1;

    }
}
//Method to display the contents of the list
void List::display()
{
    printf("\nThe contents of the list are:");
    for(int i=0;i<=cur;i++)
    {
        printf("%d ",arr[i]);
    }
}