#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++)
        {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.00);
        vector<bool> vis(n);
        pq.push({1, start});
        prob[start] = 1;
        while (!pq.empty())
        {
            double p = pq.top().first;
            int st = pq.top().second;
            pq.pop();
            if (vis[st])
                continue;
            vis[st] = true;
            for (auto v : g[st])
            {
                if (prob[v.first] < v.second * p)
                {
                    prob[v.first] = v.second * p;
                    pq.push({prob[v.first], v.first});
                }
            }
        }
        return prob[end];
    }
};