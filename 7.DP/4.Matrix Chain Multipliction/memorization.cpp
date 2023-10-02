

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int matrixChainMemoised(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        dp[i][j] = matrixChainMemoised(arr, i, k) + matrixChainMemoised(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mini = min(dp[i][j], mini);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int n, int arr[])
{

    memset(dp, -1, sizeof(dp));
    return matrixChainMemoised(arr, 1, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is " << matrixMultiplication(arr, n);
}
