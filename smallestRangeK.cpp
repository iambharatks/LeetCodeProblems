#include <bits/stdc++.h>

using namespace std;

// Smallest Range Covering Elements from K Lists

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        set<pair<int, pair<int, int>>> s;
        for (int i = 0; i < k; i++)
            s.insert({nums[i][0], {i, 1}});
        pair<int, int> ans = {0, 0};
        while (!s.empty() && s.rbegin()->first != INT_MAX)
        {
            pair<int, pair<int, int>> tmp = *(s.begin());
            int last = s.rbegin()->first;
            if (ans.first == 0 && ans.second == 0)
                ans = {tmp.first, last};
            else if (last - tmp.first < ans.second - ans.first)
                ans = {tmp.first, last};
            if (tmp.second.second < nums[tmp.second.first].size())
                tmp.first = nums[tmp.second.first][tmp.second.second];
            else
                tmp.first = INT_MAX;
            s.erase(s.begin());
            tmp.second.second += 1;
            s.insert(tmp);
        }
        vector<int> as = {ans.first, ans.second};
        return as;
    }
};