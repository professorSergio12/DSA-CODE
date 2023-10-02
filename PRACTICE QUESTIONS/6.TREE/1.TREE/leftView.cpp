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
// SPACE COMPLEXITY:- O(h) where h is hight of binary tree
int maxLevel = 0;
void leftView(struct node *root, int level)
{

    if (root == NULL)
    {
        return;
    }
    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}

void printLeftView(struct node *root)
{
    leftView(root, 1);
}

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(w) where w is width

void PrintLeftView(struct node *root)
{
    queue<struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            struct node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
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

    printLeftView(root);
    // PrintLeftView(root);
}