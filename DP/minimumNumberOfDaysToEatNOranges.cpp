#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> dp;
    int rec(int n)
    {
        if (n <= 2)
            return n;
        if (dp.count(n))
            return dp[n];
        return dp[n] = min(n % 2 + rec((n - n % 2) / 2), n % 3 + rec((n - (n % 3)) / 3)) + 1;
    }
    int minDays(int n)
    {
        return rec(n);
    }
};