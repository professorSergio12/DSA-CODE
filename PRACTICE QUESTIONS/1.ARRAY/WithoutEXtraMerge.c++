/*                           Merge 2 sorted arrays without using Extra space                         */

#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int N, int arr2[], int M)
{
    int i = 0;
    int j = 0;
    int k = N - 1;
    while (i <= k && j < M)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j], arr1[k]);
            j++;
            k--;
        }
    }
    sort(arr1, arr1 + N);
    sort(arr2, arr2 + M);
}

int main()
{
    int N = 2, M = 3;
    int arr1[] = {10, 12};
    int arr2[] = {5, 18, 20};
    merge(arr1, N, arr2, M);
    cout << "After Merging First Array: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr1[i] << " ";
    }
    printf("\n");

    cout << "After merging Second Array: " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << arr2[i] << " ";
    }
}