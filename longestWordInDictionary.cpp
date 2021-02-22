#include <bits/stdc++.h>

using namespace std;

//   Longest Word in Dictionary through Deleting

class Solution
{
public:
    bool compare(string s1, string s2)
    {
        if (s1.size() < s2.size())
            return false;
        size_t i = 0, j = 0;
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] == s2[j])
                ++i, ++j;
            else
                ++i;
        }
        return (j == s2.size());
    }
    string findLongestWord(string s, vector<string> &d)
    {
        string ans = "";
        for (string pat : d)
        {
            if (compare(s, pat) && pat.size() >= ans.size())
            {
                if ((pat.size() != ans.size()) || (pat.size() == ans.size() && pat < ans))
                    ans = pat;
            }
        }
        return ans;
    }
};