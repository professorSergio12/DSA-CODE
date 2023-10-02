#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:O(N * LOG(N))
// SPACE COMPLEXITY:O(1)

int LongestConsecutiveSequence(int arr[], int n)
{
    sort(arr, arr + n);
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            continue;

        if (arr[i] == arr[i - 1] + 1)
            count++;

        else
        {
            res = max(res, count);
            count = 1;
        }
    }
    return res;
}

// TIME COMPLEXITY:O(N)
// SPACE COMPLEXITY:O(N)
int LongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> s(a.begin(), a.end());

    int count = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) != s.end())
        {
            count = 1;

            while (s.find(arr[i] + count))
            {
                count++;
            }
            res = max(res, count);
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