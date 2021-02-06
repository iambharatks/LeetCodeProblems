#include <bits/stdc++.h>

using namespace std;
// Number of Islands

class Solution
{
public:
    void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        queue<int> qr, qc;
        int n = grid.size();
        int m = grid[0].size();
        qr.push(r);
        qc.push(c);
        visited[r][c] = true;
        while (!qr.empty())
        {
            r = qr.front();
            c = qc.front();
            qr.pop();
            qc.pop();
            for (int i = 0; i < 4; i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr < 0 || cc < 0 || rr >= n || cc >= m)
                    continue;
                if (visited[rr][cc])
                    continue;
                if (grid[rr][cc] == '0')
                    continue;
                qr.push(rr);
                qc.push(cc);
                visited[rr][cc] = true;
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int numOfIslands = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    numOfIslands++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return numOfIslands;
    }
};