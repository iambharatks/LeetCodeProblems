#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] >= b[1];
    }
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] <= end)
            {
                continue;
            }
            else
            {
                cnt++;
                end = max(end, intervals[i][1]);
            }
        }
        return cnt;
    }
};