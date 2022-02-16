#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<bool> vis(isConnected.size(), 0);
        int provinces = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (vis[i])
                continue;
            provinces++;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty())
            {
                int start = q.front();
                q.pop();
                for (int j = 0; j < isConnected[start].size(); j++)
                {
                    if (isConnected[start][j] && !vis[j])
                    {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return provinces;
    }
};