#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int prev = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " " << prev << "\n";
            if (arr[i] != prev + 1)
            {
                if (k > arr[i] - (prev + 1))
                    k -= arr[i] - (prev + 1);
                else
                    return prev + k;
            }
            prev = arr[i];
        }
        return arr.back() + k;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << Solution().findKthPositive(arr, k);
}