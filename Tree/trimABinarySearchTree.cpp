#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
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
    TreeNode *trim(TreeNode *root, int target, bool left)
    {
        if (!root)
            return root;
        if (left)
        {
            if (root->val < target)
            {
                root = trim(root->right, target, left);
            }
            else
            {
                root->left = trim(root->left, target, left);
            }
        }
        else
        {
            if (root->val > target)
            {
                root = trim(root->left, target, left);
            }
            else
            {
                root->right = trim(root->right, target, left);
            }
        }
        return root;
    }
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        root = trim(root, low, true);
        root = trim(root, high, false);
        return root;
    }
};