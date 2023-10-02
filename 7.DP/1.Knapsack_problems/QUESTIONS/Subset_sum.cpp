/*                                SUBSET SUM PROBLEM             */
/*Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. */


#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int W)
{
    bool subset[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int j = 1; j <= W; j++)
        subset[0][j] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                subset[i][j] = subset[i - 1][j - arr[i - 1]] || subset[i - 1][j];
            }

            else
            {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }
    return subset[n][W];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}