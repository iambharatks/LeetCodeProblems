#include <bits/stdc++.h>

using namespace std;
// Find the number of islands
//BFS
class Solution1
{
public:
    void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int dr[] = {-1, 1, 0, 0, -1, 1, 1, -1};
        int dc[] = {0, 0, 1, -1, -1, 1, -1, 1};
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
            for (int i = 0; i < 8; i++)
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
//better
//dfs
class Solution2
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (auto &v : grid)
        for (char &c : v)
            cin >> c;
    cout << Solution2().numIslands(grid);
}