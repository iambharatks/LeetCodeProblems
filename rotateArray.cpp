#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverse(vector<int>::iterator left, vector<int>::iterator right)
    {
        while (left < right)
        {
            *left = *left + *right - (*right = *left);
            left++, right--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k - 1);
        reverse(nums.begin() + n - k, nums.end() - 1);
        reverse(nums.begin(), nums.end() - 1);
    }
};
int main()
{
    int n, k;
    cin >> n;
    vector<int> v(n, 0);
    for (int &i : v)
    {
        cin >> i;
    }
    cin >> k;
    Solution().rotate(v, k);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}