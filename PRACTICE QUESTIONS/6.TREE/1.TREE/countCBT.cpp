/*                                        Count the number of nodes in complete binary tree
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(n)

int Count(struct node *root)
{ // This function can be used for any tree
    if (root == NULL)
    {
        return 0;
    }

    return 1 + Count(root->left) + Count(root->right);
}

// TIME COMPLEXITY:- O(log(n) * log(n))
//  SPACE COMPLEXITY:- O(h)
int count(struct node *root)
{

    // This function is used for complete binary tree
    int lh = 0;
    int rh = 0;
    if (root == NULL)
        return 0;

    struct node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }

    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->left;
    }

    if (lh == rh)
    {
        return pow(2, lh) - 1; // check if the left sub tree or right sub tree have equal height or not
    }
    // if the heights are not equal then we find the heights by recursion
    return 1 + count(root->left) + count(root->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}