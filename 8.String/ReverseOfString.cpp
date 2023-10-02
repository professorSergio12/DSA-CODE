/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

*/

#include <bits/stcd++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size() - 1;
        int i = 0;
        int j = n;

        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};