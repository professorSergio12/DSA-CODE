

#include <bits/stdc++.h>
using namespace std;
/*                                                RECURSIVE APPROACH                                           */
int firstOcc(vector<int> &arr, int low, int high, int element)
{
    int n = arr.size(); // size

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] < element)
        firstOcc(arr, mid + 1, high, element);

    else if (arr[mid] > element)
        firstOcc(arr, low, mid - 1, element);

    else
    {
        if (mid == 0 || arr[i - 1] != arr[i])
        {
            return mid;
        }
        else
        {
            firstOcc(arr, low, mid - 1, element);
        }
    }
}

/*                                                ITERATIVE APPROACH                                           */

int firstOcc(vector<int> &arr, int element)
{
    int n = arr.size(); // size
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

int main()
{
}