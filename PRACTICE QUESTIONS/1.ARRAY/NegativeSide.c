/*                       Move all the negative elements to one side of the array                */

#include <stdio.h>

void traversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void shiftfall(int arr[], int left, int right)
{
    while (left <= right)
    {
        //condition to check if the left and the right elements are negative
        if (arr[left] < 0 && arr[right] < 0)
        {
            left += 1;
        }

        //Condition to check if the left pointer element is positive and the right pointer element is negative
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp;
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }

        // Condition to check if both the elements are positive
        else if (arr[left] > 0 && arr[right] > 0)
        {
            right -= 1;
        }

        else
        {
            left += 1;
            right -= 1;
        }
    }
}

// Alternative method

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(&arr[i], &arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    shiftfall(arr, 0, n - 1);
    printf("The order used by Two Pointer Approach ::\n");
    traversal(arr, n);

    //  Alternative method
    printf("\n");
    rearrange(arr, n);
    printf("The order by simple method ::\n");
    traversal(arr, n);
}