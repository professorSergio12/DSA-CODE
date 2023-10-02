
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
/*                        Find maximum circular sum Subarray

Example:
Input:-
arr[] = {5, -2, 3, 4};

Output:-
Max sum = 12;

*/

/*                                         NAIVE APPROACH                               */

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:-O(1)
int RotatedArray(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = arr[i];
        int curr_max = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_sum, curr_max);
        }
        res = max(res, curr_max);
    }
    return res;
}

/*                                               EFFICIENT APPROACH                                 */

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)

maxSubarraySum(int arr[], int n)
{

    int maxi = INT_MIN;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum = currsum + arr[i];
        if (currsum > maxi)
        {
            maxi = currsum;
        }
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxi;
}

int RotatedArray(int arr[], int n)
{
    int maxNormal = maxSubarraySum(arr, n);

    if (maxNormal < 0)
        return maxNormal;

    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i]; // here we perform inversion mean {-8, 4, -3, 5, -4}.
    }
    // Now by using kadane algo we are basically finding minimum sum in original array by doing inversion of an array.
    int max_circular = arr_sum + maxSubarraySum(arr, n);
    return max(maxNormal, max_circular);
}

int main()
{
    int arr[] = {8, -4, 3, 5, 4};
    int n = 5;

    int max = RotatedArray(arr, n);
    printf("%d", max);
}
