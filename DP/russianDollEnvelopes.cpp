#include <bits/stdc++.h>

using namespace std;

// Simple Dynamic Approach:
// Time Complexity: O(N*N)
// Space Complexity: O(N)
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int res = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        dp[0] = 1;
        for (int i = 1; i < envelopes.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Dynamic Programming + Binary Searching
// Time Complexity : O(N*logN)
// Space Complexity : O(N)
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        vector<int> lis;
        sort(envelopes.begin(), envelopes.end(), cmp);
        for (int i = 0; i < envelopes.size(); i++)
        {
            int l = 0, r = lis.size() - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (envelopes[i][1] > envelopes[lis[m]][1])
                    l = m + 1;
                else
                    r = m - 1;
            }
            if (l == lis.size())
            {
                lis.push_back(i);
            }
            else
            {
                lis[l] = i;
            }
        }
        return lis.size();
    }
};