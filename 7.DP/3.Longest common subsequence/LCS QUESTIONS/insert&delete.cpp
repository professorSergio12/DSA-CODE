/*Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1
*/

#include <bits/stdc++.h>
using namespace std;

int printMinDelAndInsert(string X, string Y, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
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
    string X = "heap";
    string Y = "pea";

    // Find the length of string
    int n = X.length();
    int m = Y.length();

    int len = printMinDelAndInsert(X, Y, n, m);

    cout << "Minimum number of deletions = " << (n - len) << endl;

    cout << "Minimum number of insertions = " << (m - len) << endl;
    return 0;
}

/*
Input: str1 = "heap", str2 = "pea"
Output: 3

int minOperations(string str1, string str2) 
	{ 
	   int n=str1.length(); 
	   int m=str2.length(); 
	   
	   int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
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
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[n][m];
    int insert = n - abs(lcs);
    int del = m - abs(lcs);
    return insert + del;
	    
	} 














*/