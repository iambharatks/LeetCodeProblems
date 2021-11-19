#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_set<string> dict;
    vector<string> ans;
    void solve(string &s, int i, string res)
    {
        if (i >= s.size())
        {
            res.pop_back();
            ans.push_back(res);
            return;
        }
        string tmp = res;
        for (int k = i; k < s.size(); k++)
        {

            if (dict.find(s.substr(i, k - i + 1)) != dict.end())
            {
                tmp.append(s.substr(i, k - i + 1));
                tmp.push_back(' ');
                cout << tmp << ' ';
                solve(s, k + 1, tmp);
                tmp = res;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string str : wordDict)
            dict.insert(str);
        solve(s, 0, "");
        return ans;
    }
};