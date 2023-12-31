/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.*/

#include <bits/stdc++.h>
using namespace std;

int count(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] =  dp[i][j - coin[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 5;
    printf(" %d ", count(arr, n, sum));
    return 0;
}