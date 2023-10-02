/* [V. IMP]                                   Find Largest sum contiguous Subarray[ Kadane's Algorithm ]               */

#include <bits/stdc++.h>
using namespace std;

/*                                         NAIVE APPROACH                                           */
// TIME COMPLEXITY:- O(n^2);
// SPACE COMPLEXITY:- O(1);
int maxsubArrySum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr = curr + arr[i];
            res = max(res, curr);
        }
    }
    return res;
}

// TIME COMPLEXITY:- O(n);
// SPACE COMPLEXITY:- O(1);
long long maxSubarraySum(int arr[], int n)
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

int main()
{
    int arr[] = {8, -4, 3, -5, 4};
    int n = 5;

    int max = maxSubarraySum(arr, n);
    printf("%d", max);

    return 0;
}