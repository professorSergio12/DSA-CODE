
#include <bits/stdc++.h>
using namespace std;

bool anagram(string *pat, string *txt, int i)
{
    vector<int> temp(127, 0);

    for (int i = 0; i < txt.length; i++)
    {
        temp[pat[i]]++;
        temp[txt[i + j]]--;
    }

    for (auto x : temp)
    {
        if (x != 0)
            return false;
    }
    return true;
}

bool search(string *pat, string *txt)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (anagram(pat, txt, i))
            return true;
    }
    return false;
}

int main()
{
    string txt = "BACDGABCDA";
    string pat = "ABCD";
    bool sp = search(pat, txt);
    if (sp == true)
    {
        cout << "The anagram pattern is present";
    }
    else
    {
        cout << "The anagram pattern is not present";
    }
}