#include <bits/stdc++.h>

using namespace std;

//   Combination Sum IV

class Solution
{
    vector<long long> dp;
    const int max = 2147483647;

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, 0);

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                    dp[i] += 1;
                if (nums[j] < i)
                    dp[i] += dp[i - nums[j]];
                dp[i] %= max;
            }
        }
        for (int i = 0; i <= target; i++)
            if (dp[i])
                cout << i << " " << dp[i] << "\n";
        return dp[target];
    }
};

int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    cin >> target;
    cout << Solution().combinationSum4(nums, target);
}