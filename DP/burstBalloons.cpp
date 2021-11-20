#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int **dp;
    int maxCoins(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mx = 0;
        for (int k = i; k <= j; k++)
        {
            int tmp = maxCoins(nums, i, k - 1) + maxCoins(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j + 1];
            mx = max(tmp, mx);
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        dp = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++)
                dp[i][j] = -1;
        }

        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++)
        {
            a[i + 1] = nums[i];
        }
        return maxCoins(a, 1, n);
    }
};