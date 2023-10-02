/*                             Top view of binary tree
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

vector<int> findTopView(struct node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp; // level position, node val

    queue<pair<struct node *, int>> q; // Node , Level
    
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        struct node *curr = it.first;
        int hd = it.second;

        if (mp.find(hd) == mp.end())
            mp[hd] = curr->data;

        if (curr->left != NULL)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, hd + 1});
        }
    }

    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
int main()
{
}