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
    int sum(TreeNode *root, int &res)
    {
        if (!root)
            return 0;
        int lSum = sum(root->left, res);
        int rSum = sum(root->right, res);
        res += abs(lSum - rSum);
        return lSum + rSum + root->val;
    }
    int findTilt(TreeNode *root)
    {
        int res = 0;
        sum(root, res);
        return res;
    }
};