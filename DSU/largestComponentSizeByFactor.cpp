#include <bits/stdc++.h>

using namespace std;

class DSU
{
public:
    vector<int> par;
    vector<int> size;
    DSU(int n) : par(100005, -1), size(100005, 0) {}
    int find_set(int u)
    {
        if (par[u] == -1)
        {
            par[u] = u;
            size[u] = 1;
        }
        if (par[u] == u)
            return u;
        return par[u] = find_set(par[u]);
    }
    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }
            par[v] = u;
            size[u] += size[v];
        }
    }
};
class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        DSU dsu(nums.size());
        for (int num : nums)
        {
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    dsu.union_set(i, num);
                    dsu.union_set(num / i, num);
                }
            }
        }
        int res = 0;
        int mp[100005];
        memset(mp, 0, sizeof(mp));
        for (int &i : nums)
        {
            mp[dsu.find_set(i)]++;
        }
        return *max_element(mp, mp + 100005);
    }
};