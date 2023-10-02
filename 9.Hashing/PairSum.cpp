#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY: O(N * LOG(N))
bool isPair(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sum == (arr[i] + arr[j]))
            {
                return true;
            }
        }
    }
    return false;
}

// EFFICIENT APPROACH

// TIME COMPLEXITY:O(n)
// AUXILLARY SPACE:O(N)

bool IsPair(int arr[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(sum - arr[i]) != s.end())
        {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 6, 3};
    int n = 4;

    int sum;
    cout << "Enter the sum you want:" << endl;
    cin >> sum;

    bool result = isPair(arr, n, sum);
    if (result == true)
    {
        cout << "YES, there is a pair whose sum is " << sum << endl;
    }
    else
    {
        cout << "NO, there is no pair whose sum is " << sum << endl;
    }
}