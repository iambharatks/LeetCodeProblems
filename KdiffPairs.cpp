#include <bits/stdc++.h>

using namespace std;

int findPairs(vector<int> &nums, int k)
{
    unordered_map<int, int> h;
    for (int num : nums)
    {
        h[num]++;
    }
    int count = 0;
    if (k != 0)
    {
        for (int num : nums)
        {
            if (h[num + k] > 0)
            {
                h[num + k] = 0;
                count++;
            }
        }
    }
    else
    {
        for (int num : nums)
        {
            if (h[num] > 1)
            {
                h[num] = 0;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int &i : v)
    {
        cin >> i;
    }
    cout << findPairs(v, k) << "\n";
    return 0;
}