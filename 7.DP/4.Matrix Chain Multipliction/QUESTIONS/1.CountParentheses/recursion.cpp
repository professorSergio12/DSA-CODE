/*                     Boolean Parenthesization Problem
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

*/

// NOTE:- This code do not passs the test case because it take lot of time and exceded the time limt
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

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
    return ans;
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

