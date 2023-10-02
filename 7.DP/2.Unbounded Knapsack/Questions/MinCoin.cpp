/*Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = { C1, C2, .., Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents
*/

#include <bits/stdc++.h>
using namespace std;

// n is size of coins array (number of different coins)
int minCoins(int coins[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = INT_MAX - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[i][j] = j / coins[0];
            }
            else
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][sum] == INT_MAX - 1)
    {
        return -1;
    }
    else
    {
        return dp[n][sum];
    }
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is " << minCoins(coins, m, V);
}

/*              The time complexity of the above solution is O(mV).         */