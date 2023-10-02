/*Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

Example 1:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y
0 1 2 3 4

The longest subsequence is "xx".*/

#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str)
{
    string str2 = str;

    int n = str.length();
    int m = str2.length();
    int dp[n + 1][m + 1];

    // first row of the lookup table will be all 0s
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) // first column of the lookup table will be all 0s
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str[i - 1] == str2[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string str = "axxxy";
    cout << "The length of the largest subsequence that repeats itself is : " << findLongestRepeatingSubSeq(str);
}
