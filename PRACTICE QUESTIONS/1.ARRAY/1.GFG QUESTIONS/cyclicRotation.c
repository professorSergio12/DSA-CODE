/*                        Write a program to cyclically rotate an array by one.                       */

#include <stdio.h>

void traversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void CyclicRotation(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Before performing cyclic rotation\n");
    traversal(arr, n);

    CyclicRotation(arr, n);
    printf("\n");
    printf("After performing cyclic rotation\n");
    traversal(arr, n);

    return 0;
}