#include <bits/stdc++.h>

using namespace std;

//  Beautiful Arrangement II

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        int idx = 0;
        vector<int> ans(n);
        for (int i = 1; i <= n - k; i++)
            ans[idx++] = i;
        for (int i = 1; i <= k; i++)
        {
            if (i & 1)
                ans[idx++] = n - (i / 2);
            else
                ans[idx++] = n - k + (i / 2);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        int l = 1, r = k + 1, idx = 0;
        vector<int> ans(n);
        while (l <= r)
        {
            ans[idx++] = l++;
            if (l <= r)
                ans[idx++] = r--;
        }
        for (int i = k + 2; i <= n; i++)
            ans[idx++] = i;

        return ans;
    }
};