/*                                  Flatten a binary tree into linked list

EXAMPLE:

Input :
          1
        /   \
       2     5
      / \     \
     3   4     6

Output :
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
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

// Time Complexity: O(n), traverse the whole tree
// Space Complexity: O(1), No Extra Space is used
void flatten(struct node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // if root->left exists then we have to make it root->right
    if (root->left != NULL)
    {
        flatten(root->left);

        struct node *temp = root->right; // store the node root->right
        root->right = root->left;
        root->left = NULL;

        struct node *t = root->right; // find the position to insert the stored value
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp; // insert the stored value
    }

    flatten(root->right);
}

void inorder(struct node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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

    flatten(root);

    cout << "The Inorder traversal after flattening binary tree " << endl;
    inorder(root);
    return 0;
}