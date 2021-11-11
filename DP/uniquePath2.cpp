#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = (obstacleGrid[i][j - 1] != 1) ? dp[i][j - 1] : 0;
                else if (j == 0)
                    dp[i][j] = (obstacleGrid[i - 1][j] != 1) ? dp[i - 1][j] : 0;
                else
                {
                    if (!obstacleGrid[i - 1][j])
                        dp[i][j] = dp[i - 1][j];
                    if (!obstacleGrid[i][j - 1])
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};