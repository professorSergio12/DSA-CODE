#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:((m + n) * (m + n))
// SPACE COMPLEXITY:O(N)
int findUnion(int a[], int b[], int n, int m)
{
    int c[m + n];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        c[i] = b[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (c[i] == c[j])
            {
                flag = true;
                break;
            }
        }
        if (flag = false)
        {
            res++;
        }
    }
    return res;
}

// EFFICIENT APPROACH

// TIME COMPLEXITY:((m + n))
// AUXILLARY COMPLEXITY:O(N)
void frequency(int arr[], int size)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }

    return s.size();
}
int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequency(arr, size);
    return 0;
}