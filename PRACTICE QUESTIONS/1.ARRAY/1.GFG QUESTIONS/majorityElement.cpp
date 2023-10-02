/*                        Find maximum count of and element and then check if it is greater than size/2

Example:
Input:-
arr[] = {8, 9, 8, 7, 8, 7, 5, 8, 8};

Output:-


*/

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY:- O(N^2)
// SPACE COMPLEXITY:-O(1)
int majorityElmt(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2)
            return i;
    }
    return -1;
}

// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:-O(1)
int MajorityElmnt(int arr[], int n)
{
    
    
}

int maxCircularSum(int arr[], int n)
{
    int max_normal = maxSubarraySum(arr, n);

    if (max_normal < 0)
        return max_normal;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = sum + maxSubarraySum(arr, n);
    return max(max_normal, max_circular);
}

int main()
{
}