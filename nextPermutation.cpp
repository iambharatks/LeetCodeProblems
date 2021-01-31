#include <bits/stdc++.h>

using namespace std;
//  Next Permutation

class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int n = a.size();
        int smallest = -1, largest = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > a[i - 1])
            {
                smallest = i - 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0 && smallest != -1; i--)
        {
            if (a[i] > a[smallest])
            {
                largest = i;
                break;
            }
        }
        if (smallest != -1)
            swap(a[smallest], a[largest]);
        reverse(a.begin() + smallest + 1, a.end());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    Solution().nextPermutation(nums);
    for (int &i : nums)
        cout << i << " ";
}