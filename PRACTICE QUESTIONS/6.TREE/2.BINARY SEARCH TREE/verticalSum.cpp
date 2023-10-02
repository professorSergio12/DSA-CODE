/*                                          Vertical Sum in a given Binary Tree

Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7
So expected output is 4, 2, 12, 3 and 7
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

void iSsum(struct node *root, int hd, map<int, int> &mp)
{
    if (root == NULL)
        return;

    iSsum(root->left, hd - 1, mp);
    mp[hd] += root->data;
    iSsum(root->right, hd + 1, mp);
}

// Time Complexity: O(n log hd) where hd is a possible number of horizantal distance.
// Auxiliary Space: O(n), As we are using extra space for the map and recursion call stack.
void verticalSum(struct node *root)
{
    map<int, int> mp;
    iSsum(root, 0, mp);
    for (auto sum : mp)
    {
        cout << sum.second << " ";
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
    struct node *root = createNode(10);
    root->left = createNode(2);
    root->right = createNode(10);
    root->left->left = createNode(20);
    root->left->right = createNode(1);
    root->right->right = createNode(-25);
    root->right->right->left = createNode(3);
    root->right->right->right = createNode(4);

    verticalSum(root);
}
