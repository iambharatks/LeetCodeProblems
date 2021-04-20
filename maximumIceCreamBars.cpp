#include <bits/stdc++.h>

using namespace std;

//  Maximum Ice Cream Bars

class Solution
{
public:
    int lowerBound(vector<long long> costs, int target)
    {
        int low = 0, high = costs.size() - 1, mid = 0, ans = -1;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (costs[mid] <= target)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid;
        }
        return ans;
    }
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        vector<long long> pref(costs.size(), 0);
        pref[0] = costs[0];
        for (int i = 1; i < costs.size(); i++)
        {
            pref[i] = pref[i - 1] + costs[i];
        }
        if (pref.back() <= coins)
            return costs.size();
        int ans = lowerBound(pref, coins);
        return ans + 1;
    }
};
