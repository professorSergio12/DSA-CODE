#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    string tmp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
    if (mp.find(tmp) != mp.end())
        return mp[tmp];

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lT = solve(s, i, k - 1, true);
        int lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true);
        int rF = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
                ans += lT * rT;
            else
                ans += lT * rF + lF * rT + lF * rF;
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
                ans += lT * rF + lF * rT + lT * rT;
            else
                ans += lF * rF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += lT * rF + lF * rT;
            else
                ans += lF * rF + lT * rT;
        }
    }
    return mp[tmp] = ans % 1003;
}

int countWays(int N, string S)
{
    // code here

    return solve(S, 0, N - 1, true);
}

int main()
{

    string S = "T|T&F^T";
    int N = 7;
    cout << "The no of pare parenthesize are " << countWays(N, S);
    return 0;
}