/*                             Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> temp(127, 0);

        if (s.length() != t.length())
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            temp[s[i]]++;
            temp[t[i]]--;
        }

        for (auto x : temp)
        {
            if (x > 0)
                return false;
        }
        return true;
    }
};