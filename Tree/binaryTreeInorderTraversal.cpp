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
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> res;
        while (true)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            if (s.empty())
                break;
            root = s.top();
            res.push_back(root->val);
            s.pop();
            root = root->right;
        }
        return res;
    }
};