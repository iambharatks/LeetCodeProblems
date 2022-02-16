#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        int idx = 0;
        for (auto s : equations)
        {
            adj[s[0]].push_back({s[1], values[idx]});
            adj[s[1]].push_back({s[0], 1.0 / values[idx]});
            idx++;
        }
        vector<double> res;
        for (auto &query : queries)
        {
            queue<pair<string, double>> q;
            unordered_set<string> vis;
            string start = query[0];
            string end = query[1];
            if (adj.count(start) == 0 || adj.count(end) == 0)
            {
                res.push_back(-1);
                continue;
            }

            q.push({start, 1});
            vis.insert(start);
            bool found = false;
            double val = 1;
            while (!q.empty())
            {
                string s = q.front().first;
                val = q.front().second;
                q.pop();
                if (s == end)
                {
                    found = true;
                    break;
                }
                for (auto p : adj[s])
                {
                    if (vis.count(p.first) == 0)
                    {
                        vis.insert(p.first);
                        q.push({p.first, val * p.second});
                    }
                }
            }
            if (!found)
                res.push_back(-1);
            else
                res.push_back(val);
        }
        return res;
    }
};