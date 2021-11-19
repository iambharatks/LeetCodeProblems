#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int i2 = 1, i3 = 1, i5 = 1;
        int dp[1691];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        int i = 2;
        int num = 0;
        while (i <= n)
        {
            dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
            if (dp[i] == dp[i2] * 2)
                i2++;
            if (dp[i] == dp[i3] * 3)
                i3++;
            if (dp[i] == dp[i5] * 5)
                i5++;
            i++;
        }
        // for(int i = 1 ; i <= n ; i++) cout<<dp[i]<<' ';
        return dp[n];
    }
};