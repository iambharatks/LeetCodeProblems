#include <bits/stdc++.h>

using namespace std;

//  Reverse String

class Solution
{
public:
    void swap(char &a, char &b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char> &s)
    {
        int i, n;
        n = s.size();
        for (i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
};