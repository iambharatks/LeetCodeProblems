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

class Solution1
{
public:
    bool comparator(pair<int, int> a, int b)
    {
        return a.second <= b;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        unordered_map<int, vector<pair<int, int>>> mp;
        int cnt = 0, left = 0, right = 0, height = 0;
        pair<TreeNode *, int> tmp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        q.push({NULL, 0});
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp.first == NULL)
            {
                if (q.empty())
                    break;
                q.push({NULL, 0});
                height++;
                continue;
            }
            left = (left > tmp.second) ? tmp.second : left;
            right = (right >= tmp.second) ? right : tmp.second;
            mp[tmp.second].push_back({tmp.first->val, height});
            if (!mp[tmp.second].empty())
            {
                auto it = lower_bound(mp[tmp.second].begin(), mp[tmp.second].end(), height, comparator);
                sort(it, mp[tmp.second].end());
            }
            if (tmp.first->left)
                q.push({tmp.first->left, tmp.second - 1});
            if (tmp.first->right)
                q.push({tmp.first->right, tmp.second + 1});
        }
        int n = right - left + 1;
        vector<vector<int>> soln(n);
        int x = 0;
        for (int i = left; i <= right; i++)
        {
            for (auto i : mp[i])
                soln[x].push_back(i.first);
            x++;
        }
        return soln;
    }
};
class Solution2
{
public:
    // used to store answers
    // first key will store current x coordinate
    // second key will store a pair {y corrdinates , root->value}

    map<int, vector<pair<int, int>>> mp;

    void Traverse_Vertically(TreeNode *root, int curr_x, int curr_y)
    {
        if (root == NULL)
            return;

        mp[curr_x].push_back({curr_y, root->val});
        Traverse_Vertically(root->left, curr_x - 1, curr_y + 1);
        Traverse_Vertically(root->right, curr_x + 1, curr_y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        mp.clear(); // clear the map

        vector<int> temp; // temporary vector

        Traverse_Vertically(root, 0, 0); // start vertical traversal from root

        vector<vector<int>> ans;

        for (auto it : mp)
        {

            temp.clear();

            // sort the pairs {y corrdinates , root->value} in ascending order
            sort(it.second.begin(), it.second.end());

            // store our current ans in temporary vector
            for (auto itr : it.second)
                temp.push_back(itr.second);

            // store our current traversal
            ans.push_back(temp);
        }

        return ans;
    }
};