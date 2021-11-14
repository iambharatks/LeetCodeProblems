#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i-1][j] + ((s[i-1]==t[j-1])?dp[i-1][j-1]:0);
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    cout << Solution().numDistinct(s, t) << '\n';
}