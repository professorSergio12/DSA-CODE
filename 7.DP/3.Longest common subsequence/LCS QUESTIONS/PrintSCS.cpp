/*                        Printing Shortest Common Supersequence

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest super-sequence exists, print any one of them.

For example, consider the two following sequences, X and Y:

X: ABCBDAB
Y: BDCABA

The length of the SCS is 9
The SCS are ABCBDCABA, ABDCABDAB, and ABDCBDABA
*/

#include <bits/stdc++.h>
using namespace std;

string printShortestSuperSeq(string X, string Y)
{
    int n = X.length();
    int m = Y.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs;

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs.push_back(X[i - 1]); //// Put current character in result
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                lcs.push_back(X[i - 1]);
                i--;
            }
            else
            {
                lcs.push_back(Y[j - 1]);
                j--;
            }
        }
    }
    // If Y reaches its end, put remaining characters of X in the result string
    while (i > 0)
    {
        lcs.push_back(X[i - 1]);
        i--;
    }
    // If X reaches its end, put remaining characters of Y in the result string
    while (j > 0)
    {
        lcs.push_back(X[j - 1]);
        j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string X = "ABCBDAB";
    string Y = "BDCABA";

    cout << printShortestSuperSeq(X, Y);

    return 0;
}