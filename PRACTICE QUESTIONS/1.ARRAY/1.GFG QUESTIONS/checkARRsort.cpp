
#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:-O(1)
int IsSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                return false;
        }
    }
    return true;
}

// EFFICIENT APPROACH

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
bool isSorted(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[res])
        {
            return false;
        }
        res++;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 7, 4, 5};
    int n = 5;

    if (IsSorted(arr, n) == true)
    {
        cout << "The array is sorted ";
    }
    else
    {
        cout << "Not sorted";
    }
}