#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string s;

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        if (n == 0)
            ans.push_back("");
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (string s : generateParenthesis(i))
                {
                    for (string t : generateParenthesis(n - i - 1))
                        ans.push_back("(" + s + ")" + t);
                }
            }
        }
        return ans;
    }
};