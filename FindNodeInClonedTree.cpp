#include <bits/stdc++.h>

using namespace std;

//  Find a Corresponding Node of a Binary Tree in a Clone of That Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *found;
        queue<TreeNode *> q1, q2;
        TreeNode *root1 = original, *root2 = cloned;
        q1.push(root1);
        q2.push(root2);
        while (!q1.empty())
        {
            root1 = q1.front();
            root2 = q2.front();
            q1.pop();
            q2.pop();
            if (root1 == target)
                return root2;
            if (root1->left)
                q1.push(root1->left), q2.push(root2->left);
            if (root1->right)
                q2.push(root2->right), q1.push(root1->right);
        }
        return NULL;
    }
};