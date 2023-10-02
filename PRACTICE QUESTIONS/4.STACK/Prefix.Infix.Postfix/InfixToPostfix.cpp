
#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char> sp;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;

        else if (c == '(')
        {
            sp.push('(');
        }

        else if (c == ')')
        {
            while (sp.top() != '(')
            {
                ans += sp.top();
                sp.pop();
            }
            sp.pop();
        }

        else
        {
            while (!sp.empty() && precedence(s[i]) <= precedence(sp.top()))
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
    cout << ans << endl;
}

int main()
{
    string epx = "(a+b)*c";

    infixToPostfix(epx);
    return 0;
}