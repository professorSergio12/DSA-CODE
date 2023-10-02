/*                      Construct Tree from given Inorder and Preorder traversals
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

// TIME COMPLEXITY:- O(n^2)
// SPACE COMPLEXITY:- O(h)
struct node *buildTree(char in[], char pre[], int n, int m)
{
    static int preIndex = 0;
    if (n > m)
        return NULL;

    struct node *root = createnode(pre[preIndex++]);

    int inIndex;

    for (int i = 0; i <= m; i++)
    {
        if (in[i] == root->data)
        {
            inIndex = i;
            break;
        }
    }
    root->left = buildTree(in, pre, n, inIndex - 1);
    root->right = buildTree(in, pre, inIndex + 1, m);
    return root;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    struct node *root = buildTree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree is \n";
    inOrder(root);
}