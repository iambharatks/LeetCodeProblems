#include <bits/stdc++.h>

using namespace std;
//  Number of Operations to Make Network Connected
class Solution
{

public:
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[src] = true;
        for (int neigh : adj[src])
            if (!visited[neigh])
                dfs(neigh, adj, visited);
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int no_of_edges = connections.size();
        vector<bool> visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int no_of_components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                no_of_components++;
                dfs(i, adj, visited);
            }
        }
        if (no_of_components == 1)
            return 0;
        if (no_of_edges < n - 1)
            return -1;
        return no_of_components - 1;
    }
};