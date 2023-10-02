
/*                                              Reverse the array                                      */

#include <stdio.h>

void traversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void reverse(int arr[], int size)
{
    int temp;
    int n = size / 2;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    printf("Before performing reverse operation\n");
    traversal(arr, n);

    reverse(arr, n);
    printf("\n");
    printf("After performing reverse operation\n");
    traversal(arr, n);

    return 0;
}
