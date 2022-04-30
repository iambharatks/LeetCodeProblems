#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool dfs(string src, string des, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis, double &res)
    {
        vis.insert(src);
        if (src == des)
        {
            return true;
        }
        for (auto p : adj[src])
        {
            res *= p.second;
            if (!vis.count(p.first) && dfs(p.first, des, adj, vis, res))
            {
                return true;
            }
            res /= p.second;
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        int i = 0;
        for (auto v : equations)
        {
            adj[v[0]].push_back({v[1], values[i]});
            adj[v[1]].push_back({v[0], 1.0 / values[i]});
            i++;
        }
        vector<double> res;
        double cur = 1.0;
        for (auto q : queries)
        {
            unordered_set<string> vis;
            cur = 1.0;
            if (adj.count(q[0]) && adj.count(q[1]) && dfs(q[0], q[1], adj, vis, cur))
            {
                res.push_back(cur);
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};