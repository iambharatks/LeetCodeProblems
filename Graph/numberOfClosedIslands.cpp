#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool vis[101][101];
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int n, m;
    void dfs(int r, int c, vector<vector<int>> &grid)
    {
        vis[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nc >= m || nr >= n || grid[nr][nc] == 1 || vis[nr][nc])
                continue;
            dfs(nr, nc, grid);
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0 && !vis[i][0])
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 0 && !vis[i][m - 1])
                dfs(i, m - 1, grid);
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == 0 && !vis[n - 1][i])
                dfs(n - 1, i, grid);
            if (grid[0][i] == 0 && !vis[0][i])
                dfs(0, i, grid);
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j])
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};