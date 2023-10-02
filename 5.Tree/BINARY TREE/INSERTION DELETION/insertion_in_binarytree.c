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
/*                                     RECURSIVE                                        */
// Time Complexity: O(h)
// Space Complexity: O(h)
struct node *Insertion(struct node *root, int key)
{
    if (root == NULL)
    {
        return key;
    }

    if (root->data < key)
    {
        root->right = Insertion(root->right, key);
    }

    else if (root->data > key)
    {
        root->left = Insertion(root->left, key);
    }

    return root;
}

/*                                     ITERATIVE                                        */
// Time Complexity: O(h)
// Space Complexity: O(1)
void insertion(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = create(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
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

int main()
{
    struct node *p = create(5);
    struct node *p1 = create(3);
    struct node *p2 = create(6);
    struct node *p3 = create(1);
    struct node *p4 = create(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insertion(p, 16);
    // printf("%d", p->right->right->data);
    inorder(p);
    return 0;
}