/*Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same.                           */

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    return isSubsetSum(arr, n, sum / 2);
}

int main()
{
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";

    int arr2[] = {3, 1, 5, 9, 14};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (findPartiion(arr2, n2) == true)
        cout << endl
             << "Can be divided into two subsets of equal sum";
    else
        cout << endl
             << "Can not be divided into two subsets of equal sum";
    return 0;
}