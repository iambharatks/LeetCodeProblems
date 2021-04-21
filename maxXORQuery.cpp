#include <bits/stdc++.h>

using namespace std;

// Maximum XOR for Each Query

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int ai = 0;
        vector<int> ans;
        for (int i = 1; i < nums.size(); i++)
            nums[i] ^= nums[i - 1];
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ai = 0;
            cout << nums[i] << " ";
            for (int b = 0; b < maximumBit; b++)
                ai |= (((nums[i] & (1 << b)) == 0) ? 1 : 0) << b;
            ans.push_back(ai);
        }
        return ans;
    }
};
