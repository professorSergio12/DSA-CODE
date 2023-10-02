/*                        Egg Dropping Puzzle

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

*/

// NOTE: PASS ALL THE TEST CASE
#include <bits/stdc++.h>
using namespace std;

int dp[201][201];
int solve(int e, int f)
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

    // check worst case thats why max
    // if egg breaks then egg-1 and floor till kth floor
    // if it doesn't break then egg and floor above k (floor-k) would be 1st floor for next recursion
    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        mini = min(mini, temp); // min of all the worst maxes
    }
    return dp[e][f] = mini;
}

int eggDrop(int e, int f)
{
    memset(dp, -1, sizeof(dp));
    return (solve(e, f));
}

int main()
{
    int e = 2, k = 10;
    cout << "Minimum number of trials in worst case with " << e << " eggs and " << k << " floors is " << eggDrop(e, k) << endl;
    return 0;
}

// PASS ALL THE TEST CASES
/*
unordered_map<int, int> mp;
int solve(int e, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    int flr = f;
    if (mp.find(flr) != mp.end())
    {
        return mp[flr];
    }
    int mn = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int tempAns = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        mn = min(mn, tempAns);
    }
    mp[flr] = mn;
    return mp[flr];
}
int eggDrop(int n, int k)
{
    return solve(n, k);
}

*/