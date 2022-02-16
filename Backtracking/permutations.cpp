#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void permuteUtil(int id, vector<int> &nums)
    {
        if (id == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = id; i < nums.size(); i++)
        {
            swap(nums[id], nums[i]);
            permuteUtil(id + 1, nums);
            swap(nums[id], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        permuteUtil(0, nums);
        return res;
    }
};