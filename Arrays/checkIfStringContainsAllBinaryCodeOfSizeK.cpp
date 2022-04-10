#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, long long k)
    {
        long long num = 0, n = s.size();
        if (k >= n)
            return false;
        unordered_set<long long> st;
        for (int i = 0; i < k; i++)
        {
            num <<= 1;
            if (s[i] == '1')
                num += 1;
        }
        st.insert(num);
        long long n1 = 1 << k, n2 = 1 << (k - 1);
        for (int i = k; i < n; i++)
        {
            num %= n2;
            num <<= 1;
            if (s[i] == '1')
                num += 1;
            st.insert(num);
        }
        return st.size() == n1;
    }
};