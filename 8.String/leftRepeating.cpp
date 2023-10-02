

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> temp(127, 0);
        for (int i = 0; i < s.length(); i++)
        {
            temp[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (temp[s[i]] > 1)
                return i;
        }

        return -1;
    }
};