#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, no_of_operations = 0;
        while (left < right)
        {
            cout << nums[left] << " " << nums[right] << "\n";
            if (nums[left] + nums[right] == k)
                left++, right--, no_of_operations++;
            else if (nums[left] + nums[right] < k)
                left++;
            else
                right--;
        }
        return no_of_operations;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    cout << Solution().maxOperations(nums, k);
}