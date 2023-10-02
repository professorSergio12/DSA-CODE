/*                                        Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void levelorder(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> v;
        bool leftToRight = true;

        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();

            if (curr) // if not null
            {
                v.push_back(curr->val);
                if (leftToRight)
                {
                    if (curr->left)
                    {
                        s2.push(curr->left);
                    }
                    if (curr->right)
                    {
                        s2.push(curr->right);
                    }
                }
                else
                {
                    if (curr->right)
                    {
                        s2.push(curr->right);
                    }
                    if (curr->left)
                    {
                        s2.push(curr->left);
                    }
                }
            }
            if (s1.empty())
            {
                ans.push_back(v);
                leftToRight = !leftToRight;
                swap(s1, s2);
                v.clear();
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        levelorder(root, ans);
        return ans;
    }
};