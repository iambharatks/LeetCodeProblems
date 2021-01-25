#include <bits/stdc++.h>

using namespace std;

// Rotting Oranges

class Solution
{
public:
    bool isEnd(pair<int, int> p) { return (p.first == -1) && (p.second == -1); }
    bool isSafe(pair<int, int> p, int r, int c) { return (p.first >= 0 && p.second >= 0 && p.first < r && p.second < c); }
    void printPair(pair<int, int> p) { cout << p.first << " " << p.second << "\n"; }
    bool checkAllRotten(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    return false;
        return true;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> Q;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j] == 2)
                    Q.push({i, j});
        Q.push({-1, -1});
        int time = 0;
        pair<int, int> tmp;
        while (!Q.empty())
        {
            tmp = Q.front();
            Q.pop();
            if (!isEnd(tmp))
            {
                if (isSafe({tmp.first + 1, tmp.second}, r, c) && grid[tmp.first + 1][tmp.second] == 1)
                {
                    grid[tmp.first + 1][tmp.second] = 2;
                    tmp.first++;
                    Q.push(tmp);
                    tmp.first--;
                }
                if (isSafe({tmp.first - 1, tmp.second}, r, c) && grid[tmp.first - 1][tmp.second] == 1)
                {
                    grid[tmp.first - 1][tmp.second] = 2;
                    tmp.first--;
                    Q.push(tmp);
                    tmp.first++;
                }
                if (isSafe({tmp.first, tmp.second + 1}, r, c) && grid[tmp.first][tmp.second + 1] == 1)
                {
                    grid[tmp.first][tmp.second + 1] = 2;
                    tmp.second++;
                    Q.push(tmp);
                    tmp.second--;
                }
                if (isSafe({tmp.first, tmp.second - 1}, r, c) && grid[tmp.first][tmp.second - 1] == 1)
                {
                    grid[tmp.first][tmp.second - 1] = 2;
                    tmp.second--;
                    Q.push(tmp);
                    tmp.second++;
                }
            }
            else if (Q.empty())
                break;
            else
            {
                time++;
                Q.push(tmp);
                continue;
            }
        }
        if (checkAllRotten(grid))
            return time;
        else
            return -1;
    }
};