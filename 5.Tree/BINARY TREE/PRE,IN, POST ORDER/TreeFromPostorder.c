/*                               Construct a binary tree from inorder and postorder traversals                */

#include <stdio.h>
#include <stdlib.h>

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

/* Function to find index of value in arr[start...end].The function assumes that value is postsent in in[] */
int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct node *buildNode(int inorder[], int postorder[], int start, int end)
{
    static int idx = 4;

    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;

    struct node *n = createNode(curr);
    if (start == end)
    {
        return n;
    }

    int pos = search(inorder, start, end, curr);

    // recursively construct the right subtree
    n->right = buildNode(inorder, postorder, pos + 1, end);

    // recursively construct the left subtree
    n->left = buildNode(inorder, postorder, start, pos - 1);
    return n;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    struct node *root = buildNode(inorder, postorder, 0, 4);
    printf("Inorder traversal of the constructed tree is \n");
    inOrder(root);
}