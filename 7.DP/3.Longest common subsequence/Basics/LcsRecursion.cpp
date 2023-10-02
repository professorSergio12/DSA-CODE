/*                        Longest Common Subsequence

Given two strings s1 and s2, the task is to find the length of the longest common subsequence present in both of them.

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
LCS for input Sequences "AGGTAB" and "GXTXAYB" is " of length 4.
Input: s1 = "striver", s2 = "raj"
Output: 1  */

#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (X[n - 1] == Y[m - 1])
    {
        return 1 + lcs(X, Y, n - 1, m - 1);
    }

    else
    {
        return max(lcs(X, Y, n - 1, m), lcs(X, Y, n, m - 1));
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