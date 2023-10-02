#include <stdio.h>

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int inserting(int arr[], int size, int value, int index, int capacity)
{
    if (size > capacity)
    {
        return 0;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

int deletion(int arr[], int size, int index)
{
    for (int i = index; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int index, size, value, index1;
    int arr[100];
    printf("Enter size of the array :-\n");
    scanf("%d", &size);
    printf("Enter elements in array :-\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to insert:\n ");
    scanf("%d", &value);

    printf("Enter the index in which you want to insert:-\n");
    scanf("%d", &index);

    printf("Before insertion:-\n");
    traversal(arr, size);

    inserting(arr, size, value, index, 100);
    size += 1;
    printf("After insertion:-\n");
    traversal(arr, size);

    printf("Enter the index you want to delete:-\n");
    scanf("%d", &index1);

    printf("Before deletion:-\n");
    traversal(arr, size);

    deletion(arr, size, index1);
    size -= 1;
    printf("After deletion:-\n");
    traversal(arr, size);
}