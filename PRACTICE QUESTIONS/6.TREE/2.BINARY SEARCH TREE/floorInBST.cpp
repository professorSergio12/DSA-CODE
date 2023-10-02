/*                                     Floor in Binary Search Tree (BST)
Floor Value Node: Node with the greatest data lesser than or equal to the key value.
Ceil(X) is a number that is either equal to X or is immediately greater than X.
*/

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

// Time Complexity: O(H), where H is the height of the tree
// Auxiliary Space: O(1)
struct node *Floor(struct node *root, int val)
{
    struct node *res = NULL;
    if (root == NULL)
        return NULL;
    // thoda se chota element chahiye hote hia like if the val  = 57 ans there are node  = (45, 67, 56)so we return 56
    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }

        else if (root->data > val)
        {
            root = root->left;
        }

        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

int main()
{
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(6);

    struct node *ans = Floor(root, 5);
    cout << ans << " ";
}