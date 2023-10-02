/*                           Longest Prefix Suffix

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper
prefix and suffix.
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper
prefix and suffix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int lps(string s)
	{
		int n = s.length();
		int Lps[n];
		Lps[0] = 0;
		int len = 0;
		int i = 1;

		while (i < n)
		{
			if (s[i] == s[len])
			{
				len++;
				Lps[i] = len;
				i++;
			}

			else
			{
				if (len == 0)
				{
					Lps[i] = 0;
					i++;
				}
				else
				{
					len = Lps[len - 1];
				}
			}
		}
		return len;
	}
};

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;

		Solution ob;

		cout << ob.lps(str) << "\n";
	}

	return 0;
}
