#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int &candidate : candidates)
        {
            for (int tot = candidate; tot <= target; tot++)
            {
                for (auto v : dp[tot - candidate])
                {
                    v.push_back(candidate);
                    dp[tot].push_back(v);
                }
            }
        }
        return dp[target];
    }
};
class Solution
{
public:
    vector<vector<int>> res;
    void rec(vector<int> &candidates, int N, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            if (!temp.empty())
                res.push_back(temp);
            return;
        }
        if (N == 0)
            return;
        if (candidates[N - 1] <= target)
        {
            temp.push_back(candidates[N - 1]);
            rec(candidates, N, target - candidates[N - 1], temp);
            temp.pop_back();
        }
        rec(candidates, N - 1, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        rec(candidates, candidates.size(), target, temp);
        return res;
    }
};