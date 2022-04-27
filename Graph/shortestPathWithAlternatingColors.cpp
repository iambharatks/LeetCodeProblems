#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
        for (auto v : redEdges)
        {
            g[0][v[0]].push_back(v[1]);
        }
        for (auto v : blueEdges)
        {
            g[1][v[0]].push_back(v[1]);
        }
        vector<vector<int>> dist(n, vector<int>(2, INT_MIN));
        dist[0][1] = dist[0][0] = 0;
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(2));
        q.push({0, 0});
        q.push({0, 1});
        vis[0][0] = true;
        vis[0][1] = true;
        while (!q.empty())
        {
            vector<int> tp = q.front();
            q.pop();
            for (auto v : g[1 - tp[1]][tp[0]])
            {
                if (!vis[v][1 - tp[1]])
                {
                    q.push({v, 1 - tp[1]});
                    dist[v][1 - tp[1]] = dist[tp[0]][tp[1]] + 1;
                    vis[v][1 - tp[1]] = true;
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            if (dist[i][0] == INT_MIN)
                res[i] = dist[i][1];
            else if (dist[i][1] == INT_MIN)
                res[i] = dist[i][0];
            else
                res[i] = min(dist[i][0], dist[i][1]);
            if (res[i] == INT_MIN)
                res[i] = -1;
        }
        return res;
    }
};