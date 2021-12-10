#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    const int mod = 1e9 + 7;
    int findState(bool t1, bool t2)
    {
        int state = 0;
        if (t1)
            state |= 1;
        if (t2)
            state |= 2;
        return state;
    }
    int numTilings(int &n, int i, int t1 = true, int t2 = true)
    {
        if (i == n)
            return 1;

        int state = findState(t1, t2);

        if (dp[i][state] != -1)
            return dp[i][state];

        bool t3 = i + 1 < n;
        bool t4 = i + 1 < n;

        long long count = 0;
        if (t1 && t2 && t3)
            count += numTilings(n, i + 1, false, true);
        if (t1 && t2 && t4)
            count += numTilings(n, i + 1, true, false);
        if (t1 && !t2 && t3 && t4)
            count += numTilings(n, i + 1, false, false);
        if (!t1 && t2 && t3 && t4)
            count += numTilings(n, i + 1, false, false);
        if (t1 && t2 && t3 && t4)
            count += numTilings(n, i + 1, false, false);
        if (t1 && t2)
            count += numTilings(n, i + 1, true, true);
        if (!t1 && !t2)
            count += numTilings(n, i + 1, true, true);
        if (t1 && !t2 && t3)
            count += numTilings(n, i + 1, false, true);
        if (!t1 && t2 && t4)
            count += numTilings(n, i + 1, true, false);
        return dp[i][state] = count % mod;
    }
    int numTilings(int n)
    {
        dp.resize(n + 1, vector<int>(4, -1));
        return numTilings(n, 0);
    }
};