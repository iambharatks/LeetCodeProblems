#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int _max = INT_MIN;
        int s = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (s == -1)
            {
                s = arr[i];
            }
            else
            {
                if (s <= arr[i])
                {
                    _max = max(_max, arr[i] - s);
                }
                else
                {
                    s = arr[i];
                }
            }
        }
        _max = max(_max, 0);
        return _max;
    }
};