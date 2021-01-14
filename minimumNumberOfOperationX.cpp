#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int sum = 0;
        int operations = 0, minOps = INT_MAX;
        while (right >= 0 && sum < x)
        {
            sum += nums[right--];
            operations++;
        }
        if (sum == x)
            minOps = min(operations, minOps);
        if (sum == x && right == -1)
            return minOps;
        right++;
        for (; right <= n - 1; right++)
        {
            sum -= nums[right];
            operations--;
            while (left < right && sum < x)
            {
                sum += nums[left++];
                operations++;
            }
            if (sum == x && operations < minOps)
                minOps = operations;
        }
        minOps = (minOps == INT_MAX) ? -1 : minOps;
        return minOps;
    }
};

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    cout << Solution().minOperations(nums, x);
}