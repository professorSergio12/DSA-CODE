#include <bits/stdc++.h>
using namespace std;

void LCS(string X, string Y, int n, int m)
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

    // Create a character array to store the lcs string
    string str;
    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str.push_back(X[i - 1]);
            i--;
            j--;
        }

        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(str.begin(), str.end());
    cout << "LCS of " << X << " and " << Y << " is " << str;
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int n = X.length();
    int m = Y.length();
    LCS(X, Y, n, m);
    return 0;
}
