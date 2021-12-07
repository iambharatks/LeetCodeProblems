#include <bits/stdc++.h>

using namespace std;

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
            return v.first * 1000 + v.second;
        }
    };
    unordered_set<pair<int, int>, pair_hash> vis;

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx)
    {
        vis.insert({i, j});
        if (idx == word.size())
            return true;
        for (int k = 0; k < 4; k++)
        {
            int rr = i + dr[k];
            int cc = j + dc[k];
            if (rr >= 0 && cc >= 0 && rr <= n - 1 && cc <= m - 1 && (vis.find({rr, cc}) == vis.end()) && board[rr][cc] == word[idx] && dfs(board, word, rr, cc, idx + 1))
                return true;
        }
        vis.erase({i, j});
        return false;
    }
    bool exist(vector<vector<char>> &board, string &word)
    {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};