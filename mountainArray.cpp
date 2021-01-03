#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int i = 0, n = arr.size();
        if (n < 3)
            return false;
        for (i = 0; i < n - 1; i++)
            if (arr[i] >= arr[i + 1])
                break;
        if (i == 0 || i == n - 1)
            return false;
        for (; i < n - 1; i++)
            if (arr[i] <= arr[i + 1])
                break;
        return (i == (n - 1));
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << Solution().validMountainArray(arr);
}