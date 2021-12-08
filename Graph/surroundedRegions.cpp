#include <bits/stdc++.h>

using namespace std;

// Naive Approach
// Brute Force
class Solution
{
public:
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    struct pair_hash
    {
        size_t operator()(const pair<int, int> &v) const
        {
            return v.first * 200 + v.second;
        }
    };
    unordered_set<pair<int, int>, pair_hash> vis;

    void bfs(vector<vector<char>> &board, int r, int c)
    {
        unordered_set<pair<int, int>, pair_hash> region;
        queue<int> qr, qc;
        qr.push(r);
        qc.push(c);
        vis.insert({r, c});
        region.insert({r, c});
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
                if (rr < 0 || cc < 0 || rr >= n || cc >= m || board[rr][cc] == 'X' || vis.find({rr, cc}) != vis.end())
                    continue;
                qr.push(rr);
                qc.push(cc);
                vis.insert({rr, cc});
                region.insert({rr, cc});
            }
        }
        bool surrounded = true;
        for (auto p : region)
        {
            if (p.first == 0 || p.second == 0 || p.first == n - 1 || p.second == m - 1)
            {
                surrounded = false;
                break;
            }
        }
        if (surrounded)
        {
            for (auto p : region)
                board[p.first][p.second] = 'X';
        }
    }
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && vis.find({i, j}) == vis.end())
                {
                    bfs(board, i, j);
                }
            }
        }
    }
};

// Small optimisation
// just correct those regions of 'O' which are connected to border by applying bfs to only border 'O's
class Solution
{
public:
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> vis;

    void bfs(vector<vector<char>> &board, int r, int c)
    {
        queue<int> qr, qc;
        qr.push(r);
        qc.push(c);
        vis[r][c] = true;
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
                if (rr < 0 || cc < 0 || rr >= n || cc >= m || board[rr][cc] == 'X' || vis[rr][cc])
                    continue;
                qr.push(rr);
                qc.push(cc);
                vis[rr][cc] = true;
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                bfs(board, i, 0);
            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                bfs(board, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O' && !vis[0][i])
                bfs(board, 0, i);
            if (board[n - 1][i] == 'O' && !vis[n - 1][i])
                bfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};