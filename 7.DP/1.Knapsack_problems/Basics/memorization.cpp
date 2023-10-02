// Memorization


#include <bits/stdc++.h>
using namespace std;

int knapSack(int wt[], int val[], int W, int n)
{
    int dp[n + 1][W + 1];
    memset(dp, -1, sizeof(dp));

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n - 1] > W)
    {
        return dp[n][W] = knapSack(wt, val, W, n - 1);
    }
    else
    {
        return dp[n][W] = max(val[n - 1] + knapSack(wt, val, W - wt[n - 1], n - 1), knapSack(wt, val, W, n - 1));
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt, val, W, n);
    return 0;
}