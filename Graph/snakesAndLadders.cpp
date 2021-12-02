#include <bits/stdc++.h>

using namespace std;

//With graph
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

// NO need to create a  graph
//Better
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

    int snakesAndLadders(vector<vector<int>> &board)
    {
        pair<int, int> p;
        int n = board.size();

        vector<int> dist(n * n + 1, INT_MAX);
        int v;
        pair<int, int> neigh;
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            if (v == n * n)
                return dist[v];
            for (int i = 1; i < 7; i++)
            {
                if (i + v > n * n)
                    break;
                if (i + v <= n * n)
                {
                    p = rc(i + v, n);
                    if (board[p.first][p.second] == -1)
                    {
                        if (dist[i + v] != INT_MAX)
                            continue;
                        q.push(i + v);
                        dist[i + v] = dist[v] + 1;
                    }
                    else
                    {
                        if (dist[board[p.first][p.second]] != INT_MAX)
                            continue;
                        q.push(board[p.first][p.second]);
                        dist[board[p.first][p.second]] = dist[v] + 1;
                    }
                }
            }
        }
        return -1;
    }
};