/*Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Example:
Input
3
8
20
13
Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the
two possible permutations but
these represent the same
cobmination. Hence output is 1.*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][3];
int arr[3] = {3, 5, 10};
int long long util(int long long n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    int ans = 0;
    for (int i = x; i < 3; i++) // here x is index of an array
    {
        ans += util(n - arr[i], i);
    }
    return dp[n][x] = ans;
}
long long int count(long long int n)
{
    memset(dp, -1, sizeof(dp));
    return util(n, 0);
}

int main()
{
    int n = 20;
    cout << "Output: " << count(n);
}