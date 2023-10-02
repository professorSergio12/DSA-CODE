/*Given an array of integer and a number k, find the maximum sum of k consecutive elements

EXAMPLE:

input:- arr[] = {1, 8, 30, -5, 20, 7}
k = 3;

output: 45

*/

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY:-O((N- K) * K) ~  O(N^2)
// SPACE COMPLEXITY:-O(1)
int maxSum(int arr[], int n, int k)
{
    int max_sum = INT_MIN;

    for (int i = 0; i + k - 1 < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += arr[i + 1]
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

// int Sum(int arr[], int n, int k)
// {

//     int maxi = INT_MIN;
//     for(int i = 0; i < n - 1; i++)
//     {
//         int sum = 0;
//         for(int j = 0; j < k; j++)
//         {
//             sum += arr[i + j];
//         }
//         // cout<<sum<<endl;
//         maxi = max(maxi, sum);
//     }
//     return maxi;
// }

// TIME COMPLEXITY:-O(N)
// SPACE COMPLEXITY:-O(1)

int MaxSum(int arr[], int n, int k)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
        curr_sum += arr[i];
    }

    int max_sum = curr_sum;
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

/*Given an unsorted array of non-negative integer. Find if there is a subarray with given sum

EXAMPLE:

input:- arr[] = {1, 4, 20, 3, 10, 5}
sum = 33;

output: yes

*/

// TIME COMPLEXITY:-O(N^2)
// SPACE COMPLEXITY:-O(1)
int givenSum(int arr[], int n, int givensum)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == givenSum)
                return true;
        }
    }
    return false;
}

// TIME COMPLEXITY:-O(N)
// SPACE COMPLEXITY:-O(1)

int MaxSum(int arr[], int n, int sum)
{
    int curr_sum = arr[0];
    int start = 0;
    for (int i = 1; i < n; i++)
    {
        while (curr_sum > sum && start < i - 1)
        {
            curr_sum -= arr[start];
            start++;
        }
        if (curr_sum == sum)
        {
            return true;
        }
        if (i < n)
            curr_sum += arr[i];
    }
    return (curr_sum == sum);
}
