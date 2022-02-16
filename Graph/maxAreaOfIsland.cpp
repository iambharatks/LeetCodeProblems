#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (vis[i][j] || grid[i][j] == 0)
                    continue;
                queue<int> qr;
                queue<int> qc;
                qr.push(i);
                qc.push(j);
                vis[i][j] = true;
                int curArea = 0;
                while (!qr.empty())
                {
                    int r = qr.front();
                    int c = qc.front();
                    qr.pop();
                    qc.pop();
                    curArea++;
                    for (int k = 0; k < 4; k++)
                    {
                        int nr, nc;
                        nr = r + dr[k];
                        nc = c + dc[k];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || grid[nr][nc] == 0)
                            continue;
                        qr.push(nr);
                        qc.push(nc);
                        vis[nr][nc] = true;
                    }
                }
                maxArea = max(maxArea, curArea);
            }
        }
        return maxArea;
    }
};