#include <bits/stdc++.h>

using namespace std;

//  Unique Paths

class recursion
{
public:
    int uniquePaths(int m, int n)
    {
        if (n == 1 || m == 1)
            return 1;
        if (n < 1 || m < 1)
            return 0;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};
//Dynamic Programming
//Time Complexity:= O(m*n)
//Space Complexity:= O(m*n)
class tabulation
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//Math Solution
//Time Complexity:= O(m+n)
//Space Complexity:= O(m+n)
class OptimizedDP
{
    vector<long long> factorial;

public:
    void preCompute(int N)
    {
        factorial.resize(N, 1);
        for (int i = 1; i < N; i++)
            factorial[i] = factorial[i - 1] * i;
    }
    int uniquePaths(int m, int n)
    {
        preCompute(m + n);
        return factorial[m + n - 2] / factorial[m - 1] / factorial[n - 1];
    }
};
class PascalTriangle
{
public:
    int comb(int n, int k)
    {
        long long r = 1;
        for (int d = 1; d <= k; d++)
            r = r * (n--) / d;
        return r;
    }
    int uniquePaths(int m, int n)
    {
        return comb(m + n - 2, min(m, n) - 1);
    }
};
class Optimimum
{
public:
    int uniquePaths(int m, int n)
    {
        long k = min(m, n) - 1, r = 1;
        n = m + n - 2;
        for (long d = 1; d <= k; d++)
            r = r * (n--) / d;
        return r;
    }
};
int main()
{
    int n, m;
    cin >> m >> n;
    cout << PascalTriangle().uniquePaths(m, n);
}