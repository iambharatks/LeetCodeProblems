#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int **dp;
    int maxProfit(vector<int> &prices, int i, bool toBuy)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][toBuy] != -1)
            return dp[i][toBuy];

        if (prices[i] == 0)
            dp[i][toBuy] = maxProfit(prices, i + 1, toBuy);

        if (toBuy)
        {
            return dp[i][toBuy] = max(maxProfit(prices, i + 1, false) - prices[i], maxProfit(prices, i + 1, true));
        }
        return dp[i][toBuy] = max(maxProfit(prices, i + 1, true) + prices[i], maxProfit(prices, i + 1, false));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[2];
            memset(dp[i], -1, sizeof(dp[i]));
        }
        return maxProfit(prices, 0, true);
    }
};
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1])
                maxProfit += prices[i + 1] - prices[i];
        }
        return maxProfit;
    }
};
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int i = 0;
        int buy = prices[0];
        int sell = prices[0];
        int maxProfit = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            buy = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1])
                i++;
            sell = prices[i];
            maxProfit += sell - buy;
        }
        return maxProfit;
    }
};