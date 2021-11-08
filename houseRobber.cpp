#include <bits/stdc++.h>

using namespace std;

// 198. House Robber
class SolutionMemoization
{
    int *dp;

public:
    int rec(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        if (n == 1)
            return dp[n] = nums[n - 1];
        return dp[n] = max(nums[n - 1] + rec(nums, n - 2), rec(nums, n - 1));
    }
    int rob(vector<int> &nums)
    {
        dp = new int[1e5];
        memset(dp, -1, sizeof(int) * 1e5);
        return rec(nums, nums.size());
    }
};
class SolutionTabulation
{
    int *dp;

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        dp = new int[1e5]{0};
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
};
class SolutionOptimal
{
public:
    int rob(vector<int> &nums)
    {
        int inc, exc;
        inc = nums[0];
        exc = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            exc += nums[i];
            if (inc < exc)
                swap(inc, exc);
            else
                exc = inc;
        }
        return max(inc, exc);
    }
};
int main()
{
}