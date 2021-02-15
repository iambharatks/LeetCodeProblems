#include <bits/stdc++.h>

using namespace std;
//  Happy Number

class Solution
{
public:
    unsigned sumOfDigits(unsigned long long n)
    {
        unsigned long long sum = 0;
        while (n)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(unsigned long long n)
    {
        while (n > 10)
        {
            n = sumOfDigits(n);
        }
        return (n == 1 || n == 7 || n == 10);
    }
};