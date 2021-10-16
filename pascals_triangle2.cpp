#include <bits/stdc++.h>

using namespace std;

// 119. Pascal's Triangle II

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> preRow(1, 1);
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> curRow;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    curRow.push_back(1);
                else
                    curRow.push_back(preRow[j - 1] + preRow[j]);
            }
            preRow = curRow;
        }
        return preRow;
    }
};