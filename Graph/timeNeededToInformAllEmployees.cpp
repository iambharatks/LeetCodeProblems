#include <bits/stdc++.h>

using namespace std;

// 1376. Time Needed to Inform All Employees
class Solution
{
public:
    int dfs(vector<vector<int>> &adj, int src, vector<int> &informTime)
    {
        if (adj[src].size() == 0)
            return 0;
        int res = 0;
        for (int &neigh : adj[src])
            res = max(res, dfs(adj, neigh, informTime));
        return res + informTime[src];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(adj, headID, informTime);
    }
};