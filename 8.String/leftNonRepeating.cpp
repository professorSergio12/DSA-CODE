/*                                     First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1


Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/

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
            if (temp[s[i]] == 1)
                return i;
        }

        return -1;
    }
};