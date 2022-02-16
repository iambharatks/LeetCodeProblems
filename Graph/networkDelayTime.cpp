#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b) { return a.first >= b.first; }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto &v : times)
        {
            g[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> tm(n + 1, INT_MAX);
        tm[k] = 0;
        pq.push({0, k});
        int time = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            time = pq.top().first;
            // cout<<node<<" "<<time<<'\n';
            pq.pop();
            if (tm[node] < time)
                continue;
            for (pair<int, int> &p : g[node])
            {
                if (tm[p.first] > p.second + time)
                {
                    tm[p.first] = p.second + time;
                    pq.push({p.second + time, p.first});
                }
            }
        }
        time = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            time = max(time, tm[i]);
        }
        return time == INT_MAX ? -1 : time;
    }
};