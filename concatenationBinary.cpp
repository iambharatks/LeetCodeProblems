#include <bits/stdc++.h>

using namespace std;

//   Concatenation of Consecutive Binary Numbers

class Solution
{
public:
    long long numberOfBits(long long n)
    {
        long long bitCnt = 0;
        while (n)
        {
            n >>= 1;
            bitCnt++;
        }
        return bitCnt;
    }
    int concatenatedBinary(int n)
    {
        long long ans = 0;
        const long long M = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
        {
            long long bitCnt = numberOfBits(i);
            ans = ((ans << bitCnt) + i) % M;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Solution().concatenatedBinary(n) << "\n";
    }
}