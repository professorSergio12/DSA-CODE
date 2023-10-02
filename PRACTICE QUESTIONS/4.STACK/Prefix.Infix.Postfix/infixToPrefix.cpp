
#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char> sp;
    string ans;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;

        else if (c == ')')
        {
            sp.push(')');
        }

        else if (c == '(')
        {
            while (sp.top() != ')')
            {
                ans += sp.top();
                sp.pop();
            }
            sp.pop();
        }

        else
        {
            while (!sp.empty() && precedence(s[i]) < precedence(sp.top()))
            {
                ans += sp.top();
                sp.pop();
            }
            sp.push(c);
        }
    }

    while (!sp.empty())
    {
        ans += sp.top();
        sp.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{
    string epx = "x+y/z-w*u";

    infixToPostfix(epx);
    return 0;
}