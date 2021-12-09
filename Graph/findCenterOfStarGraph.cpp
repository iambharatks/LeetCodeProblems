#include <bits/stdc++.h>

using namespace std;

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