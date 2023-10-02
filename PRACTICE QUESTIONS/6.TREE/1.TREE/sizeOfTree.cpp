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
int sizeOfTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
    }
}

int main()
{
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(6);

    int size = sizeOfTree(root);
    cout << "The size of a tree is " << size;
}