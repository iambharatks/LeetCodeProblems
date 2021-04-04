#include <bits/stdc++.h>

using namespace std;
//  Longest Valid Parentheses
class BruteForce
{
public:
    bool isValid(string s, int i, int j)
    {
        stack<char> brack;
        for (int k = i; k < j; k++)
        {
            if (s[k] == '(')
                brack.push('(');
            else
            {
                if (!brack.empty() && brack.top() == '(')
                    brack.pop();
                else
                    return false;
            }
        }
        return (brack.empty()) ? true : false;
    }
    int longestValidParentheses(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                for (int L = 2; L <= s.size() - i; L += 2)
                {
                    if (s[i + L - 1] == ')')
                    {
                        // cout << s.substr(i, L) << "\n";
                        if (isValid(s, i, i + L))
                            ans = (ans < L) ? L : ans;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '(')
                dp[i] = 0;
            else if (s[i] == ')' && s[i - 1] == '(')
                dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
            else if (s[i] == ')' && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().longestValidParentheses(s);
}