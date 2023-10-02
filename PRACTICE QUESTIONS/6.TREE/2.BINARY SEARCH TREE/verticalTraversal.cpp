/*                              Print a Binary Tree in Vertical Order

Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9

The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
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

void verticalTraversal(struct node *root)
{
    map<int, vector<int>> mp;
    queue<pair<struct node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();

        struct node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->data);
        q.pop();

        if (curr->left != NULL)
        {
            q.push(curr->left, hd - 1);
        }

        if (curr->right != NULL)
        {
            q.push(curr->right, hd + 1);
        }
    }
}

int main()
{
}