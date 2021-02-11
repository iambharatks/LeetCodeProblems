#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int f1[256] = {0};
        int f2[256] = {0};
        if (s.size() != t.size())
            return false;
        for (size_t i = 0; i < s.size(); i++)
        {
            f1[s[i]]++;
            f2[t[i]]++;
        }
        for (int i = 0; i < 256; i++)
            if (f1[i] != f2[i])
                return false;
        return true;
    }
};
