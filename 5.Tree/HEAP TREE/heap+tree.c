#include <stdio.h>

int size = 0;
void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < size && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
        }
    }
} 

void insert(int arr[], int element)
{
    if (size == 0)
    {
        arr[0] = element;
        size += 1;
    }
    else
    {
        arr[size] = element;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
    }
}

void deletion(int arr[], int element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (element == arr[i])
            break;
    }
    swap(&arr[i], &arr[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

int main()
{
    int arr[10];

    insert(arr, 4);
    insert(arr, 6);
    insert(arr, 3);
    insert(arr, 8);
    insert(arr, 5);
    insert(arr, 9);
    printf("Max-Heap array: ");
    traversal(arr, size);

    deletion(arr, 9);

    printf("After deleting an element: ");

    traversal(arr, size);
}
