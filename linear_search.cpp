#include <stdio.h>

int ls(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return 1;
        }

        return 0;
    }
}

int main()
{
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Element to search : ");
    scanf("%d", &x);
    x = ls(arr, n, x);
    (x = 1) ? printf("element is found") : printf("Not found");
}