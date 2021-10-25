#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int step1, step2, c;
        step1 = 0;
        step2 = 0;
        for (int i = 2; i <= n; i++)
        {
            c = min(cost[i - 1] + step1, cost[i - 2] + step2);
            step2 = step1;
            step1 = c;
        }
        return c;
    }
};
