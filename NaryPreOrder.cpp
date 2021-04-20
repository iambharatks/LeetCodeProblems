#include <bits/stdc++.h>

using namespace std;

//   N-ary Tree Preorder Traversal

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void preorderUtil(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->val);
        for (Node *n : root->children)
        {
            preorderUtil(n, v);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        preorderUtil(root, ans);
        return ans;
    }
};

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        stack<Node *> s;
        if (!root)
            return ans;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            ans.push_back(root->val);
            s.pop();
            for (int i = root->children.size(); i >= 0; i--)
            {
                if (!(root->children[i]))
                    s.push(root->children[i]);
            }
        }
        return ans;
    }
};
