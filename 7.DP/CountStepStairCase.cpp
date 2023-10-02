/*There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

Input: n = 4
Output: 5
(1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)

*/

#include <bits/stdc++.h>
using namespace std;

// RECURSION APPROACH
int fib(int n, int dp[])
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int countWays(int n)
{
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    return fib(n, dp);
}

// TOP-DOWN APPROACH
int countWay(int n)
{
    int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            dp[i] = dp[i - 1];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[n];
}

int main()
{
    int n = 4;

    cout << "Number of ways = " << countWays(n);

    return 0;
}