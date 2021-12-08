#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<pair<int, int>> a(26, {-1, -1});
        for (int i = 0; i < s.size(); i++)
        {
            if (a[s[i] - 'a'].first < 0)
                a[s[i] - 'a'].first = i + 1;
            a[s[i] - 'a'].second = i + 1;
        }
        sort(a.begin(), a.end());
        vector<int> res;
        int prev = -1;
        int prevSum = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i].first == -1)
                continue;
            else if (a[i].first != -1 && prev == -1)
                prev = a[i].second;
            else if (prev >= a[i].first)
                prev = max(prev, a[i].second);
            else
            {
                if (res.empty())
                    res.push_back(prev);
                else
                    res.push_back(prev - prevSum);
                prevSum += res.back();
                prev = a[i].second;
            }
        }
        if (res.empty())
        {
            res.push_back(prev);
        }
        else if (prev > prevSum)
        {
            res.push_back(prev - prevSum);
        }
        return res;
    }
};