#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int points = questions[i][0];
            int jumps = questions[i][1];
            dp[i] = max(dp[i + 1], points + dp[min(i + jumps + 1, n)]);
        }
        return dp[0];
    }
};