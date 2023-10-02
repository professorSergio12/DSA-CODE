/*                              Count no of subsets with given difference (DP)                */

/*
Let sum of subset 1 be s1 and subset 2 with s2
s1 - s2 = diff (given)
s1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
s1= (diff + sum of array)/2;
Problem reduces to find no of subsets with given sum**
*/

#include <bits/stdc++.h>
using namespace std;

int countWithGivenSum(int arr[], int n, int target)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int reqSum = (target + sum) / 2;

    int dp[n + 1][reqSum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int j = 1; j <= reqSum; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < reqSum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][reqSum];
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff = 1;
    cout << "The minimum difference between 2 sets is " << countWithGivenSum(arr, n, diff);
    return 0;
}