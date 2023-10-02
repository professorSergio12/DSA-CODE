/*                                             K distance from root
Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6
     \
      8
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void _Kdistance(struct Node *root, vector<int> &ans, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        ans.push_back(root->data);
        return;
    }
    else
    {
        _Kdistance(root->left, ans, k - 1);
        _Kdistance(root->right, ans, k - 1);
    }
}
// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> ans;
    _Kdistance(root, ans, k);
    return ans;
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    vector<int> ans = Kdistance(root, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
