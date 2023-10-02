#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m)
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    // Find the length of string
    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << LCS(X, Y, m, n);

    return 0;
}
