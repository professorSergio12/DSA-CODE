//                Print Right View of a Binary Tree

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

void rightView(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // n is level

        for (int i = 0; i < n; i++)
        {
            struct node *node = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << node->data << " "; // here we are printing the last node of a level
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
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

    rightView(root);
}