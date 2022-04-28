#include <bits/stdc++.h>

using namespace std;

class Pos
{
public:
    int r, c, val;
    Pos(int r, int c, int val) : r(r), c(c), val(val) {}
};
class cmp
{
public:
    bool operator()(Pos const &a, Pos const &b)
    {
        return a.val > b.val;
    }
};
class Solution
{
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int swimInWater(vector<vector<int>> &grid)
    {
        priority_queue<Pos, vector<Pos>, cmp> pq;
        pq.push(Pos(0, 0, grid[0][0]));
        int n = grid.size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool>(n));
        while (!pq.empty())
        {
            Pos p = pq.top();
            pq.pop();
            if (vis[p.r][p.c])
                continue;
            vis[p.r][p.c] = true;
            res = max(res, p.val);
            if (p.r == n - 1 && p.c == n - 1)
                break;
            for (int i = 0; i < 4; i++)
            {
                int r = p.r + dr[i];
                int c = p.c + dc[i];
                if (r < 0 || c < 0 || r >= n | c >= n || vis[r][c])
                    continue;
                pq.push(Pos(r, c, grid[r][c]));
            }
        }
        return res;
    }
};