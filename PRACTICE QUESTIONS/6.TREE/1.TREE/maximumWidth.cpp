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
int maxWidth(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<struct node *> q;
    q.push(root);
    int ans = 0;

    while (!q.empty())
    {
        int n = q.size();
        ans = max(ans, n);
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
        }
    }
    return ans;
}

int main()
{
    struct node *root = createnode(20);
    root->left = createnode(8);
    root->right = createnode(12);
    root->right->left = createnode(3);
    root->right->right = createnode(9);

    int ans = maxWidth(root);
    cout << "The maximum width is " << ans;
}