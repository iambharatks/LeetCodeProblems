//76. Minimum Window Substring
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size(), l = 0;
        int subStart = -1, minSize = INT_MAX;
        vector<int> mp(256);
        for (char ch : t)
            mp[ch]--;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            bool found = true;
            for (int i = 0; i < 256; i++)
            {
                if (mp[i] < 0)
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                while (mp[s[l]] > 0)
                {
                    mp[s[l]]--;
                    l++;
                }
                // cout<<l<<" "<<i-l+1<<" "<<minSize<<"\n";
                if (minSize > i - l + 1)
                {
                    minSize = i - l + 1;
                    subStart = l;
                }
            }
        }
        return (subStart == -1) ? "" : s.substr(subStart, minSize);
    }
};