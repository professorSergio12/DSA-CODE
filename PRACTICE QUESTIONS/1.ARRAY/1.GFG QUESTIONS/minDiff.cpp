

#include <bits/stdc++.h>
using namespace std;

/*                                        NAIVE APPROACH                                   */
// TIME COMPLEXITY:- O(N^2)
// SPACE COMPLEXITY:-O(1)
int midDiff(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxi = max(maxi, arr[j] - arr[i]);
        }
    }
    return maxi;
}

/*                                        EFFICIENT APPROACH                                   */
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:-O(1)
int midDiff(int arr[], int n)
{
    int maxi = arr[1] - arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    return maxi;
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = 4;

    cout << midDiff(arr, n);

    return 0;
}
