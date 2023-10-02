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

/*                      Time complexity of this function is O(n^2)                          */
int HeightOfTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    return max(lh, rh) + 1;
}

int diameterOFTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    int currentDiameter = lh + rh + 1;
    int ldiameter = diameterOFTree(root->left);
    int rdiameter = diameterOFTree(root->right);

    return max(currentDiameter, max(ldiameter, rdiameter));
}

/*                      Time complexity of this function is O(n)                          */

int diameterOfTree(struct node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldiameter = diameterOfTree(root->left, &lh);
    int rdiameter = diameterOfTree(root->right, &rh);

    int currentDiameter = lh + rh + 1;

    *height = max(lh, rh) + 1;
    return max(currentDiameter, max(ldiameter, rdiameter));
}

int res = 0;
int diameter(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = diameter(root->left);
    int rh = diameter(root->right);

    res = max(res, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int main()
{
    /*    1
        /   \
        2    3
       /  \ / \
       4  5 6  7

    */
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("The max diameter of the tree is %d ", diameterOFTree(root)); // Time complexity is O(n^2)

    int height = 0;
    printf("The max diameter of the tree is %d\n", diameterOfTree(root, &height)); // Time complexity is O(n)
}