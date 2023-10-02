/*                         Find k closest elements to a given value

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].

Examples:

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
*/

#include <bits/stdc++.h>
using namespace std;

// Expected Time Complexity:
// Expected Auxiliary Space:

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{

    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
    }

    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);

        if (diff < pq.top().first)
        {
            pq.pop();
            pq.push({diff, arr[i]});
        }
    }

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second); // push top k elements in the ans
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 35, k = 4;
    printKclosest(arr, x, 4, n);
}