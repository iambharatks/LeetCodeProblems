#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> left(n), right(n);
        int sell = prices[n - 1], buy = prices[0];
        for (int i = 0; i < n; i++)
        {
            if (buy > prices[i])
                buy = prices[i];
            else
                left[i] = prices[i] - buy;
            if (i > 0)
                left[i] = max(left[i], left[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (sell < prices[i])
                sell = prices[i];
            else
                right[i] = sell - prices[i];
            if (i < n - 1)
                right[i] = max(right[i], right[i + 1]);
        }
        int maxProfit = 0;
        maxProfit = max(left[n - 1], right[0]);
        for (int i = 1; i < n - 1; i++)
        {
            maxProfit = max(maxProfit, left[i] + right[i + 1]);
            maxProfit = max(maxProfit, left[i - 1] + right[i]);
        }
        return maxProfit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sell1 = 0, sell2 = 0;
        int buy1 = INT_MIN, buy2 = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};