#include <bits/stdc++.h>

using namespace std;

// Time Complexity : O(N)
//  Space Complexity : O(1)
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int maxE = INT_MIN, minE = INT_MAX, l = 0, r = 0;
        bool small = false, big = false;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
                small = true;
            if (small)
                minE = min(minE, nums[i]);
            if (nums[n - i] < nums[n - i - 1])
                big = true;
            if (big)
                maxE = max(maxE, nums[n - i - 1]);
        }
        for (int i = 0; i < n && (big || small); i++)
        {
            if (small && nums[i] > minE)
            {
                small = !small;
                l = i;
            }
            if (big && nums[n - i - 1] < maxE)
            {
                big = !big;
                r = n - i - 1;
            }
        }
        return (r <= l) ? 0 : r - l + 1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int l = n - 1, r = 0;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        return (r <= l) ? 0 : r - l + 1;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(1)
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> val(nums);
        sort(val.begin(), val.end());
        int l = 0, r = n - 1;
        while (l < r && nums[l] == val[l])
            l++;
        while (r > l && nums[r] == val[r])
            r--;
        return (r <= l) ? 0 : r - l + 1;
    }
};