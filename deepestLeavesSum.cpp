#include <bits/stdc++.h>

using namespace std;

//   Deepest Leaves Sum

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

// BFS Solution
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        int curLevel = 0, maxLevel = 0, sum = 0;
        bool isLeaf;
        queue<TreeNode *> q;
        if (!root)
            return 0;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            root = q.front();
            isLeaf = 1;
            q.pop();
            if (root == NULL)
            {
                curLevel++;
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            if (root->left)
            {
                isLeaf = 0;
                q.push(root->left);
            }
            if (root->right)
            {
                isLeaf = 0;
                q.push(root->right);
            }
            if (isLeaf)
            {
                if (maxLevel < curLevel)
                {
                    maxLevel = curLevel;
                    sum = root->val;
                }
                else if (maxLevel == curLevel)
                    sum += root->val;
            }
        }
        return sum;
    }
};

//Better
// DFS Solution
class Solution
{
public:
    void dfs(TreeNode *root, int &sum, int curLevel, int &maxLevel)
    {
        if (!root)
            return;
        if (curLevel == maxLevel)
            sum += root->val;
        if (curLevel > maxLevel)
        {
            sum = root->val;
            maxLevel = curLevel;
        }
        dfs(root->left, sum, curLevel + 1, maxLevel);
        dfs(root->right, sum, curLevel + 1, maxLevel);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int sum = 0, maxLevel = 0;
        dfs(root, sum, 0, maxLevel);
        return sum;
    }
};