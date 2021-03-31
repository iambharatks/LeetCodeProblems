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
class memoization
{

public:
    int coinChangeUtil(vector<int> &coins, int n, int amount, vector<vector<int>> &table)
    {
        if (amount == 0)
            return 0;
        if (n <= 0)
            return INT_MAX;
        if (table[n - 1][amount] != -1)
            return table[n - 1][amount];
        if (amount >= coins[n - 1])
        {
            int including = coinChangeUtil(coins, n, amount - coins[n - 1], table);
            int excluding = coinChangeUtil(coins, n - 1, amount, table);
            table[n - 1][amount] = min(((including == INT_MAX) ? INT_MAX : including + 1), excluding);
        }
        else
            table[n - 1][amount] = coinChangeUtil(coins, n - 1, amount, table);
        cout << coins[n - 1] << " " << amount << " = " << table[n - 1][amount] << "\n";
        return table[n - 1][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> table(coins.size(), vector<int>(amount + 1, -1));
        return (coinChangeUtil(coins, coins.size(), amount, table) == INT_MAX) ? -1 : table[coins.size() - 1][amount];
    }
};
class BFS
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        unordered_set<int> qset;
        queue<pair<int, int>> q;
        qset.insert(amount);
        //{coins,amount}
        q.push({0, amount});
        while (!q.empty())
        {
            int numCoins = q.front().first;
            int remaining = q.front().second;
            q.pop();
            if (remaining == 0)
                return numCoins;
            if (remaining < 0)
                continue;
            for (int coin : coins)
            {
                int x = remaining - coin;
                if (x < 0)
                    continue;
                if (qset.find(x) == qset.end())
                {
                    q.push({numCoins + 1, x});
                    qset.insert(x);
                }
            }
        }
        return -1;
    }
};
int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int &coin : coins)
        cin >> coin;
    cout << memoization().coinChange(coins, amount);
}