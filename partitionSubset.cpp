#include <bits/stdc++.h>

using namespace std;

// Partition Equal Subset Sum

class Solution
{
public:
    bool canPartition(vector<int> &arr)
    {
        int sum = 0, i, j, N;
        N = arr.size();
        for (i = 0; i < N; i++)
            sum += arr[i];

        if (sum & 1)
            return false;

        bool dp[sum / 2 + 1][N + 1];
        memset(dp, 0, sizeof(dp));

        //Initialization
        for (i = 0; i <= sum / 2; i++)
            dp[i][0] = 0;
        for (i = 0; i <= N; i++)
            dp[0][i] = 1;

        //Calculation
        for (i = 1; i <= sum / 2; i++)
        {
            for (j = 1; j <= N; j++)
            {
                if (i >= arr[j - 1])
                    dp[i][j] = dp[i][j - 1] || dp[i - arr[j - 1]][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[sum / 2][N];
    }
};
class Solution
{
    vector<vector<int>> table;

public:
    int canPartitionUtil(vector<int> &nums, int n, int subSum, int &sum)
    {
        if (subSum == sum / 2)
            return true;
        if (n < 0 || subSum > sum / 2)
            return false;
        if (table[subSum][n] != -1)
            return table[subSum][n];
        return table[subSum][n] = (canPartitionUtil(nums, n - 1, subSum + nums[n - 1], sum) || canPartitionUtil(nums, n - 1, subSum, sum));
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum & 1)
            return false;

        table.resize(sum / 2 + 1, vector<int>(nums.size() + 1, -1));

        return canPartitionUtil(nums, nums.size(), 0, sum);
    }
};