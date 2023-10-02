#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n, int sum)
{
    unordered_map<int, int> mp;

    int prefixSum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (prefixSum == sum)
            res = i + 1;

        if (mp.find(prefixSum) == mp.end())
            mp.insert({prefixSum, i});

        if (mp.find(prefixSum - sum) != mp.end())
            res = max(res, i - mp[prefixSum - sum]);
    }
    return res;
}

int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = maxLen(arr, n, 4);
    cout << "The longest subarray with given sum is :" << res << endl;
}