#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size(), pos = 0, tot;
        tot = m * n;
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pos = (i * m + j + k) % tot;
                res[pos / m][pos % m] = grid[i][j];
            }
        }
        return res;
    }
};