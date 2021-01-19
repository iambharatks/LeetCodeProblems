#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string naiveApproach(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        int len = 0;
        string ans;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= n - i; ++j)
            {
                string t1 = s.substr(i, j);
                string t2 = rev.substr(n - j - i, j);
                cout << t1 << " " << t2 << "\n";
                if (t1 == t2 && len < j)
                {
                    len = j;
                    ans = t1;
                }
            }
        }
        return ans;
    }
    string longestPalindrome(string s)
    {
        pair<int, int> index;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int left = i, right = i + 1;
            while (left >= 0 && right < n)
            {
                if (s[left] != s[right])
                {
                    if (index.second - index.first < right - left - 2)
                        index = {left + 1, right - 1};
                    break;
                }
                left--, right++;
                if (left < 0 || right >= n)
                    if (index.second - index.first < right - left - 2)
                        index = {left + 1, right - 1};
            }
            left = i, right = i;
            while (left >= 0 && right < n)
            {
                if (s[left] != s[right])
                {
                    if (index.second - index.first < right - left - 2)
                        index = {left + 1, right - 1};
                    break;
                }
                left--, right++;
                if (left < 0 || right >= n)
                    if (index.second - index.first < right - left - 2)
                        index = {left + 1, right - 1};
            }
        }
        return s.substr(index.first, index.second - index.first + 1);
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s);
}