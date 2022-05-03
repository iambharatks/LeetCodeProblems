#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int index(char c)
    {
        return (c >= 'A' && c <= 'Z') ? c - 'A' + 26 : c - 'a';
    }
    int longestPalindrome(string s)
    {
        vector<int> a(52);
        for (char c : s)
            a[index(c)]++;
        bool mid = false;
        int res = 0;
        for (int i = 0; i < 52; i++)
        {
            res += a[i] - (a[i] & 1);
            if (!mid)
                mid = a[i] & 1;
        }
        return res + mid;
    }
};