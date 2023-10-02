#include <bits/stdc++.h>
using namespace std;

/*                                        NAIVE APPROACH                                   */
// TIME COMPLEXITY:- O(N^2)
// SPACE COMPLEXITY:-O(1)
int consecutive1s(bool arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 1)
                curr++;

            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

/*                                        EFFICIENT APPROACH                                   */
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:-O(1)
int consecutive1s(bool arr[], int n)
{
    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            curr = 0;
        }
        else
        {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 1, 1};
    int n = 7;

    cout << consecutive1s(arr, n);

    return 0;
}
