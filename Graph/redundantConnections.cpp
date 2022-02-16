#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int par[1001];
    int size[1001];
    int findSet(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = findSet(par[u]);
    }
    bool unionSet(int u, int v)
    {
        u = findSet(u);
        v = findSet(v);
        if (u != v)
        {
            if (size[u] < size[v])
                swap(u, v);
            size[u] += size[v];
            par[v] = u;
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        for (int i = 0; i < 1001; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
        for (auto &v : edges)
        {
            if (unionSet(v[0], v[1]))
                continue;
            else
            {
                return v;
            }
        }
        return {};
    }
};