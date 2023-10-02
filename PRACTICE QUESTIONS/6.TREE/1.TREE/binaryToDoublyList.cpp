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

// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(h)

struct node *convertTodoublylist(struct node *root)
{
    if (root == NULL)
    {
        return root;
    }
    struct node *prev = NULL;
    struct node *head = convertTodoublylist(root->left);
    if (prev = NULL)
        head = root;

    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertTodoublylist(root->right);
    return head;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

int main()
{
    // struct node *root = createnode(1);
    // root->left = createnode(2);
    // root->right = createnode(3);
    // root->left->left = createnode(4);
    // root->left->right = createnode(5);
    // root->right->right = createnode(6);

    struct node *root = createnode(20);
    root->left = createnode(8);
    root->right = createnode(12);
    root->right->left = createnode(3);
    root->right->right = createnode(9);

    struct node *head = convertTodoublylist(root);
    printList(head);
}