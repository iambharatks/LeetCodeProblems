#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        stack<int> s;
        int rem = nums.size() - k;
        for (int i : nums)
        {
            while (!s.empty() && rem && i < s.top())
                s.pop(), rem--;
            s.push(i);
        }
        while (s.size() != k)
            s.pop();
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    vector<int> v = Solution().mostCompetitive(nums, k);
    for (int i : v)
        cout << i << " ";
}