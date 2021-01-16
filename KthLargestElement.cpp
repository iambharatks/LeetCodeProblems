#include <bits/stdc++.h>

using namespace std;

// Kth Largest Element in an Array
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    cout << Solution().findKthLargest(nums, k) << " ";
}
