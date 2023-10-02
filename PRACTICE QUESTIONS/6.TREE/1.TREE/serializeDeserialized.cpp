/*         Serialize and Deserialize a Binary Tree
Serialization is to store the tree in a file so that it can be later restored. The structure of the tree must be maintained. Deserialization is reading the tree back from a file
 */
#include <bits/stdc++.h>
using namespace std;

#define Empty -1
int index = 0;
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

void serialize(struct node *root, vector<int> arr)
{
    if (root == NULL)
    {
        arr.push_back(Empty);
        return;
    }

    arr.push_back(root->data);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

struct node *deserialized(vector<int> arr)
{
    if (index == arr.size())
    {
        return NULL;
    }

    int val = arr[index];
    index++;

    if (val == Empty)
        return NULL;
    struct node *root = newNode(val);

    root->left = deserialized(arr);
    root->right = deserialized(arr);
    return root;
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

    return 0;
}