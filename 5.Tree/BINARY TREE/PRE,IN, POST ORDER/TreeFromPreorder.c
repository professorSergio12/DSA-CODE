/*              Construct Tree from given Inorder and Preorder traversals   */
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

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

struct node *buildNode(int inorder[], int preorder[], int start, int end)
{
    static int preIndex = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[preIndex];
    preIndex++;
    struct node *n = createNode(curr);

    if (start == end)
    {
        return n;
    }

    int pos = search(inorder, start, end, curr);
    n->left = buildNode(inorder, preorder, start, pos - 1);
    n->right = buildNode(inorder, preorder, pos + 1, end);
    return n;
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    struct node *root = buildNode(inorder, preorder, 0, 4);
    printf("Inorder traversal of the constructed tree is \n");
    inOrder(root);
}
