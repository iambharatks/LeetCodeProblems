#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int maxDist = 0;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;
                if (dist[nr][nc] > dist[r][c] + 1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    maxDist = max(maxDist, dist[nr][nc]);
                }
            }
        }

        return maxDist == 0 ? -1 : maxDist;
    }
};