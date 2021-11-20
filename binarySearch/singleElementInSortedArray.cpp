#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int xOr = 0;
        for (int i : nums)
            xOr ^= i;
        return xOr;
    }
};

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid > 0 && mid < nums.size() - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid == nums.size() - 1 && nums[mid] != nums[mid - 1])
                return nums[mid];
            if (mid == 0 && nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid & 1)
            {
                if (mid > 0 && nums[mid] == nums[mid - 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};