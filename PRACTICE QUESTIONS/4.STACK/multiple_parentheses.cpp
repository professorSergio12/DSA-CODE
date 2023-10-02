#include <bits/stdc++.h>
using namespace std;

bool marked(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']'))
    {
        return true;
    }

    return false;
}

bool parenthesis_match(string epx)
{
    stack<char> sp;
    char popped_element;
    for (int i = 0; i < epx.length(); i++)
    {
        if (epx[i] == '(' || epx[i] == '[' || epx[i] == '{')
        {
            sp.push(epx[i]);
        }
        else if (epx[i] == ')' || epx[i] == ']' || epx[i] == '}')
        {
            if (sp.empty())
            {
                return false;
            }
            popped_element = sp.top();
            sp.pop();
            if (!marked(popped_element, epx[i]))
            {
                return false;
            }
        }
    }
    if (sp.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string expr = "{()}[]";

    // Function call
    if (parenthesis_match(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
