#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        vector<pair<int, int>> freq(50000, {0, 0});
        int maxSize = 0, subSize = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]].first++;
            freq[nums[i]].second = i;
            maxSize = max(maxSize, freq[nums[i]].first);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (freq[num].second != -1 && maxSize == freq[num].first)
            {
                subSize = min(subSize, freq[num].second - i + 1);
                freq[num].second = -1;
            }
        }
        return subSize;
    }
};