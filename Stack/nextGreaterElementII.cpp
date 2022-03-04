#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> s;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.empty() || nums[s.top()] >= nums[i])
                s.push(i);
            else
            {
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    res[s.top()] = nums[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        for (int i = 0; i < nums.size() && !s.empty(); i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                res[s.top()] = nums[i];
                s.pop();
            }
        }
        return res;
    }
};