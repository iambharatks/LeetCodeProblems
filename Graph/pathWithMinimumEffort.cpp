#include <bits/stdc++.h>

using namespace std;

// using binarySearch
class Solution
{
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    bool isPossible(vector<vector<int>> &heights, int &maxEffort)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[0][0] = true;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == n - 1 && c == m - 1)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc])
                    continue;
                if (abs(heights[nr][nc] - heights[r][c]) > maxEffort)
                    continue;
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int l = 0, r = 1e6, res = 1e6;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(heights, mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
                l = mid + 1;
        }
        return res;
    }
};

class effort
{
public:
    int r, c, diff;
    effort(int r, int c, int diff) : r(r), c(c), diff(diff) {}
};

class cmp
{
public:
    bool operator()(effort const &a, effort const &b)
    {
        return a.diff > b.diff;
    }
};
// using modified Dijkstra 1
class Solution
{
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int res = 0;
        priority_queue<effort, vector<effort>, cmp> pq;
        pq.push(effort(0, 0, 0));
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX / 2));
        dist[0][0] = 0;
        while (!pq.empty())
        {
            effort e = pq.top();
            pq.pop();
            if (dist[e.r][e.c] < e.diff)
                continue;
            res = max(res, e.diff);
            if (e.r == n - 1 && e.c == m - 1)
                break;
            for (int i = 0; i < 4; i++)
            {
                int nr = e.r + dr[i], nc = e.c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;
                int diff = abs(heights[nr][nc] - heights[e.r][e.c]);
                if (dist[nr][nc] <= diff)
                    continue;
                pq.push(effort(nr, nc, diff));
                dist[nr][nc] = diff;
            }
        }
        return res;
    }
};

// using modified Dijkstra 2
class Solution
{
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int res = 0;
        priority_queue<effort, vector<effort>, cmp> pq;
        pq.push(effort(0, 0, 0));
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        while (!pq.empty())
        {
            effort e = pq.top();
            pq.pop();
            if (vis[e.r][e.c])
                continue;
            vis[e.r][e.c] = true;
            res = max(res, e.diff);
            if (e.r == n - 1 && e.c == m - 1)
                break;
            for (int i = 0; i < 4; i++)
            {
                int nr = e.r + dr[i], nc = e.c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc])
                    continue;
                pq.push(effort(nr, nc, abs(heights[nr][nc] - heights[e.r][e.c])));
            }
        }
        return res;
    }
};

// using dsu
class Solution
{
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    vector<vector<int>> rank, par;
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int findSet(int u)
    {
        if (par[u / 1000][u % 1000] == u)
            return u;
        return par[u / 1000][u % 1000] = findSet(par[u / 1000][u % 1000]);
    }
    void unionSet(int u, int v)
    {
        u = findSet(u);
        v = findSet(v);
        if (u == v)
            return;
        if (rank[u / 1000][u % 1000] < rank[v / 1000][v % 1000])
            swap(u, v);
        par[v / 1000][v % 1000] = u;
        if (rank[u / 1000][u % 1000] == rank[v / 1000][v % 1000])
            rank[u / 1000][u % 1000]++;
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> edge;
        // makeset
        for (int i = 0; i < n; i++)
        {
            rank.push_back({});
            par.push_back({});
            for (int j = 0; j < m; j++)
            {
                par.back().push_back(i * 1000 + j);
                rank.back().push_back(0);

                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;
                    edge.push_back({nr * 1000 + nc, i * 1000 + j, abs(heights[nr][nc] - heights[i][j])});
                }
            }
        }
        sort(edge.begin(), edge.end(), cmp);
        int ptr = 0;
        while (findSet(0) != findSet(1000 * (n - 1) + m - 1) && ptr < edge.size())
        {
            unionSet(edge[ptr][0], edge[ptr][1]);
            ptr++;
        }
        if (ptr == 0)
            return 0;
        return edge[ptr - 1][2];
    }
};