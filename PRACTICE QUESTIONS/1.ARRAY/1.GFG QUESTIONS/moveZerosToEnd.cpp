
#include <bits/stdc++.h>
using namespace std;

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/*                                         NAIVE APPROACH                               */

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:-O(1)
void MoveZeroToEnd(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

/*                                               EFFICIENT APPROACH                                 */

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
void moveZeroToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main()
{
    int arr[] = {12, 4, 0, 0, 6, 0, 3, 0, 0};
    int n = 9;

    MoveZeroToEnd(arr, n);
    traversal(arr, n);
}