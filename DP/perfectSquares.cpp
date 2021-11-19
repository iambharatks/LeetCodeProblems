#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 1)
            return n;
        int k = sqrt(n) + 1;
        int dp[n + 1][k + 1];
        for (int i = 0; i <= k; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = INT_MAX - 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i >= j * j)
                    dp[i][j] = min(dp[i - j * j][j] + 1, dp[i][j - 1]);
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[n][k];
    }
};
class Solution
{
public:
    int numSquares(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};