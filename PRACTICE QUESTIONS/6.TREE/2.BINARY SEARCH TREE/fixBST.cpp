/*                Two nodes of a BST are swapped, correct the BST

Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

EXAMPLE:
Input: x = 20, y = 8
         10
        /  \
      5    8
    / \
  2   20
Output:
         10
        /  \
     5    20
   / \
 2   8

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

// Time Complexity: O(N)
// Auxiliary Space: O(N) for recursive call stack

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void correctBST(struct node *root)
{
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *prev = NULL;

    if (root == NULL)
        return;

    correctBST(root->left);

    if (prev != NULL && root->data <= prev->data)
    {
        if (first == NULL)
            first = prev;

        second = root;
    }
    prev = root;
    correctBST(root->right);

    swap(&(first->data), &(last->data));
}

void inorder(struct node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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

    correctBST(root);

    cout << "The Inorder traversal after swapped of  binary tree " << endl;
    inorder(root);
    return 0;
}