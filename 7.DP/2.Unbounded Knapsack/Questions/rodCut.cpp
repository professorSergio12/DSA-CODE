/*Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) */

#include <bits/stdc++.h>
using namespace std;

int rodCut(int price[], int n)
{
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int L = n;
    int dp[n + 1][L + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < L + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][L];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    // Function Call
    cout << "Maximum obtained value  is " << rodCut(price, n) << endl;
}