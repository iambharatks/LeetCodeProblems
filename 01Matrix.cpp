#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void createGraph(vector<vector<int>> &adj, int r, int c)
    {
        int k = 1;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i == r && j != c)
                {
                    adj[k].push_back(k + 1);
                    adj[k + 1].push_back(k);
                }
                else if (i != r && j == c)
                {
                    adj[k].push_back(k + c);
                    adj[k + c].push_back(k);
                }
                else if (i != r && j != c)
                {
                    adj[k].push_back(k + 1);
                    adj[k + 1].push_back(k);
                    adj[k].push_back(k + c);
                    adj[k + c].push_back(k);
                }
                k++;
            }
        }
    }

    void bfs(vector<vector<int>> &adj, queue<int> &q, vector<int> &dist, vector<bool> &visit)
    {
        int tmp;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            for (int neigh : adj[tmp])
            {
                if (!visit[neigh])
                {
                    dist[neigh] = min(dist[neigh], dist[tmp] + 1);
                    q.push(neigh);
                    visit[neigh] = true;
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> adj(r * c + 1);
        createGraph(adj, r, c);
        vector<int> dist(r * c + 1, INT_MAX);
        vector<bool> visit(r * c + 1, 0);
        int k = 1;
        queue<int> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dist[k] = 0;
                    visit[k] = true;
                    q.push(k);
                }
                k++;
            }
        }
        bfs(adj, q, dist, visit);
        for (int i = 1; i < r * c + 1; i++)
        {
            int row = (i - 1) / c;
            int col = i - row * c - 1;
            matrix[row][col] = dist[i];
        }
        return matrix;
    }
};