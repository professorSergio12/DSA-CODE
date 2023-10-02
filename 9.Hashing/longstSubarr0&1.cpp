/*                       Longest sub array with equal number of 0's ans 1's
 */

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

int longestSub(int arr[], int n, int)
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int c0 = 0, c1 = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                c0++;
            else
                c1++;

            if (c0 == c1)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        int prefixSum = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                prefixSum += -1;

            if (nums[i] == 1)
                prefixSum += 1;

            if (prefixSum == 0)
                res = max(res, i + 1);

            else if (mp.find(prefixSum) != mp.end())
                res = max(res, i - mp[prefixSum]);

            else
                mp[prefixSum] = i;
        }
        return res;
    }
};

int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = longestSub(arr, n);
    cout << "The longest subarray with given sum is :" << res << endl;
}