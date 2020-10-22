#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        int arr[101] = {0};
        int n = 0;
        for (int i : index)
        {
            arr[i]++;
            n++;
        }
        vector<int> ans(n, 0);
        for (int i = 1; i <= 100; i++)
        {
            arr[i] += arr[i - 1];
        }
        int j = 0;
        for (int i : index)
        {
            arr[i]--;
            ans[arr[i]] = nums[j++];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0), index(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int &i : index)
    {
        cin >> i;
    }
    vector<int> v = Solution().createTargetArray(nums, index);
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}