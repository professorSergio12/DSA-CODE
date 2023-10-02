
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

void printkdistanceNodeDown(struct node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, print it
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printkdistanceNodeDown(root->left, k - 1);
    printkdistanceNodeDown(root->right, k - 1);
}

int printkdistanceNode(struct node *root, struct node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    // If target is same as root.  Use the downward function to print all nodes at distance k in subtree rooted with target or root
    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);
    if (dl != -1) // Check if target node was found in left subtree
    {
        if (dl + 1 == k)
        {
            cout << root->data << " " << endl;
        }
        else
        {
            printkdistanceNodeDown(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " " << endl;
        }
        else
        {
            printkdistanceNodeDown(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}
int main()
{
    /*   20
        /  \
        8   22
       / \
       4  12
          / \
         10 14

    */
    struct node *root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(4);
    root->left->right = createNode(12);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);
    struct node *target = root->left->right;
    printkdistanceNode(root, target, 2);
}