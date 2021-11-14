#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (s[0] == '0')
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '0' && (s[i - 2] == '0' || s[i - 2] >= '3'))
                continue;
            if (s[i - 1] == '0')
                dp[i] = dp[i - 2];
            else if (s[i - 1] <= '6' && s[i - 2] > '0' && s[i - 2] < '3')
                dp[i] = dp[i - 1] + dp[i - 2];
            else if (s[i - 1] <= '6')
                dp[i] = dp[i - 1];
            else if (s[i - 1] > '6' && s[i - 2] == '1')
                dp[i] = dp[i - 1] + dp[i - 2];
            else if (s[i - 1] > '6')
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};