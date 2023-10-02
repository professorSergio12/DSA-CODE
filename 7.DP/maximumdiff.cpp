/*Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s - number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example 1:

Input : S = "11000010001"
Output : 6
Explanatio: From index 2 to index 9,
there are 7 0s and 1 1s, so number
of 0s - number of 1s is 6. */

#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string str)
{
    int ans = 0;
    int currsum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = 0;
        if (str.at(i) == '0')
        {
            val = +1;
        }
        else if (str.at(i) == '1')
        {
            val = -1;
        }

        if (currsum > 0)
        {
            currsum += val;
        }
        else
        {
            currsum = val;
        }
        if (currsum > ans)
        {
            ans = currsum;
        }
    }
    if (ans == 0)
    {
        ans = -1;
    }
    return ans;
}

int main()
{
    string S = "11000010001";
    cout << "The max substring is " << maxSubstring(S);

    return 0;
}