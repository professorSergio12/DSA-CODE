/*Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.*/

#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int diff = INT_MAX;

    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is " << findMin(arr, n);
    return 0;
}