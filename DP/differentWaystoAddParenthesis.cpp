#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> res;
    vector<int> dp[21][21];

    int operation(int &a, int &b, char &op)
    {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        return 0;
    }
    void solve(string &expression, int i, int j)
    {
        if (i > j)
            return;
        if (dp[i][j].size() != 0)
            return;
        int k = i;
        int val = 0;
        for (k = i; k <= j && expression[k] >= '0' && expression[k] <= '9'; k++)
        {
            val = val * 10 + expression[k] - '0';
        }
        if (k > j)
        {
            dp[i][j].push_back(val);
            return;
        }
        k = i;
        while (k < j)
        {
            while (expression[k] >= '0' && expression[k] <= '9')
            {
                k++;
            }
            solve(expression, i, k - 1);
            solve(expression, k + 1, j);

            for (int l : dp[i][k - 1])
            {
                for (int r : dp[k + 1][j])
                    dp[i][j].push_back(operation(l, r, expression[k]));
            }
            k++;
        }

        return;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        solve(expression, 0, expression.size() - 1);

        return dp[0][expression.size() - 1];
    }
};