#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int setBits = 0;
        while (n)
        {
            if (n & 1)
                setBits++;
            n >>= 1;
        }
        return setBits;
    }
};
