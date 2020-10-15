#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> arr(101, 0);
        unordered_map<int, stack<int>> hsh;
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
            hsh[nums[i]].push(i);
        }
        int sum = 0;
        for (int i = 100; i >= 0; i--)
        {
            sum += arr[i];
        }
        for (int i = 100; i >= 0; i--)
        {
            if (arr[i])
            {
                sum -= arr[i];
                while (!hsh[i].empty())
                {
                    nums[hsh[i].top()] = sum;
                    hsh[i].pop();
                }
            }
        }
        return nums;
    }
};
// #include <bits/stdc++.h>

// using namespace std;

// class Solution
// {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> temp(nums);
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++)
//         {
//             temp[i] = lower_bound(nums.begin(), nums.end(), temp[i]) - nums.begin();
//         }
//         return temp;
//     }
// };

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Solution solve;
    A = solve.smallerNumbersThanCurrent(A);
    for (int i : A)
        cout << i << " ";
    return 0;
}