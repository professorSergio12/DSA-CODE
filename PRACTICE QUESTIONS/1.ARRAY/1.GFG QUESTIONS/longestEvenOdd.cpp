
#include <bits/stdc++.h>
using namespace std;

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/*                                         NAIVE APPROACH                               */

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:-O(1)
int EvenOdd(int arr[], int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
            {
                curr++;
            }
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

/*                                               EFFICIENT APPROACH                                 */

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
int Evenodd(int arr[], int n)
{
    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    return res;
}

int main()
{
    int arr[] = {0, 4, 6, 8, 10, 12, 14};
    int n = 7;

    int ans = Evenodd(arr, n);
    cout << ans;
}