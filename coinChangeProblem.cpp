#include <bits/stdc++.h>

using namespace std;

// Coin Change

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != -1)
                    dp[i] = min(dp[i], (dp[i - coin] + 1));
            }
            if (dp[i] == INT_MAX)
                dp[i] = -1;
            cout << i << " = " << dp[i] << "\n";
        }
        return dp[amount];
    }
};

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int &coin : coins)
        cin >> coin;
    cout << Solution().coinChange(coins, amount);
}