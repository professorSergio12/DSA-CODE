
#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n)
{
    int res = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return res;
}
// NAIVE APPROACH
int secondLargest(int arr[], int n)
{
    int largest = largestElement(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest])
        {
            if (arr[res] == -1)
                res = i;

            else if (arr[i] >= arr[res])
                res = i;
        }
    }
    return res;
}

// EFFICIENT APPROACH
int SecondLargest(int arr[], int n)
{
    int largest = 0;
    int res = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (arr[i] > arr[res] || res == -1)
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[] = {12, 4, 3, 5, 6};
    int n = 5;

    cout << "The second largest element is " << SecondLargest(arr, n);
}