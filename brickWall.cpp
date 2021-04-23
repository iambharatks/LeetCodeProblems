#include <bits/stdc++.h>

using namespace std;

//   Brick Wall

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        int width = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < wall.size(); i++)
        {
            width = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                width += wall[i][j];
                mp[width] += 1;
                ans = max(ans, mp[width]);
            }
        }
        return wall.size() - ans;
    }
};

int main()
{
    int n, m;
    cin >> n;
    vector<vector<int>> wall(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        wall[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> wall[i][j];
    }
    cout << Solution().leastBricks(wall);
}