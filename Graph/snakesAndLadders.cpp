#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    pair<int, int> rc(int i, int n)
    {
        int r, c;
        c = (i - 1) % n;
        if (((i - 1) / n) & 1)
            c = n - c - 1;
        r = n - (i - 1) / n - 1;
        return {r, c};
    }
    int bfs(vector<vector<int>> &adj)
    {
        vector<int> dist(adj.size(), INT_MAX);
        int v;
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            for (int neigh : adj[v])
            {
                if (dist[neigh] == INT_MAX)
                {
                    q.push(neigh);
                    dist[neigh] = dist[v] + 1;
                }
            }
        }
        return dist.back() == INT_MAX ? -1 : dist.back();
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        pair<int, int> p;
        int n = board.size();
        vector<vector<int>> adj(n * n + 1);
        for (int i = 1; i <= n * n; i++)
        {
            p = rc(i, n);
            for (int j = 1; j <= 6; j++)
            {
                if (i + j <= n * n)
                {
                    pair<int, int> p1 = rc(i + j, n);
                    if (board[p1.first][p1.second] == -1)
                        adj[i].push_back(i + j);
                    else
                        adj[i].push_back(board[p1.first][p1.second]);
                }
            }
        }

        return bfs(adj);
    }
};