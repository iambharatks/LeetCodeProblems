#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int res = 0, cur = 2, n = nums.size();
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                cur++;
            else
            {
                res += (cur - 2) * (cur - 1) / 2;
                cur = 2;
            }
        }
        res += (cur - 2) * (cur - 1) / 2;

        return res;
    }
};