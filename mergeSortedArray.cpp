#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
        int gap = n + m;
        for (gap = (gap == 1) ? 0 : ((gap) / 2 + (gap & 1)); gap > 0; gap = (gap == 1) ? 0 : (gap) / 2 + (gap & 1))
        {
            for (int i = 0; i + gap < n + m; i++)
            {
                if (nums1[i] > nums1[i + gap])
                    swap(nums1[i], nums1[i + gap]);
            }
        }
    }
};