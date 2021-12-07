#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end());

        vector<int> freq(n + 1, 0);
        vector<int> dp(n + 1, 0);
        for (int i : nums)
            freq[i]++;
        dp[0] = 0;
        dp[1] = freq[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
            cout << dp[i] << ' ';
        }
        return dp[n];
    }
};
class Solution
{
    vector<int> freq;
    vector<int> dp;

public:
    int rec(int n)
    {
        if (n <= 1)
            return freq[n];
        if (dp[n] != -1)
            return dp[n];
        dp[n - 2] = rec(n - 2);
        dp[n - 1] = rec(n - 1);
        dp[n] = max(dp[n - 2] + n * freq[n], dp[n - 1]);
        return dp[n];
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end());
        dp.resize(n + 1, -1);
        freq.resize(n + 1, 0);

        for (int i : nums)
        {
            freq[i]++;
        }
        return rec(n);
    }
};