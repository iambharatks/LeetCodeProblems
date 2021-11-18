#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        ll maxProd = 1, minProd = 1, ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minProd, maxProd);
            maxProd = max(maxProd * nums[i], (ll)nums[i]);
            minProd = min(minProd * nums[i], (ll)nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};