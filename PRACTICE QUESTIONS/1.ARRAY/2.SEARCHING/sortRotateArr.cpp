/*                                Find the position in sorted roatated array
 */

#include <bits/stdc++.h>
using namespace std;

/*                                    NAIVE APPROACH                                                   */
int findPos(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

/*                                     EFFICIENT APPROACH                                             */

// TIME COMPLEXITY: O(log n)
int FindPos(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[low] < arr[mid])
        {
            if (x >= arr[low] && x < arr[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        else
        {
            if (x > arr[mid] && x <= arr[high])
                low = mid + 1;

            else
                high = mid - 1;
        }
    }
    return -1;
}

// TIME COMPLEXITY: O(pos)
int FindPos(int arr[], int x)
{
}

int main()
{
}