#include <bits/stdc++.h>

using namespace std;

// 118. Pascal's Triangle

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (i == 0)
                {
                    ans[i].push_back(1);
                    continue;
                }
                if (j == 0 || j == i)
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
        }
        return ans;
    }
};