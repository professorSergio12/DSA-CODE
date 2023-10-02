#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool isScrambled(string X, string Y)
{
    if (X.length() != Y.length())
    {
        return false;
    }

    if (X.compare(Y) == 0)
    {
        return true;
    }

    if (X.length() <= 1)
    {
        return false;
    }

    string key = (X + " " + Y);
    if (mp.find(key) != mp.end())
        return mp[key];

    bool flag = false;

    int n = X.length();
    for (int i = 1; i <= n - 1; i++)
    {
        if (isScrambled(X.substr(0, i), Y.substr(n - i, i)) && isScrambled(X.substr(i, n - i), Y.substr(0, n - i)))
        {
            flag = true;
            return true;
        }

        if (isScrambled(X.substr(0, i), Y.substr(0, i)) && isScrambled(X.substr(i, n - i), Y.substr(i, n - i)))
        {
            flag = true;
            return true;
        }
        mp[key] = flag;
    }
    return flag;
}
int main()
{
    string S1 = "coder";
    string S2 = "ocred";

    if (isScrambled(S1, S2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}