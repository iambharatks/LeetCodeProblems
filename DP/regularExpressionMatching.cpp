#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int **dp;
    bool rec(string &s, string &p, int N, int M)
    {
        if (N == 0 && M == 0)
            return true;
        if (N == 0)
        {
            if (p[M - 1] == '*')
                return rec(s, p, N, M - 2);
            else
                return false;
        }
        if (M == 0 && N != 0)
            return false;
        if (dp[N][M] != -1)
            return dp[N][M];
        if (s[N - 1] == p[M - 1] || p[M - 1] == '.')
            return dp[N][M] = rec(s, p, N - 1, M - 1);

        if (p[M - 1] == '*')
        {
            if (p[M - 2] == s[N - 1] || p[M - 2] == '.')
                return dp[N][M] = rec(s, p, N, M - 2) || rec(s, p, N - 1, M);
            return dp[N][M] = rec(s, p, N, M - 2);
        }
        return dp[N][M] = false;
    }
    bool isMatch(string s, string p)
    {
        dp = new int *[s.size() + 1];
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i] = new int[p.size() + 1];
            for (int j = 0; j < p.size() + 1; j++)
            {
                dp[i][j] = -1;
            }
        }
        return rec(s, p, s.size(), p.size());
    }
    bool isMatchbu(string s, string p)
    {
        dp = new int *[s.size() + 1];
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i] = new int[p.size() + 1];
            for (int j = 0; j < p.size() + 1; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j <= p.size(); j++)
            {
                if (i == 0)
                {
                    if (j != 0 && p[j - 1] == '*')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = 0;
                }
                else if(j == 0 && i!= 0)
                    dp[i][j] = 0;
                else if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
                else
                    dp[i][j] = false;
            }
        }
    }
};