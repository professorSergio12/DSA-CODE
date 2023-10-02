

#include <bits/stdc++.h>
using namespace std;

// Naive approach
// Time complexity = O(n^3)
void IsMatch(string str, int i, int j)
{
    vector<bool> vis(256);

    for (int k = i; k < = j; k++)
    {
        if (vis[Str[k]] == true)
        {
            return false;
        }
        vis[str[k]] = true;
    }
    return true;
}

int longestString(string str)
{
    int n = str.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (IsMatch(str, i, j))
            {
                res = max(res, j - i + 1)
            }
        }
    }
    return res;
}

// Time complexity = O(n^2)
int longestString(string str)
{
    int n = str.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> vis(256);
        for (int j = i; j < n; j++)
        {
            if (vis[str[j]] == true)
            {
                break;
            }

            else
            {
                res = max(res, j - i + 1)
                    vis[str[i]] = true;
            }
        }
    }
    return res;
}

int main()
{
}