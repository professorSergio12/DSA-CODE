#include <bits/stdc++.h>
using namespace std;

// NIAVE APPROACH
// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY: O(1)
int countDistinct(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            res++;
        }
    }
    return res;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
int CountDistinct(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}

// Another Efficient Approach
int CountDistinct(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    return s.size();
}

int main()
{
    int arr[] = {10, 20, 20, 30, 20, 30, 50, 50};
    int n = 8;
    int ans = CountDistinct(arr, n);
    printf("The number of distinct are: %d", ans);
}