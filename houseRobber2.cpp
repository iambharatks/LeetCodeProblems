#include <bits/stdc++.h>

using namespace std;

// 213. House Robber II

class Solution
{
public:
    int ans(vector<int> &nums, int idx, int n)
    {
        int inc = nums[idx];
        int exc = 0;
        for (int i = idx + 1; i < n; i++)
        {
            exc += nums[i];
            if (exc <= inc)
                exc = inc;
            else
                swap(exc, inc);
        }
        return inc;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(ans(nums, 0, nums.size() - 1), ans(nums, 1, nums.size()));
    }
};
