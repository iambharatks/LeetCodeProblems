#include <bits/stdc++.h>

using namespace std;

//  Shortest Path in Binary Matrix

class Solution
{

public:
    bool isSafe(int r, int c, int n, int m)
    {
        return (r >= 0 && r < n && c < m && c >= 0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int dr[] = {0, 0, -1, 1, -1, 1, 1, -1};
        int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        queue<int> qr, qc;
        int n = grid.size();
        int m = grid[0].size();
        qr.push(0);
        qc.push(0);
        if (grid[0][0] || grid[n - 1][m - 1])
            return -1;
        grid[0][0] = 1;
        if (n == 1 && m == 1)
            return 1;
        while (!qr.empty())
        {
            int r = qr.front();
            int c = qc.front();
            qr.pop();
            qc.pop();
            for (int i = 0; i < 8; i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (isSafe(rr, cc, n, m) && grid[rr][cc] == 0)
                {
                    grid[rr][cc] = grid[r][c] + 1;
                    if (rr == n - 1 && cc == m - 1)
                        return grid[rr][cc];
                    qr.push(rr);
                    qc.push(cc);
                }
            }
        }
        return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &v : grid)
        for (int &i : v)
            cin >> i;
    cout << Solution().shortestPathBinaryMatrix(grid);
}