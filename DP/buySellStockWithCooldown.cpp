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
// For Understanding
//* (1) We have to `rest` before we `buy` and
//* (2) we have to `buy` before we `sell`
//TODO: 

// Great Approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int s0[n], s1[n], s2[n];
        memset(s0, 0, sizeof(s0));
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[n - 1], s2[n - 1]);
    }
};
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int s0, s1, s2;

        s0 = 0;
        s1 = -prices[0];
        s2 = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            int ps0 = s0, ps1 = s1;
            s0 = max(s0, s2);
            s1 = max(s1, ps0 - prices[i]);
            s2 = ps1 + prices[i];
        }
        return max(s0, s2);
    }
};