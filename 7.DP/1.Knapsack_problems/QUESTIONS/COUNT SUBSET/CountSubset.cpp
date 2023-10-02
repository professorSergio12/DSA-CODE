/* Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.*/


#include <bits/stdc++.h>
using namespace std;

int fndCount(int arr[], int n, int W)
{
    int subset[n + 1][W + 1];

    subset[0][0] = 1;
    for (int j = 1; j <= W; j++)
        subset[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                subset[i][j] = subset[i - 1][j - arr[i - 1]] + subset[i - 1][j];
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
    int n = 4;
    int a[] = {3, 3, 3, 3};
    int sum = 6;

    cout << (fndCount(a, n, sum));
}