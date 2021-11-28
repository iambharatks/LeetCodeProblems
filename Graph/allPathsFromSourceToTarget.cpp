#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    int vis[16];
    void dfs(int i, vector<int> v, int n, vector<vector<int>> &g)
    {
        if (i == n)
        {
            res.push_back(v);
            return;
        }
        vis[i] = true;
        for (int ne : g[i])
        {
            if (!vis[ne])
            {
                v.push_back(ne);
                dfs(ne, v, n, g);
                v.pop_back();
            }
            vis[ne] = false;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        memset(vis, 0, sizeof(vis));
        dfs(0, {0}, graph.size() - 1, graph);
        return res;
    }
};
