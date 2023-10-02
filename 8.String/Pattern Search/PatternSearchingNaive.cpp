/*                                  Naive algorithm for Pattern Searching


Input:  txt[] = “THIS IS A TEST TEXT”,
pat[] = “TEST”
Output: Pattern found at index 10

*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2)
// Auxiliary Space: O(1)
void search(string &pat, string &txt)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }
        if (j == m)
            cout << i << " ";
    }
}

// IMPROVED NAIVE PATTERN SEARCHING FOR DISTINCT
void search(string &pat, string &txt)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }
        if (j == m)
            cout << i << " ";
        if (j == 0)
            i++;
        else
            i = i + j;
    }
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)

int main()
{
}
