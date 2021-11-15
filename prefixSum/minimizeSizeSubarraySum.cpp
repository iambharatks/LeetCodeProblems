#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minSize = INT_MAX;
        int sum = 0;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[l++];
                }
                minSize = min(minSize, i - l + 2);
            }
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};