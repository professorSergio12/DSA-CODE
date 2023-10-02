

#include <bits/stdc++.h>
using namespace std;

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

int maxArea(int arr[MAX][MAX], int n, int m)
{
    int res = LargestRectangleArea(arr[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        res = max(res, LargestRectangleArea(arr[i], m));
    }
    return res;
}

int main()
{
}

/* Time Complexity: O(R x C).
Only one traversal of the matrix is required, so the time complexity is O(R X C)

Space Complexity: O(C).
Stack is required to store the columns, so space complexity is O(C)*/