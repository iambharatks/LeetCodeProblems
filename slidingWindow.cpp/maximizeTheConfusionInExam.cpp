#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isTrue(char c) { return (c == 'T') ? 1 : 0; }
    int maxConsecutiveAnswers(string s, int k)
    {
        int count[2] = {0}, maxSub = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count[isTrue(s[i])]++;
            maxSub = max(maxSub, count[isTrue(s[i])]);
            if (res - maxSub < k)
                res++;
            else
                count[isTrue(s[i - res])]--;
        }
        return res;
    }
};