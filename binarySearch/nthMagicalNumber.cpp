#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b)
    {
        long r = 1l * min(a, b) * n;
        long l = 0;
        long lcm = 1l * a / __gcd(a, b) * b;
        while (l <= r)
        {
            long m = l + (r - l) / 2;
            long ni = m / a + m / b - m / (lcm);
            if (ni >= n)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l % mod;
    }
};