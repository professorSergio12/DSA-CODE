#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:(m*(m + n))
// SPACE COMPLEXITY:O(1)

int intersection(int a[], int b[], int n, int m)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i - 1; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }

        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}

// EFFICIENT APPROACH

// TIME COMPLEXITY:((m + n))
// SPACE COMPLEXITY:O(N)

int Intersection(int a[], int b[], int n, int m)
{
    int res = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (s.find(b[i]) != s.end())
        {
            res++;
            s.erase(b[i]);
        }
    }
    return res;
}

int main()
{
    int a[] = {10, 15, 20, 15, 30, 30, 5};
    int b[] = {30, 5, 30, 80};

    int n = 7;
    int m = 4;

    int result = intersection(a, b, n, m);
    cout << "The number of intersections are:" << result << endl;

    int ans = Intersection(a, b, n, m);
    cout << "The number of intersections are:" << ans;
}