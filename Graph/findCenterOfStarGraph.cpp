#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &e)
    {
        return (e[0][0] == e[1][0] || e[0][0] == e[1][1]) ? e[0][0] : e[0][1];
    }
};

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> numberOfEdges(n + 1, 0);
        for (auto v : edges)
        {
            numberOfEdges[v[0] - 1]++;
            numberOfEdges[v[1] - 1]++;
            if (numberOfEdges[v[0] - 1] == n)
                return v[0];
            if (numberOfEdges[v[1] - 1] == n)
                return v[1];
        }
        return -1;
    }
};