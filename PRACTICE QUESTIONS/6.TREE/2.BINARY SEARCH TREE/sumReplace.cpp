/*                               Convert a binary tree to its sum tree                                */


/*Given a binary tree of integers, you are supposed to modify the given binary tree to a sum tree where each node value is replaced by the sum of the values of both left and right subtrees in the given tree. The value of leaf nodes is changed to zero.*/

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

void sumReplacement(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
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
    root->right->right = createNode(7);

    preorder(root);
    cout << "\n";
    sumReplacement(root);
    preorder(root);
}