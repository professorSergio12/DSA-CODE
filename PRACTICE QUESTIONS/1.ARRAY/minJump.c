/*                                         Minimum no. of Jumps to reach end of an array      */
#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }

    int step = arr[0];
    int maxR = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;

        maxR = max(maxR, i + arr[i]);
        step--;
        if (step == 0)
        {
            jumps++;
            if (i >= maxR)
                return -1;
            step = maxR - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}
