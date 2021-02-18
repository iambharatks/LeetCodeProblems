#include <bits/stdc++.h>

using namespace std;

//   Container With Most Water

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        pair<int, int> boundary;
        int maxCapacity = 0, minHeight, curCapacity;
        while (left < right)
        {
            minHeight = (height[left] < height[right]) ? height[left] : height[right];
            curCapacity = (right - left) * minHeight;
            if (curCapacity > maxCapacity)
            {
                boundary = {left, right};
                maxCapacity = curCapacity;
            }
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        return maxCapacity;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int &h : height)
        cin >> h;
    cout << Solution().maxArea(height);
}