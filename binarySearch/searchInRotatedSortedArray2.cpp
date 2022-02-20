#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &a, int target)
    {
        int l = 0, r = a.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] == target)
                return true;
            if (a[mid] == a[l] && a[mid] == a[r])
            {
                while (l <= r && a[l] == a[r])
                    l++, r--;
            }
            else if (a[l] <= a[mid])
            {
                if (a[l] <= target && a[mid] >= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {   
                if (a[mid] <= target && a[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};