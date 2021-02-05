#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    //O(n)
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> hashMap;
        for (int i : nums)
            hashMap[i]++;
        int res = 0;
        for (int i : nums)
        {
            if (hashMap.find(i + 1) != hashMap.end())
                res = max(res, hashMap[i + 1]);
            if (hashMap.find(i - 1) != hashMap.end())
                res = max(res, hashMap[i - 1]);
        }
        return res;
    }
    //O(nlogn)
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int prev_cnt = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cnt = 1;
            if (i > 0 && nums[i] - nums[i - 1] == 1)
            {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                {
                    cnt++;
                    i++;
                }
                res = max(res, cnt + prev_cnt);
                prev_cnt = cnt;
            }
            else
            {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                {
                    cnt++;
                    i++;
                }
                prev_cnt = cnt;
            }
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
}