/*                                                   k largest elements
Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order.

Example 1:

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.*/

#include <bits/stdc++.h>
using namespace std;

// Expected Time Complexity: O(N + KlogK)
// Expected Auxiliary Space: O(K+(N-K)*logK)
void kLargest(int arr[], int k, int n)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int count = 0;
    while (!pq.empty() && count != k)
    {
        cout << pq.top() << " ";
        pq.pop();
        count++;
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    int ans = 0;
    for (int i = k; i < nums.size(); i++)
    {
        if (pq.top() < nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
        else
        {
            continue;
        }
    }
    ans = pq.top();
    return ans;
}


int main()
{
    int A[] = {11, 5, 12, 9, 44, 17, 2};
    int n = 7;
    int k = 2;
    kLargest(A, k, n);
}