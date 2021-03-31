#include <bits/stdc++.h>

using namespace std;
#define M 1000000009
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int freq[101] = {0};
        for (int i : arr)
            freq[i]++;
        int sum = 0;
        for (int i = 1; i <= 100; ++i)
        {
            long long current = 0;
            if (target - i > 0)
                for (int j = i; j <= 100; j++)
                {
                    if (target - i - j >= j)
                    {
                        if (i == j == (target - i - j))
                            current = (freq[i] * freq[j] * freq[target - i - j])
                        else if (i == j || target - i - j == j || target - i - j == i)
                            current = (freq[i] * freq[j] * freq[target - i - j]) / 2;
                        cout << i << " " << j << " " << target - i - j << "\n";
                    }
                }
        }
        return sum;
    }
};

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n, 0);
    for (int &i : arr)
        cin >> i;
    cout << Solution().threeSumMulti(arr, target);
}