#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//
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
        printf("After Pass %d --> ", i + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

// TIME COMPLEXITY:- O(N)  if array is already sorted
void bubbleSortAdaptive(int *A, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 1; // if array is already sorted it will not set it to 1
            }
        }
        if (isSorted == 0) // it will break the loop and not iterate further
        {
            break;
        }
    }
}

int main()
{
    int size;
    int A[100];
    printf("Enter size of the array :-\n");
    scanf("%d", &size);
    printf("Enter elements in array :-\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }

    bubbleSort(A, size); // Function to sort the array

    printf("After sorting :-\n");

    printArray(A, size); // Printing the array before sorting
    return 0;
}
