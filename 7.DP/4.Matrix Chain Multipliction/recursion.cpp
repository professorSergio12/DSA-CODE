

#include <bits/stdc++.h>
using namespace std;

// Function for matrix chain multiplication
int MatrixChainOrder(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    int min = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = MatrixChainOrder(arr, i, k) + MatrixChainOrder(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp < min)
        {
            min = temp;
        }
    }
    return min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1);
}
