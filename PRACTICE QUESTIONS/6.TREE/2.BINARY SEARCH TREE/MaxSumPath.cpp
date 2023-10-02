/*Maximum Path sum | From leaf node to leaf node*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int maxPathSum(struct node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = maxPathSum(root->left, res);
    int r = maxPathSum(root->right, res);

    int temp = max(l, r) + root->data;
    if (root->left == NULL && root->right == NULL)
    {
        max(temp, root->data);
    }

    int ans = max(temp, l + r + root->data);
    res = max(res, ans);
    return temp;
}

int findMaxSum(struct node *root)
{
    // Initialize result
    int res = INT_MIN;

    // Compute and return result
    maxPathSum(root, res);
    return res;
}

int main()
{
    /*    1
        /   \
        2    3
       /  \ / \
       4  5 6  7

    */
    struct node *root = createNode(10);
    root->left = createNode(2);
    root->right = createNode(10);
    root->left->left = createNode(20);
    root->left->right = createNode(1);
    root->right->right = createNode(-25);
    root->right->right->left = createNode(3);
    root->right->right->right = createNode(4);

    cout << "Max path sum is " << findMaxSum(root);
}