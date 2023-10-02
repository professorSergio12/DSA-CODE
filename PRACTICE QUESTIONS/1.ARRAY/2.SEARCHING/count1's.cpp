/*                          Count 1's in a sorted binary array

Given a binary array arr[] of size N, which is sorted in non-increasing order, count the number of 1's in it.

Examples:

Input: arr[] = {1, 1, 0, 0, 0, 0, 0}
Output: 2

Input: arr[] = {1, 1, 1, 1, 1, 1, 1}
Output: 7

Input: arr[] = {0, 0, 0, 0, 0, 0, 0}
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

int countOnes(int arr[], int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == 0)
            low = mid + 1;

        else
        {
            if (mid == 0 || arr[mid - 1] == 0)
            {
                return (n - mid);
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    bool arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of 1's in given array is" << countOnes(arr, 0, n - 1);
    return 0;
}