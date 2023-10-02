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

vector<vector<int>> levelOrder(struct node *root)
{
    vector<vector<int>> ans;
    queue<struct node *> q;

    if (root == NULL)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            struct node *curr = q.front();
            q.pop();

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }

            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(6);

    vector<vector<int>>ans  =  levelOrder(root);
}