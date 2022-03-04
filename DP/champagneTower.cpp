#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double dp[101][101];
    double champagneTower(int poured, int query_row, int query_glass)
    {
        dp[0][0] = poured;
        for (int i = 1; i < 101; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    if (dp[i - 1][j] > 1)
                        dp[i][j] = (dp[i - 1][j] - 1) / 2;
                }
                else
                {
                    if (dp[i - 1][j - 1] > 1)
                        dp[i][j] += (dp[i - 1][j - 1] - 1) / 2.0;
                    if (dp[i - 1][j] > 1)
                        dp[i][j] += (dp[i - 1][j] - 1) / 2.0;
                }
            }
        }
        return dp[query_row][query_glass] > 1 ? 1 : dp[query_row][query_glass];
    }
};