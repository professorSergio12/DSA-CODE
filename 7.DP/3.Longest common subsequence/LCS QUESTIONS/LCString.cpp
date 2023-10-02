/*Given two strings "X" and "Y", find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5 */

#include <bits/stdc++.h>
using namespace std;

int LCSubStr(string X, string Y, int n, int m)
{
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

    // fill the lookup table in a top-down manner
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int max = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }
    return max;
}

int main()
{
    string X = "ABCDGH";
    string Y = "ACDGHR";

    // Find the length of string
    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << LCSubStr(X, Y, m, n);
}