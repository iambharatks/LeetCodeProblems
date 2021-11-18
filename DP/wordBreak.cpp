#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_set<string> dict;
    int *dp;
    bool wordBreak(string &s, int i)
    {
        if (i >= s.size())
            return true;
        if (dp[i] != -1)
            return dp[i];
        for (int k = i; k < s.size(); k++)
        {
            if (dict.find(s.substr(i, k - i + 1)) != dict.end())
                if (wordBreak(s, k + 1))
                    return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string s : wordDict)
            dict.insert(s);
        dp = new int[s.size() + 1];
        for (int i = 0; i < s.size() + 1; i++)
            dp[i] = -1;
        return wordBreak(s, 0);
    }
};