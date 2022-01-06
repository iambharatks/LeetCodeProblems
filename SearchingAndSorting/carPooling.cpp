#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> enter(trips.size()), leave(trips.size());
        for (int i = 0; i < trips.size(); i++)
        {
            enter[i] = {trips[i][1], i};
            leave[i] = {trips[i][2], i};
        }
        int i = 0, j = 0, n = trips.size();
        int curCap = 0;
        sort(enter.begin(), enter.end());
        sort(leave.begin(), leave.end());
        while (i < n && j < n)
        {
            if (enter[i].first < leave[j].first)
            {
                curCap += trips[enter[i].second][0];
                i++;
            }
            else
            {
                curCap -= trips[leave[j].second][0];
                j++;
            }
            if (curCap > capacity)
                return false;
        }
        while (j < n)
            curCap -= trips[leave[j++].second][0];
        return curCap <= capacity;
    }
};
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> stops(1001, 0);
        for (vector<int> &trip : trips)
        {
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }
        int curCapacity = 0;
        for (int &i : stops)
        {
            curCapacity += i;
            if (curCapacity > capacity)
                return false;
        }
        return true;
    }
};