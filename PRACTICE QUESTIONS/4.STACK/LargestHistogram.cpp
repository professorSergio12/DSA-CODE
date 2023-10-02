
#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
            {
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
            {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}

// Efficient Approach
// TIME COMPLEXITY:-O(N);
// AUXILARY COMPLEXITY:-O(N);
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

vector<int> nextSmaller(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> v(n);

    for (int i = n - 1; i >= 0; i--)
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

int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ps = prevSmaller(arr, n);
    vector<int> ns = nextSmaller(arr, n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = (ns[i] - ps[i] - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}

// Efficient Approach
// TIME COMPLEXITY:-O(N);
// AUXILARY COMPLEXITY:-O(1);

int LargestRectangleArea(int arr[], int n)
{
    stack<int> s;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = largest(arr, n);
    int res1 = LargestRectangleArea(arr, n);
    cout << "By naive approach:" << res << endl;
    cout << "By efficient approach: " << res1;
}