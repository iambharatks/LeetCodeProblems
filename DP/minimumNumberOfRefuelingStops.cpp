#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long res(int pos, int target, int i, int fuel, vector<vector<int>> &stations)
    {
        if (pos >= target)
            return 0;
        if (fuel <= 0 || i >= stations.size())
            return INT_MAX;
        return min(res(pos + stations[i][0], target, i + 1, fuel - stations[i][1], stations) + 1, res(pos + stations[i][0], target, i + 1, fuel, stations));
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        return res(0, target, 0, startFuel, stations);
    }
};