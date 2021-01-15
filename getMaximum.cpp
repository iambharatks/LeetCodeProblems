#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        int *dp = new int[n + 4]{0};
        dp[0] = 0;
        dp[1] = 1;
        int maxVal = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1)
                dp[i] = dp[(i - 1) / 2] + dp[(i - 1) / 2 + 1];
            else
                dp[i] = dp[i / 2];
            cout << i << " " << dp[i] << "\n";
            maxVal = (maxVal > dp[i]) ? maxVal : dp[i];
        }
        return maxVal;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().getMaximumGenerated(n);
}