#include <stdio.h>

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

/*                                 ITERATIVELY APPROACH                                        */

int binary_search(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/*                                 RECURSIVE APPROACH                                              */

int binarySearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == element)
        return mid;

    if (arr[i] > element)
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
}

// SORT THE ARRAY
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    int i, j;
    for (i = 0; i < n - 1; i++) // For number of pass
    {
        for (j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size, value, search;
    int arr[100];
    printf("Enter the size:");
    scanf("%d", &size);

    printf("Enter the %d integer\n", size);
    for (int i = 0; i < size; i++)
    {

        scanf("%d", &arr[i]);
    }

    printf("Enter the elements to be searched in an array\n");
    scanf("%d", &value);

    bubbleSort(arr, size);
    printf("sorting array:-\n");
    traversal(arr, size);

    int linear = linear_search(arr, size, value);
    printf("%d", linear);

    search = binary_search(arr, size, value);
    if (search == -1)

    {

        printf("Number is not found in an array");
    }
    else
    {

        printf("Number is found at %d position", search);
    }

    return 0;
}
