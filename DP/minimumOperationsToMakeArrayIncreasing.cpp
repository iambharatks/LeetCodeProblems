#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kIncreasing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            vector<int> lis;
            for (int j = i; j < n; j += k)
            {
                if (lis.empty() || lis.back() <= arr[j])
                    lis.push_back(arr[j]);
                else
                    *upper_bound(lis.begin(), lis.end(), arr[j]) = arr[j];
            }
            res -= lis.size();
        }
        return res + n;
    }
};