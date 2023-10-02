/*                                                       Previous greater element
Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

Examples:

Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
Output :         -1, 10, 4, -1, -1, 40, 40

Input : arr[] = {10, 20, 30, 40}
Output :        -1, -1, -1, -1

*/

#include <bits/stdc++.h>
using namespace std;

void previousGreater(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }
        int pg = (s.empty()) ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}

// PREVIOUS SMALLEST ELEMENT
vector<int> prevSmaller(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && arr[i] <= s.top())
        {
            s.pop();
        }
        v[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    return v;
}

int main()
{
    int arr[] = {20, 30, 10, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    previousGreater(arr, n);

    printf("\n");
    vector<int> arr1 = {20, 30, 10, 5, 15};
    vector<int> res = prevSmaller(arr1, n);
    for (long long i : res)
    {
        cout << i << " ";
    }
}

/*
Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of array is added and removed from stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).

Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.
*/