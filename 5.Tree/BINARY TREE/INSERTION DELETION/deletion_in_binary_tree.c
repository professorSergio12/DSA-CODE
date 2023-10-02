#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *inorderPrecedesur(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//  Time Complexity: O(h)
// Space Complexity: O(h)
struct node *delete_node(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            iPre = inorderPrecedesur(root);
            root->data = iPre->data;
            root->left = delete_node(root->left, iPre->data);
        }
    }
    return root;
}

int main()
{
    struct node *p = create(5);
    struct node *p1 = create(3);
    struct node *p2 = create(6);
    struct node *p3 = create(1);
    struct node *p4 = create(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    delete_node(p, 3);
    inorder(p);
}
