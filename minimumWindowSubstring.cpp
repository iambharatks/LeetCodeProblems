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

class OptimisedSoln
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        // if (s == t)
        //     return s;
        vector<pair<int, char>> filteredS;
        vector<int> mp(256);
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]--;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < 0)
                filteredS.push_back({i, s[i]});
        }
        if (filteredS.size() == 0)
            return "";
        int l = -1, ans = s.size()+2, start = -1;
        for (int i = 0; i < filteredS.size(); i++)
        {
            mp[filteredS[i].second]++;
            if (l == -1)
                l = filteredS[i].first;
            cout << filteredS[i].first << " " << filteredS[i].second << '\n';
            bool fullfilled = true;
            for (int j = 0; j < 256; j++)
            {
                if (mp[j] < 0)
                {
                    fullfilled = false;
                    break;
                }
            }
            if (fullfilled)
            {
                while (mp[filteredS[l].second] > 0)
                {
                    // cout << (filteredS[l].second) << ' ';
                    mp[filteredS[l].second]--;
                    l++;
                }
                if (ans > filteredS[i].first - filteredS[l].first + 1)
                {
                    ans = filteredS[i].first - filteredS[l].first + 1;
                    start = filteredS[l].first;
                }
            }
        }
        // cout << start << " " << ans;
        return (ans == -1) ? "" : s.substr(start, ans);
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    cout << OptimisedSoln().minWindow(s, t);
}