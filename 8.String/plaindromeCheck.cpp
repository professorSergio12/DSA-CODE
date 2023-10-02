/*                  Palindrome check
We have given an string. Write a program to find whether the given string is palindrome or not
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
	// Time complexity : - O(n);
	// Space complexity : - O(n);
	int isPalindrome(string S)
	{
		string st = S;
		reverse(st.begin(), st.end());
		if (S == st)
		{
			return 1;
		}
		return 0;
	}

	// Time complexity : - O(n);
	// Space complexity : - O(1);
	int isPalindrome(string S)
	{
		int begin = 0;
		int end = S.length() - 1;

		while (begin < end)
		{
			if (S[begin] != S[end])
			{
				return 0;
			}
			begin++;
			end--;
		}
		return 1;
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
		string s;
		cin >> s;

		Solution ob;

		cout << ob.isPalindrome(s) << "\n";
	}

	return 0;
}
// } Driver Code Ends