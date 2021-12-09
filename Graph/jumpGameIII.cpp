#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (arr[v] == 0)
                return true;
            if (v - arr[v] >= 0 && vis.find(v - arr[v]) == vis.end())
            {
                vis.insert(v - arr[v]);
                q.push(v - arr[v]);
            }
            if (v + arr[v] < arr.size() && vis.find(v + arr[v]) == vis.end())
            {
                vis.insert(v + arr[v]);
                q.push(v + arr[v]);
            }
        }
        return false;
    }
};