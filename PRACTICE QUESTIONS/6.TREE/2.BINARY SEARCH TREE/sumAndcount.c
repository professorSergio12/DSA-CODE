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

int count(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

int sum(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    printf("The number of nodes in a binary are: %d\n", count(root));
    printf("The sum of nodes are: %d ", sum(root));
}
