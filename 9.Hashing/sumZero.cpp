#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:O(N^2)
bool fun(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == 0)
                return true;
        }
    }
    return false;
}

bool isSubarray(int arr[], int n)
{
    unordered_set<int> s;
    int prev_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prev_sum += arr[i];
        if (s.find(prev_sum) != s.end())
            return true;
        if (prev_sum == 0)
            return true;
        s.insert(prev_sum);
    }
    return false;
}
// If we have to return the length if that subarray
int isSubarray(int arr[], int n)
{
    unordered_map<int, int> mp;
    int res = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0)
            res = i + 1;

        if (s.find(prefixSum) == s.end())
        {
            mp.insert({prefixSum, i});
        }

        if (s.find(prefixSum) != s.end())
        {
            res = max(res, i - mp[prefixSum]);
        }
    }
    return res;
}

int main()
{
    int arr[] = {4, -3, 2, 9};
    int n = 4;

    bool result = isSubarray(arr, n);
    if (result == true)
    {
        cout << "YES, there is a subset whose sum is 0" << endl;
    }
    else
    {
        cout << "NO, there is no subset whose sum is 0" << endl;
    }
}