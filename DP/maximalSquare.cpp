#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        bool allZero = true;
        for (int i = 0; i < n; i++)
        {
            if (allZero)
                allZero = matrix[i][0] == '0';
            dp[i][0] = matrix[i][0] - '0';
        }
        for (int j = 0; j < m; j++)
        {
            if (allZero)
                allZero = matrix[0][j] == '0';
            dp[0][j] = matrix[0][j] - '0';
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    continue;
                if (allZero)
                    allZero = false;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                ans = max(dp[i][j], ans);
            }
        }
        return max(ans * ans, ((allZero) ? 0 : 1));
    }
};