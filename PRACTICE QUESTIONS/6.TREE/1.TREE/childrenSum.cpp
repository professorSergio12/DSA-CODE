#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(h)
bool childrenSum(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }

    if (root->right != NULL)
    {
        sum += root->right->data;
    }

    return (root->data == sum && childrenSum(root->left) && childrenSum(root->right));
}

int main()
{
    // struct node *root = createnode(1);
    // root->left = createnode(2);
    // root->right = createnode(3);
    // root->left->left = createnode(4);
    // root->left->right = createnode(5);
    // root->right->right = createnode(6);

    struct node *root = createnode(20);
    root->left = createnode(8);
    root->right = createnode(12);
    root->right->left = createnode(3);
    root->right->right = createnode(9);

    bool ans = childrenSum(root);
    if (ans == true)
    {
        cout << "The children sum exist" << endl;
    }
    else
    {
        cout << "The children sum not exist" << endl;
    }
}