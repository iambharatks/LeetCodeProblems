#include <bits/stdc++.h>

using namespace std;

//   Letter Combinations of a Phone Number


class Solution
{
public:
    void preCompute(vector<vector<char>> &a)
    {
        char c = 'a';
        int j = 0, u;
        for (int i = 2; i < 10; i++)
        {
            j = 0;
            if (i == 7 || i == 9)
                u = 4;
            else
                u = 3;
            while (j < u)
            {
                a[i].push_back(c++);
                j++;
            }
        }
    }
    void dfs(string digits, int idx, vector<string> &ans, vector<vector<char>> a, string s = "")
    {
        if (idx >= digits.size())
        {
            ans.push_back(s);
            return;
        }
        for (char c : a[digits[idx] - '0'])
            dfs(digits, idx + 1, ans, a, s + c);
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<vector<char>> a(10);
        vector<string> ans;
        preCompute(a);
        // for (int i = 2; i <= 9; ++i)
        // {
        //     cout << i << "->";
        //     for (char c : a[i])
        //         cout << c << " ";
        //     cout << '\n';
        // }
        dfs(digits, 0, ans, a);
        return ans;
    }
};

int main()
{
    string digits;
    cin >> digits;

    vector<string> ans = Solution().letterCombinations(digits);
    for (string s : ans)
        cout << s << " ";
}