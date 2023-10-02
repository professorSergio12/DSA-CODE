#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));

    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (X[n - 1] == Y[m - 1])
    {
        return dp[n][m] = 1 + lcs(X, Y, n - 1, m - 1);
    }

    else
    {
        return dp[n][m] = max(lcs(X, Y, n - 1, m), lcs(X, Y, n, m - 1));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    // Find the length of string
    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << lcs(X, Y, m, n);

    return 0;
}
/*Time Complexity: O(N * M), where N and M are lengths of the first and second string respectively. 
Auxiliary Space: (N * M)*/