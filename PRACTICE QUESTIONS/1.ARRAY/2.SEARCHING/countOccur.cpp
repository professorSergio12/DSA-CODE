/*                             Count number of occurrences (or frequency) in a sorted array

Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)

Examples:

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
  Output: 4 // x (or 2) occurs 4 times in arr[]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
  Output: 1 */

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(Log n + count) where count is number of occurrences.
// Space Complexity: O(logn), due to recursive stack space
int firstOcc(int arr[], int n, int element)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] < element)
            low = mid + 1;

        else if (arr[mid] > element)
            high = mid - 1;

        else
        {
            if (mid == 0 || arr[i - 1] != arr[i])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int LastOcc(int arr[], int n, int element)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] < element)
            low = mid + 1;

        else if (arr[mid] > element)
            high = mid - 1;

        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int countOccurrences(int arr[], int n, int element)
{
    int first = firstOcc(arr, n, element);

    if (first == -1)
        return 0;

    else
        return (LastOcc(arr, n, element) - first + 1);
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << countOccurrences(arr, n, x);
    return 0;
}