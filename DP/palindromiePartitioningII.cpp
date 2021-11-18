#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int **dp;
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int minCut(string &s, int i, int j)
    {
        // Base case
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (isPalindrome(s, i, j))
            return 0;

        int mn = INT_MAX;
        // Breaking points
        for (int k = i; k < j; k++)
        {
            int tmp;
            if (isPalindrome(s, i, k))
            {
                tmp = minCut(s, k + 1, j) + 1;
                mn = min(tmp, mn);
            }
        }
        return dp[i][j] = mn;
    }

    int minCut(string &s)
    {
        dp = new int *[s.size()];
        for (int i = 0; i < s.size(); i++)
        {
            dp[i] = new int[s.size()];
            for (int j = 0; j < s.size(); j++)
            {
                dp[i][j] = -1;
            }
        }
        return minCut(s, 0, s.size() - 1);
    }
};
class Solution1
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> cut(n + 1);
        for (int i = 0; i <= n; i++)
            cut[i] = i - 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; (i - j) >= 0 && (i + j) < n && s[i + j] == s[i - j]; j++)
            {
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j] + 1);
            }
            for (int j = 0; (i - j - 1) >= 0 && (i + j) < n && s[i + j] == s[i - j - 1]; j++)
            {
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j - 1] + 1);
            }
        }
        return cut[n];
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().minCut(s) << '\n';
}