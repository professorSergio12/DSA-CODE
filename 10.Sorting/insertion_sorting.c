#include <stdio.h>
#include <stdlib.h>

void traversal(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int insertion_sorting(int arr[], int n)
{
    int key, j, i;
    for (i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int A[] = {12, 34, 23, 7, 33, 2};
    int n = 6;
    traversal(A, n);
    insertion_sorting(A, n); // Function to sort the array
    traversal(A, n);         // Printing the array before sorting
}
