

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:-O(1)
int midDiff(int arr[], int n)
{
    int i = 1;
    int freq = 1;

    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        cout << arr[i - 1] << " " << freq;
        i++;
        freq = 1;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2])
    {
        cout << arr[n - 1] << " " << 1;
    }
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = 4;

    cout << midDiff(arr, n);

    return 0;
}
