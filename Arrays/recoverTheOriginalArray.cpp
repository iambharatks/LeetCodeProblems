#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> Possible(vector<int> &nums, int k)
    {
        vector<int> ans;
        vector<bool> visited(nums.size());
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            int required = nums[i] + 2 * k;
            while (j < nums.size() && nums[j] != required)
                j++;
            if (j < nums.size())
            {
                visited[j] = 1;
                ans.push_back((nums[i] + nums[j]) / 2);
                j++;
            }
        }
        if (ans.size() == nums.size() / 2)
            return ans;
        else
            return {};
    }

public:
    vector<int> recoverArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[0] || (nums[i] - nums[0]) % 2)
                continue;
            vector<int> ans = Possible(nums, (nums[i] - nums[0]) / 2);
            if (!ans.empty())
                return ans;
        }
        return {};
    }
};
class Solution
{
public:
    vector<int> recoverArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_multiset<int> ms;
        for (int &i : nums)
            ms.insert(i);
        for (int i = 1; i < nums.size(); i++)
        {
            int k = nums[i] - nums[0];
            if (k == 0 || (k & 1))
                continue;
            k >>= 1;
            unordered_multiset<int> cp = ms;
            vector<int> res;
            for (int j = 0; j < nums.size(); j++)
            {
                auto it = cp.find(nums[j]);
                if (it == cp.end())
                    continue;
                auto it2 = cp.find(nums[j] + 2 * k);
                if (it2 == cp.end())
                    continue;
                cp.erase(it);
                cp.erase(it2);
                res.push_back(nums[j] + k);
            }
            if (cp.empty())
                return res;
        }
        return {};
    }
};