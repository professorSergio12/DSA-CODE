
/*Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings
are "a", "babbbab", "b", "ababa".

*/
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool isPalindrome(string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int partitioning(string &s, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i >= j || isPalindrome(s, i, j))
    {
        dp[i][j] = 0;
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        dp[i][j] = partitioning(s, i, k) + partitioning(s, k + 1, j) + 1;
        mini = min(dp[i][j], mini);
    }
    return dp[i][j] = mini;
}

int palindromicPartition(string str)
{
    memset(dp, -1, sizeof(dp));
    return partitioning(str, 0, str.length() - 1);
}

int main()
{
    string str = "ababbbabbababa";
    cout << "Min cuts needed for Palindrome Partitioning is " << palindromicPartition(str) << endl;
}