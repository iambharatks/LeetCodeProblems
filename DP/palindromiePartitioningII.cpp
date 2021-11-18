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
class Solution
{

public:
    int minCut(string s)
    {

        int N = s.size();
        if (N <= 1)
            return 0;

        int cuts[N + 1];

        for (int i = 0; i <= N; i++)
            cuts[i] = i - 1;

        for (int i = 1; i < N; i++)
        {

            // odd length
            for (int j = 0; (i - j) >= 0 && (i + j) < N && s[i - j] == s[i + j]; j++)
                cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j] + 1);

            // even length
            for (int j = 0; (i - j - 1) >= 0 && (i + j) < N && s[i - j - 1] == s[i + j]; j++)
                cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j - 1] + 1);
        }

        return cuts[N];
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().minCut(s) << '\n';
}