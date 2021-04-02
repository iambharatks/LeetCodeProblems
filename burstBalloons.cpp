#include <bits/stdc++.h>

using namespace std;

class recursion
{
public:
    int maxCoinsUtil(vector<int> nums, int i, int j)
    {
        if (i == j)
            return nums[i];
        int ans = maxCoinsUtil(nums, i, i) + maxCoinsUtil(nums, i + 1, j);
        for (int k = i; k < j; k++)
        {
            int tmp = maxCoinsUtil(nums,i,k) + maxCoinsUtil(nums,k+1,j) + nums[i-1]
        }
    }
    int maxCoins(vector<int> &nums)
    { 
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
}