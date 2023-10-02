/*                       Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

*/


#include <stdio.h>

long long merge(long long A[], int mid, int low, int high)
{
    long long inversionCount = 0;
    int i = low, j = mid + 1;
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
            inversionCount += (mid - i + 1);
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
    return inversionCount;
}

long long mergesort(long long A[], int low, int high)
{
    long long inversionCount = 0;
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        inversionCount += mergesort(A, low, mid);
        inversionCount += mergesort(A, mid + 1, high);
        inversionCount += merge(A, mid, low, high);
    }
    return inversionCount;
}

int main()
{
    int N = 5;
    long long arr[] = {1, 9, 6, 4, 5};

    int inversionCount = mergesort(arr, 0, N - 1); // Function to sort the array
    printf("The inversion count is %d", inversionCount);
}
