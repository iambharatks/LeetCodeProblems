#include <bits/stdc++.h>

using namespace std;

//O(n)
class Solution1
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 2)
        {
            return 0;
        }
        int ans = 0;
        vector<int> leftHeight(n, 0);
        vector<int> rightHeight(n, 0);
        leftHeight[0] = height[0];
        rightHeight[n - 1] = height[n - 1];
        for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--)
        {
            leftHeight[i] = max(leftHeight[i - 1], leftHeight[i]);
            rightHeight[i] = max(rightHeight[i + 1], rightHeight[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans += min(leftHeight[i], rightHeight[i]) - height[i];
        }
        return ans;
    }
};
//O(n)
class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                (height[left] >= left_max) ? left_max = height[left] : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                (height[right] >= right_max) ? right_max = height[right] : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};