#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ***dp;
    int maxProfit(int k, vector<int> &prices, int i, bool toBuy)
    {
        if (i >= prices.size() || k == 0)
            return 0;

        if (dp[i][k][toBuy] != -1)
            return dp[i][k][toBuy];

        if (toBuy)
        {
            return dp[i][k][toBuy] = max(maxProfit(k, prices, i + 1, false) - prices[i], maxProfit(k, prices, i + 1, true));
        }
        return dp[i][k][toBuy] = max(maxProfit(k - 1, prices, i + 1, true) + prices[i], maxProfit(k, prices, i + 1, false));
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        dp = new int **[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[k + 1];
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = new int[2];
                for (int l = 0; l < 2; l++)
                    dp[i][j][l] = -1;
            }
        }
        return maxProfit(k, prices, 0, true);
    }
};