/*                               Find the Union and Intersection of the two sorted arrays.                */

#include <stdio.h>

void unionOFarray(int arr1[], int len1, int arr2[], int len2)
{
    int i, j, f, k = 0;
    int arr3[100];
    for (i = 0; i < len1; i++)
    {
        arr3[k] = arr1[i];
        k++;
    }

    for (i = 0; i < len2; i++)
    {
        f = 0;
        for (j = 0; j < len1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                f = 1;
            }
        }

        if (f == 0)
        {
            arr3[k] = arr2[i];
            k++;
        }
    }

    printf("Union of two array is:");
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr3[i]);
    }
}

void intersection(int arr1[], int len1, int arr2[], int len2)
{
    int i, j, k = 0;
    int arr3[100];
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr3[k] = arr1[i];
                k++;
            }
        }
    }
    printf("\nIntersection of two array is:");
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr3[i]);
    }
}

int main()
{
    int arr1[100];
    int arr2[100];

    int len1;
    int len2;

    printf("Enter the size of 1st array::");
    scanf("%d", &len1);

    printf("Enter the vlaues for 1st array::");
    for (int i = 0; i < len1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of 2st array::");
    scanf("%d", &len2);

    printf("Enter the vlaues for 2st array::");
    for (int i = 0; i < len2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    unionOFarray(arr1, len1, arr2, len2);
    intersection(arr1, len1, arr2, len2);
}

