#include <bits/stdc++.h>

using namespace std;
//  Valid Anagram
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int freq[256] = {0};
        if (s.size() != t.size())
            return false;
        for (size_t i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for (int i = 0; i < 256; i++)
            if (freq[i])
                return false;
        return true;
    }
};
