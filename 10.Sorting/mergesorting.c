#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
void merge(int A[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
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

    mergesort(A, 0, size - 1); // Function to sort the array

    printf("After sorting :-\n");

    printArray(A, size); // Printing the array before sorting
    return 0;
}

