/*
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Time Complexity: O(n^2), traverse the whole tree
// Space Complexity: O(1), No Extra Space is used

void printPrevGreater(int arr[], int n)
{
    cout << "-1" << " ";
    for (int i = 1; i < n; i++)
    {
        int diff = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
            {
                diff = min(diff, arr[j] - arr[i]);
            }
        }
        if (diff == INT_MAX)
        {
            cout << "-1" << " ";
        }
        else
        {
            cout << arr[i] + diff << " ";
        }
    }
}

int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printPrevGreater(arr, n);
    return 0;
}