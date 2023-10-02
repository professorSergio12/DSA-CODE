/*
             Find the maximum and minimum element in an array
*/
#include <stdio.h>
#include <limits.h>

int maximum(int *arr, int size)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i]) //finding maximum element
        {
            max = arr[i];
        }

        if (arr[i] < min) //finding minimum element
        {
            min = arr[i];
        }
    }
    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d", min);
}

int main()
{
    int arr[100];
    int size;

    printf("Enter the size of array--->");
    scanf("%d", &size);

    printf("Enter the value--->");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    maximum(arr, size);

    return 0;
}
