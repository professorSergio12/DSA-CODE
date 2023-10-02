/*                        Check if a string is a scrambled form of another string

Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
Scrambled string:
Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.

Below is one possible representation of str = "coder":

    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r
To scramble the string, we may choose any non-leaf node and swap its two children.
Suppose, we choose the node "co" and swap its two children, it produces a scrambled string "ocder".

    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
Thus, "ocder" is a scrambled string of "coder".

Input: S1="coder", S2="ocder"
Output: Yes

*/

#include <bits/stdc++.h>
using namespace std;

bool isScramble(string S1, string S2)
{
    if (S1.length() != S2.length())
    {
        return false;
    }

    if (S1.compare(S2) == 0)
    {
        return true;
    }

    if (S1.length() <= 1)
    {
        return false;
    }

    int n = S1.length();
    for (int i = 1; i <= n - 1; i++)
    {
        if (isScramble(S1.substr(0, i), S2.substr(n - i, i)) && isScramble(S1.substr(i, n - i), S2.substr(0, n - i)))
        {
            return true;
        }

        if (isScramble(S1.substr(0, i), S2.substr(0, i)) && isScramble(S1.substr(i, n - i), S2.substr(i, n - i)))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string S1 = "coder";
    string S2 = "ocred";

    if (isScramble(S1, S2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}