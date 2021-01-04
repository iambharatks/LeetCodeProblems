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
    TreeNode *minValueNode(TreeNode *root)
    {
        TreeNode *current = root;
        while (current && current->left)
            current = current->left;
        return current;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                TreeNode *tmp = root->right;
                // free(root);
                return tmp;
            }
            if (root->right == NULL)
            {
                TreeNode *tmp = root->left;
                // free(root);
                return tmp;
            }
            TreeNode *tmp = minValueNode(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
        return root;
    }
};