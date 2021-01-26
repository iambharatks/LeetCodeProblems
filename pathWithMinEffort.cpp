#include <bits/stdc++.h>

using namespace std;
//! still not done
//TODO
class SolutionNaive
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        const int r = heights.size();
        const int c = heights[0].size();
        int dp[100][100];
        memset(dp, 0x7f, sizeof(dp));
        dp[0][0] = 0;
        vector<int> dirs{0, -1, 0, 1, 0};
        for (int k = 0; k < r * c; ++k)
        {
            bool stable = true;
            for (int y = 0; y < r; ++y)
                for (int x = 0; x < c; ++x)
                    for (int d = 0; d < 4; ++d)
                    {
                        int tx = x + dirs[d];
                        int ty = y + dirs[d + 1];
                        if (tx < 0 || tx == c || ty < 0 || ty == r)
                            continue;
                        int t = max(dp[ty][tx], abs(heights[ty][tx] - heights[y][x]));
                        if (t < dp[y][x])
                        {
                            stable = false;
                            dp[y][x] = t;
                        }
                    }
            if (stable)
                break;
        }
        return dp[r - 1][c - 1];
    }
};
class BinarySearchBFS
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        const int rows = heights.size();
        const int cols = heights[0].size();
        vector<int> dirs{0, -1, 0, 1, 0};
        auto bfs = [&](int cost) -> bool {
            queue<pair<int, int>> q;
            vector<int> seen(cols * rows);
            q.emplace(0, 0);
            seen[0] = 1;
            while (!q.empty())
            {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                if (cx == cols - 1 && cy == rows - 1)
                    return true;
                for (int i = 0; i < 4; ++i)
                {
                    int x = cx + dirs[i];
                    int y = cy + dirs[i + 1];
                    if (x < 0 || x == cols || y < 0 || y == rows)
                        continue;
                    if (abs(heights[cy][cx] - heights[y][x]) > cost)
                        continue;
                    if (seen[y * cols + x]++)
                        continue;
                    q.emplace(x, y);
                }
            }
            return false;
        };
        int l = 0, r = 1e6 + 1;
        while (l < r)
        {
            const int m = l + (r - l) / 2;
            if (bfs(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};
class Dijkstra
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        const vector<int> dirs{0, -1, 0, 1, 0};
        const int rows = heights.size();
        const int cols = heights[0].size();
        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        vector<int> dist(rows * cols, INT_MAX / 2);
        q.emplace(0, 0);
        dist[0] = 0;
        while (!q.empty())
        {
            int t = q.top().first;
            int u = q.top().second;
            q.pop();
            if (u == rows * cols - 1)
                return t;
            if (t > dist[u])
                continue;
            const int ux = u % cols;
            const int uy = u / cols;
            for (int i = 0; i < 4; ++i)
            {
                const int x = ux + dirs[i];
                const int y = uy + dirs[i + 1];
                if (x < 0 || x == cols || y < 0 || y == rows)
                    continue;
                const int v = y * cols + x;
                const int c = abs(heights[uy][ux] - heights[y][x]);
                if (max(t, c) >= dist[v])
                    continue;
                q.emplace(dist[v] = max(t, c), v);
            }
        }
        return -1;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m, 0));
    for (auto &v : heights)
        for (int &i : v)
            cin >> i;
    cout << Dijkstra().minimumEffortPath(heights);
}