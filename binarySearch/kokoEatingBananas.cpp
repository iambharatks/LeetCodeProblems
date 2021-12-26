#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    typedef long long ll;
    bool isPossible(vector<int> &piles, int h, int k)
    {
        for (int &i : piles)
        {
            if (h >= ceil(1.0 * i / k))
            {
                h -= ceil(1.0 * i / k);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        ll l = 0, r = 0;
        for (int &i : piles)
            r += i;
        ll res = 0;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (isPossible(piles, h, mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};