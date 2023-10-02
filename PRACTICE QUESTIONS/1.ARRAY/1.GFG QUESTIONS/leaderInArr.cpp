/*Write a program to print all the LEADERS in the array. An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader.

For example:

Input: arr[] = {16, 17, 4, 3, 5, 2},
Output: 17, 5, 2
*/
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

/*                                         NAIVE APPROACH                               */

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:-O(1)
void Leader(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            printf(arr[i]);
        }
    }
}

/*                                               EFFICIENT APPROACH                                 */

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:-O(1)
vector<int> leaders(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= ans[ans.size() - 1])
        {
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int arr[] = {12, 4, 0, 0, 6, 0, 3, 0, 0};
    int n = 9;

    Leader(arr, n);
    traversal(arr, n);
}