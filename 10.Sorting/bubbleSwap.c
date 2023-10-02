#include <stdio.h>

void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void bubbleSort(int A[], int n)
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
                isSorted++;
            }
        }}
        printf("Number swaps are  %d \n",isSorted);
}



int main()
{
    
    int A[]={7, 1, 4, 12, 67, 33, 45};
    int size=7;

    bubbleSort(A, size); // Function to sort the array

    printf("After sorting :-\n");

    printArray(A, size); // Printing the array before sorting
    return 0;
}