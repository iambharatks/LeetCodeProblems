#include <bits/stdc++.h>

using namespace std;
//   Number of Steps to Reduce a Number to Zero

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int n0 = 0, n1 = 0;
        while (num)
        {
            if (num & 1)
                n1++;
            else
                n0++;
            num >>= 1;
        }
        int ans = n0 + n1 + (n1 - 1);
        return (ans == -1) ? 0 : ans;
    }
};
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int c = 0;
        while (num)
        {
            c++;
            if (num & 1)
                num -= 1;
            else
                num >>= 1;
        }
        return c;
    }
};