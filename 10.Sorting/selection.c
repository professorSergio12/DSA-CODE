#include <stdio.h>

void traversal(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int selection_sorting(int *arr, int n)
{
    int indexmin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexmin])
            {
                indexmin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }
}

int main()
{
    int A[] = {12, 34, 23, 7, 33, 2};
    int n = 6;
    traversal(A, n);
    selection_sorting(A, n); // Function to sort the array
    traversal(A, n);         // Printing the array before sorting
}
