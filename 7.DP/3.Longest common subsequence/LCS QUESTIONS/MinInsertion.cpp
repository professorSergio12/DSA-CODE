/*Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome. */

#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfInsertions(string A)
{
    string B(A);
    reverse(B.begin(), B.end());

    int n = A.length();
    int m = B.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int index = dp[n][m];
    int answer = n - index;
    return answer;
}

int main()
{
    string A = "agbcba";
    cout << "Length of LCS: " << minimumNumberOfInsertions(A);
}
