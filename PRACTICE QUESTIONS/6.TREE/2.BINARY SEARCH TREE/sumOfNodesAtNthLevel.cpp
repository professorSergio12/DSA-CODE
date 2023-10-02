/*                                       Sum of all nodes at Kth level in a Binary Tree  

Given a binary tree with N nodes and an integer K, the task is to find the sum of all the nodes present at the Kth level.                                                                                                                 */

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

int sumOfNodesAtNthLevel(struct node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        struct node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main()
{
    struct node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    int level = 2;
    int result = sumOfNodesAtNthLevel(root, level);
    cout << result;
}