#include <bits/stdc++.h>
using namespace std;

int dp[11][51]; // NOTE: PASS ALL THE TEST CASE
int eggDrop(int e, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }

    if (e == 1)
    {
        return f;
    }

    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int low, high;
        if (dp[e - 1][k - 1] != -1)
        {
            low = dp[e - 1][k - 1];
        }
        else
        {
            low = eggDrop(e - 1, k - 1);
            dp[e - 1][k - 1] = low;
        }

        if (dp[e][f - k] != -1)
        {
            high = dp[e][f - k];
        }
        else
        {
            high = eggDrop(e, f - k);
            dp[e][f - k] = high;
        }

        int temp = 1 + max(low, high);
        mini = min(temp, mini);
    }
    return mini;
}

int main()
{
    int e = 2, k = 10;
    memset(dp, -1, sizeof(dp));
    cout << "Minimum number of trials in worst case with " << e << " eggs and " << k << " floors is " << eggDrop(e, k) << endl;
    return 0;
}