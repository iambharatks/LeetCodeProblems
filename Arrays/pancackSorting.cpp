#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res, index(n + 1, 0), val(n, 0);
        for (int i = 0; i < n; i++)
        {
            index[arr[i]] = i;
            val[i] = arr[i];
        }
        for (int i = n; i >= 2; i--)
        {
            if (index[i] == i - 1)
            {
                continue;
            }
            else
            {
                if (index[i] != 0)
                {
                    res.push_back(index[i] + 1);
                    int l = 0, r = index[i];
                    while (l < r)
                    {
                        swap(val[l], val[r]);
                        index[val[l]] = l;
                        index[val[r]] = r;
                        l++, r--;
                    }
                }
                res.push_back(i);
                int l = 0, r = i - 1;
                while (l < r)
                {
                    swap(val[l], val[r]);
                    index[val[l]] = l;
                    index[val[r]] = r;
                    l++, r--;
                }
            }
        }
        return res;
    }
};