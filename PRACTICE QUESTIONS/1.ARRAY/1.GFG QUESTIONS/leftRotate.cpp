
#include <bits/stdc++.h>
using namespace std;

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/*                                       Left rotate of an array by one                                */

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
void LeftRotate(int arr[], int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

/*                                       Left rotate an array by d                     */


// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
void rotate(vector<int> &nums, int k)
{
    int t = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + t); // 1st k elements
    reverse(nums.begin() + t, nums.end());   // last k elements
}

int main()
{
    int arr[] = {12, 4, 0, 0, 6, 0, 3, 0, 0};
    int n = 9;

    LeftRotate(arr, n);
    traversal(arr, n);
}