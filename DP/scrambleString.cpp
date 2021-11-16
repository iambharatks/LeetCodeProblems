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
// 99%
class SolutionOptimal
{
public:
    int dp[31][31][31];
    bool isScramble(string &s1, string &s2, int l1, int l2, int len)
    {
        if (s1.size() != s2.size())
            return false;
        if (dp[l1][l2][len] != -1)
            return dp[l1][l2][len];
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));

        bool isSame = true;
        for (int i = 0; i < len; i++)
        {
            if (s1[i + l1] != s2[i + l2])
                isSame = false;
            cnt[s1[i + l1] - 'a']++;
            cnt[s2[i + l2] - 'a']--;
        }
        if (isSame)
            return dp[l1][l2][len] = true;

        for (int i = 0; i < 26; i++)
            if (cnt[i])
                return dp[l1][l2][len] = false;

        for (int k = 1; k < len; k++)
        {

            if (isScramble(s1, s2, l1, l2, k) && isScramble(s1, s2, l1 + k, l2 + k, len - k) || (isScramble(s1, s2, l1, l2 + len - k, k) && isScramble(s1, s2, l1 + k, l2, len - k)))
                return dp[l1][l2][len] = true;
        }
        return dp[l1][l2][len] = false;
    }
    bool isScramble(string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        if (s1.size() != s2.size())
            return false;
        return isScramble(s1, s2, 0, 0, s1.size());
    }
};