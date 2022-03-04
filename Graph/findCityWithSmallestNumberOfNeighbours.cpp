#include <bits/stdc++.h>

using namespace std;

//! O(N^4) [ TIME LIMITED EXCEEDED ]
class Solution
{
public:
    int bellmanFord(int src, vector<vector<int>> &edges, int n, int distanceThreshold)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto &edge : edges)
            {
                if (dist[edge[0]] != INT_MAX && dist[edge[0]] + edge[2] < dist[edge[1]])
                    dist[edge[1]] = dist[edge[0]] + edge[2];
                if (dist[edge[1]] != INT_MAX && dist[edge[1]] + edge[2] < dist[edge[0]])
                    dist[edge[0]] = dist[edge[1]] + edge[2];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (dist[i] <= distanceThreshold);
        }
        return res - 1;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int maxCities = INT_MAX, res = -1;
        for (int i = 0; i < n; i++)
        {
            int cur = bellmanFord(i, edges, n, distanceThreshold);
            if (maxCities >= cur)
            {
                maxCities = cur;
                res = i;
            }
        }
        return res;
    }
};

//* O(N^3) [ACCEPTED]
class Solution
{
public:
    void floydWarshal(int n, vector<vector<int>> &dp)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (auto &edge : edges)
        {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
        floydWarshal(n, dp);
        int res = 0, maxCity = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int curCity = 0;
            for (int j = 0; j < n; j++)
            {
                curCity += (dp[i][j] <= distanceThreshold);
            }
            if (maxCity >= curCity)
            {
                maxCity = curCity;
                res = i;
            }
        }
        return res;
    }
};

//* O(N*N*logN) [ACCEPTED]
class Solution
{
public:
    int dijkstra(int src, vector<vector<pair<int, int>>> &graph, int n, int distanceThreshold)
    {
        map<int, int> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.insert({src, 0});
        while (!pq.empty())
        {
            int node = pq.begin()->first;
            pq.erase(pq.begin());
            for (auto &neigh : graph[node])
            {
                if (dist[neigh.first] > dist[node] + neigh.second)
                {
                    dist[neigh.first] = dist[node] + neigh.second;
                    if (pq.count(neigh.first))
                        pq.erase(neigh.first);
                    pq.insert({neigh.first, dist[neigh.first]});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (dist[i] <= distanceThreshold);
        }
        return res;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        int res = 0, maxCity = INT_MAX, curCity = 0;
        for (int i = 0; i < n; i++)
        {
            curCity = dijkstra(i, graph, n, distanceThreshold);
            if (maxCity >= curCity)
            {
                maxCity = curCity;
                res = i;
            }
        }
        return res;
    }
};