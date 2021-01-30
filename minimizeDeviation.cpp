#include <bits/stdc++.h>

using namespace std;
//Time Complexity := O(n*logn)
//Space Complexity := O(n)
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> s;
        for (int i : nums)
        {
            if (i & 1)
                s.insert(i * 2);
            else
                s.insert(i);
        }
        int diff = *s.rbegin() - *s.begin();
        while (!s.empty() && ((*s.rbegin()) & 1) != 1)
        {
            int maxElement = *s.rbegin();
            s.erase(maxElement);
            s.insert(maxElement >> 1);
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        return diff;
    }
};
