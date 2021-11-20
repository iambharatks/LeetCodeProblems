#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int **dp;
    int maxProfit(vector<int> prices, int i, bool toBuy)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][toBuy] != -1)
            return dp[i][toBuy];
        if (toBuy)
        {
            return dp[i][toBuy] = max(maxProfit(prices, i + 1, false) - prices[i], maxProfit(prices, i + 1, true));
        }
        return dp[i][toBuy] = max(maxProfit(prices, i + 2, true) + prices[i], maxProfit(prices, i + 1, false));
    }
    int maxProfit(vector<int> &prices)
    {
        dp = new int *[prices.size()];
        for (int i = 0; i < prices.size(); i++)
        {
            dp[i] = new int[2];
            dp[i][0] = dp[i][1] = -1;
        }
        return maxProfit(prices, 0, true);
    }
};