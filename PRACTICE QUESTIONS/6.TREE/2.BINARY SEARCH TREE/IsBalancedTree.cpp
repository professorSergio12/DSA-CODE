

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

bool IsBalanced(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (IsBalanced(root->left) == false)
    {
        return false;
    }
    if (IsBalanced(root->right) == false)
    {
        return false;
    }

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    // abs() function returns the absolute value of an integer number
    if (abs(lh - rh) <= 1) // To check  current(root) node is balanced or not
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*                      Time complexity of this function is O(n)                          */
bool Isbalanced(struct node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (Isbalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (Isbalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1; // for calcualting the current(root) node height
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
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

    if (IsBalanced(root)) // for time complexity o(n^2)
    {
        cout << "The tree is balanced" << endl;
    }
    else
    {
        cout << "The tree is not balanced" << endl;
    }

    int height = 0;
    if (Isbalanced(root, &height) == true) // for time complexity o(n)
    {
        cout << "The tree is balanced" << endl;
    }
    else
    {
        cout << "The tree is not balanced" << endl;
    }
}