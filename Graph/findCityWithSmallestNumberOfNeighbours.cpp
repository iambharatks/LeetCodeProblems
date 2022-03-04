#include <bits/stdc++.h>

using namespace std;

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
