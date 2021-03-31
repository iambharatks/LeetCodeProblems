#include <bits/stdc++.h>

using namespace std;

// Coin Change 2
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
class memoization
{
public:
    long long int changeUtil(int amount, vector<int> &coins, int m, vector<vector<long long int>> &table)
    {
        //Base Case
        // cout << n << " " << m << "\n";
        if (amount == 0)
            return 1;
        if (amount < 0 || m <= 0)
            return 0;
        if (table[amount][m - 1] != -1)
            return table[amount][m - 1];
        long long int left = changeUtil(amount, coins, m - 1, table);
        long long int right = changeUtil(amount - coins[m - 1], coins, m, table);
        return (table[amount][m - 1] = left + right);
    }
    long long int change(int amount, vector<int> &coins)
    {
        vector<vector<long long int>> table(amount + 1, vector<long long int>(coins.size(), -1));
        return changeUtil(amount, coins, coins.size(), table);
    }
};