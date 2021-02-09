#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
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
    TreeNode *convertBST(TreeNode *root)
    {
        stack<TreeNode *> ps;
        TreeNode *node = root;
        int sum = 0;
        while (!ps.empty() || root != NULL)
        {
            if (root != NULL)
            {
                ps.push(root);
                root = root->right;
            }
            else
            {
                root = ps.top();
                ps.pop();
                sum += root->val;
                root->val = sum;
                root = root->left;
            }
        }
        return node;
    }
};