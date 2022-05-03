#include <bits/stdc++.h>

using namespace std;

// Time Complexity : O(NlogN)
// Space Complexity : O(N)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis.empty() || lis.back() < nums[i])
                lis.push_back(nums[i]);
            else
            {
                *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
            }
        }
        return (int)lis.size();
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};