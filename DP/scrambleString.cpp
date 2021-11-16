#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1 == s2)
            return true;
        int n = s1.size();
        for (int k = 1; k <= n - 1; k++)
        {
            string s2l = s2.substr(0, k);
            string s2r = s2.substr(k);
            if ((isScramble(s1.substr(0, k), s2l) && isScramble(s1.substr(k), s2r)) || (isScramble(s1.substr(n - k), s2l) && isScramble(s1.substr(0, n - k), s2r)))
                return true;
        }
        return false;
    }
};