/*                                          Find a pair with given sum in BST

Given a BST and a sum, find if there is a pair with the given sum.
Input: sum = 28, given BST

Output: Pair is found (16, 12)
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

bool findPairSum(struct node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (findPairSum(root->left, val, s) == true)
        return true;

    if (s.find(sum - root->data) != s.end())
    {
        return true;
    }
    else
    {
        s.insert(root->data);
    }

    return findPairSum(root->right, val, s);
}

void findPair(Node *root, int sum)
{
    unordered_set<int> set;
    if (!findPairSum(root, sum, set))
        cout << "Pairs do not exit" << endl;
}

int main()
{
    /*    1
        /   \
        2    3
       /  \ / \
       4  5 6  7

    */
    struct node *root = createNode(10);
    root->left = createNode(2);
    root->right = createNode(10);
    root->left->left = createNode(20);
    root->left->right = createNode(1);
    root->right->right = createNode(-25);
    root->right->right->left = createNode(3);
    root->right->right->right = createNode(4);

    int sum = 28;
    findPair(root, sum);
}