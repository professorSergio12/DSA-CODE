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

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:- O(h)

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

bool isBalancedTree(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh) <= 1 && isBalancedTree(root->left) && isBalancedTree(root->right));
}


// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(h)
int IsBalancedTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = IsBalancedTree(root->left);
    if (lh == -1)
        return -1;

    int rh = IsBalancedTree(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main()
{
    // struct node *root = createnode(20);
    // root->left = createnode(8);
    // root->right = createnode(12);
    // root->right->left = createnode(3);
    // root->right->right = createnode(9);

    struct node *root = createnode(20);
    root->left = createnode(8);
    root->left->right = createnode(12);

    bool ans = isBalancedTree(root);
    if (ans == true)
    {
        cout << "The tree is balanced" << endl;
    }
    else
    {
        cout << "The tree is not balanced" << endl;
    }
}