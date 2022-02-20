#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SparseTable
{
    int **st;
    int *log_2;
    int **ind;

public:
    SparseTable(vector<int> nodeDepth)
    {
        int n = nodeDepth.size();

        log_2 = new int[n + 1]{0};
        for (int i = 2; i <= n; i++)
            log_2[i] = log_2[i / 2] + 1;

        int k = log_2[n] + 1;
        st = new int *[k];
        ind = new int *[k];
        for (int i = 0; i < k; i++)
        {
            st[i] = new int[n];
            ind[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            st[0][i] = nodeDepth[i];
            ind[0][i] = i;
        }

        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                if (st[j - 1][i] <= st[j - 1][i + (1 << (j - 1))])
                    ind[j][i] = ind[j - 1][i];
                else
                    ind[j][i] = ind[j - 1][i + (1 << (j - 1))];
            }
        }
    }
    int rangeMinQuery(int l, int r)
    {
        int k = log_2[r - l + 1];
        if (st[k][l] <= st[k][r - (1 << k) + 1])
            return ind[k][l];
        return ind[k][r - (1 << k) + 1];
    }
};
//* Using Euler Tour + Sparse Table Range Minimum Query
//* Time Complexity : O(NlogN)
class Solution
{
public:
    vector<TreeNode *> nodes;
    vector<int> depth;
    unordered_map<int, int> index;

    void visit(TreeNode *node, int nodeDepth)
    {
        index[node->val] = nodes.size();
        nodes.push_back(node);
        depth.push_back(nodeDepth);
    }
    void dfs(TreeNode *root, int nodeDepth = 0)
    {
        visit(root, nodeDepth);
        if (root->left != NULL)
        {
            dfs(root->left, nodeDepth + 1);
            visit(root, nodeDepth);
        }
        if (root->right)
        {
            dfs(root->right, nodeDepth + 1);
            visit(root, nodeDepth);
        }
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        dfs(root);
        int l = index[p->val];
        int r = index[q->val];
        if (l > r)
            swap(l, r);
        SparseTable st(depth);
        return nodes[st.rangeMinQuery(l, r)];
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//* Solution Using PostOrder Traveral
// Time Complexity : O(N)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return (left) ? left : right;
    }
};