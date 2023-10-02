/*                               Find position of an element in a sorted array of infinite numbers

*/

#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH
int findPos(int arr[], int x)
{
    int i = 0;
    while (true)
    {
        if (arr[i] == x)
            return i;

        if (arr[i] > x)
            return -1;

        i++;
    }
}

// EFFICIENT APPROACH

// TIME COMPLEXITY: O(pos)
int FindPos(int arr[], int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;

    while (arr[i] < x)
    {
        i = i * 2;
    }

    if (arr[i] == x)
        return i;

    return binary_search(arr, x, i / 2 + 1. i - 1);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}