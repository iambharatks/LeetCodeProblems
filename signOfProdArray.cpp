#include <bits/stdc++.h>

using namespace std;

// Sign of the Product of an Array

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int isNeg = 0, isZero = 0;
        for (int n : nums)
        {
            if (n < 0)
                isNeg++;
            if (n == 0)
            {
                isZero = 1;
                break;
            }
        }
        return (isZero) ? 0 : ((isNeg & 1) ? -1 : +1);
    }
};
