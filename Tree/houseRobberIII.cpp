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
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        pair<int, int> cur = {0, 0};
        cur.first = l.second + r.second + root->val;
        cur.second = max(l.second, l.first) + max(r.second, r.first);
        return cur;
    }
    int rob(TreeNode *root)
    {
        int exc = 0, inc = 0;
        tie(inc, exc) = dfs(root);
        return max(inc, exc);
    }
};