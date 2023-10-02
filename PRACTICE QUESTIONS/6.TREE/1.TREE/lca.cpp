/*                                        Lowest Common Ancestor in a Binary Tree
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(n)

bool findPath(struct node *root, vector<int> path, int n)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == n)
        return true;

    if (findPath(root->left, path, n) || findPath(root->right, path, n))
        return true;

    path.pop_back();
    return false;
}

int findLCA(struct node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return path1[i - 1];
}

// Efficient Approach, but it assume that one of the value (n1, n2) is present
struct node *FindLCA(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct node *lca1 = FindLCA(root->left, n1, n2);
    struct node *lca2 = FindLCA(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;

    if (lca1 != NULL)
        return lca1;

    else
        return lca2;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << FindLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << FindLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << FindLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << FindLCA(root, 2, 4)->data;
    return 0;
}