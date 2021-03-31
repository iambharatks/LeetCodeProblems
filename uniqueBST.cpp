#include <bits/stdc++.h>

using namespace std;

// Unique Binary Search Trees
// This is catalan number series

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp[n];
    }
};
