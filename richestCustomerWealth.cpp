#include <bits/stdc++.h>

using namespace std;
// Richest Customer Wealth

class Solution
{
public:
    int sum(vector<int> wealth)
    {
        int sum = 0;
        for (int i : wealth)
            sum += i;
        return sum;
    }
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0;
        for (auto v : accounts)
        {
            maxWealth = max(sum(v), maxWealth);
        }
        return maxWealth;
    }
};