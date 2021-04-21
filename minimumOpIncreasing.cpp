#include <bits/stdc++.h>

using namespace std;

//  Minimum Operations to Make the Array Increasing

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ops = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                ops += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ops;
    }
};
