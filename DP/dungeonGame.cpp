#include <bits/stdc++.h>

using namespace std;

// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + recursive stacks

class Memoization
{
public:
    int n, m;
    vector<vector<int>> dp;
    int rec(vector<vector<int>> &dungeon, int i, int j)
    {
        if (i == n || j == m)
            return 1e9;
        if (dp[i][j] != 1e9)
            return dp[i][j];

        if (i == n - 1 && j == m - 1)
            return dp[i][j] = dungeon[i][j] <= 0 ? -dungeon[i][j] + 1 : 1;

        int right = rec(dungeon, i, j + 1);
        int down = rec(dungeon, i + 1, j);

        dp[i][j] = min(down, right) - dungeon[i][j];
        dp[i][j] = dp[i][j] <= 0 ? 1 : dp[i][j];
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        n = dungeon.size();
        m = dungeon[0].size();
        dp.resize(n, vector<int>(m, 1e9));
        return rec(dungeon, 0, 0);
    }
};

class Tabulation
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = dungeon[i][j] < 0 ? -dungeon[i][j] + 1 : 1;
                    continue;
                }
                if (i < n)
                    dp[i][j] = dp[i + 1][j];
                if (j < m)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = (dp[i][j] <= 0) ? 1 : dp[i][j];
            }
        }
        return dp[0][0];
    }
};