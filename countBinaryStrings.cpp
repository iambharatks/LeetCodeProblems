#include <bits/stdc++.h>

using namespace std;

//  Count Binary Substrings

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev = 0, cur = 1, ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
                cur++;
            else
            {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
        }
        ans += min(prev, cur);
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().countBinarySubstrings(s);
}