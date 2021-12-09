#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool vis[50001] = {0};
    bool canReach(vector<int> &arr, int start)
    {
       if (arr[start] == 0)
            return true;
        if (vis[start])
            return false;
        else
            vis[start] = true;
        return (start- arr[start] >= 0 && canReach(arr, start - arr[start])) || (start + arr[start] < arr.size() && canReach(arr, start + arr[start]));
    }
};
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        queue<int> q;
        q.push(start);
        bool vis[arr.size()];
        memset(vis, 0, sizeof(vis));
        vis[start] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (arr[v] == 0)
                return true;
            if (v - arr[v] >= 0 && vis[v - arr[v]] == 0)
            {
                vis[v - arr[v]] = 1;
                q.push(v - arr[v]);
            }
            if (v + arr[v] < arr.size() && vis[v + arr[v]] == 0)
            {
                vis[v + arr[v]] = 1;
                q.push(v + arr[v]);
            }
        }
        return false;
    }
};