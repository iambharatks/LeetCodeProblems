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
class SolutionBFS
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> d;
        for (string s : wordDict)
            d.insert(s);
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        int start;
        while (!q.empty())
        {
            start = q.front();
            q.pop();
            if (visited.find(start) == visited.end())
            {
                visited.insert(start);
                for (int i = start; i < s.size(); i++)
                {
                    if (d.find(s.substr(start, i - start + 1)) != d.end())
                    {
                        if (i >= s.size() - 1)
                            return true;
                        q.push(i + 1);
                    }
                }
            }
        }
        return false;
    }
};
class SolutionOptimised
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (string s : wordDict)
            dict.insert(s);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j])
                {
                    if (dict.find(s.substr(j, i - j)) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};