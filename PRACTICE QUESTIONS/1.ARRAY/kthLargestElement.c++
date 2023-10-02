/*                          k largest elements

Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be printed in decreasing order.

Example 1:

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    while (!pq.empty() && k > 0)
    {
        ans.push_back(pq.top());
        pq.pop();
        k--;
    }

    return ans;
}

int main()
{
}