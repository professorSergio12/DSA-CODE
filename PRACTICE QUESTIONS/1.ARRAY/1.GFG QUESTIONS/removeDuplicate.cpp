
#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(n)
int removeDup(int arr[], int n)
{
    int temp[n];
    temp[0] = arr[0];
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        arr[i] = temp[i];
    }
    return res;
}

// EFFICIENT APPROACH

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
int RemoveDup(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {12, 4, 3, 5, 6};
    int n = 5;

    cout << "The second largest element is " << RemoveDup(arr, n);
}