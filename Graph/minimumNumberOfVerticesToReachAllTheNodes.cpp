#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> degree(n);
        for (auto edge : edges)
        {
            degree[edge[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};