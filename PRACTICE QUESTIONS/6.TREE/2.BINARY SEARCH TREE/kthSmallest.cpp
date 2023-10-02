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

// Time Complexity: O(n), traverse the whole tree
// Space Complexity: O(1), No Extra Space is used
int cnt = 0;
int ans = 0;
void smallest(struct node *root, int k)
{
    if (root == NULL)
        return;

    smallest(root->left, k);
    cnt++;
    if (cnt == k)
    {
        ans = root->data;
    }
    smallest(root->right, k);
}

int kthSmallest(struct node *root, int k)
{
    smallest(root, k);
    return ans;
}

// Main function
int main()
{
    struct node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left->left = createNode(1);

    // root->right->right = createNode(7);

    int ans = kthSmallest(root, 3);
    cout << ans;
    return 0;
}