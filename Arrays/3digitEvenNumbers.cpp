#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        unordered_set<int> st;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (k == j || k == i || digits[i] == 0)
                        continue;
                    if ((digits[k] & 1) == 0)
                        st.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        for (auto p : st)
            res.push_back(p);
        sort(res.begin(), res.end());
        return res;
    }
};