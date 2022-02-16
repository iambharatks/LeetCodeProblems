#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int col[10], d1[21], d2[21];
    vector<vector<string>> res;
    int N;
    void dfs(int n, vector<string> &cur)
    {
        if (n == 0)
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < N; i++)
        {
            if (!col[i] && !d1[n + i] && !d2[N - n + i])
            {
                col[i] = d1[n + i] = d2[N - n + i] = true;
                cur[n - 1][i] = 'Q';
                dfs(n - 1, cur);
                col[i] = d1[n + i] = d2[N - n + i] = false;
                cur[n - 1][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        vector<string> cur(n, string(n, '.'));
        dfs(n, cur);
        return res;
    }
};