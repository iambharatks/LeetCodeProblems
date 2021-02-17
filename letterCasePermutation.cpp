#include <bits/stdc++.h>

using namespace std;
//   Letter Case Permutation

class Solution
{
public:
    void traverse(string &s, int i, vector<string> &ans, string res = "")
    {
        if (i == s.size())
        {
            ans.push_back(res);
            return;
        }
        if (s[i] >= '0' && s[i] <= '9')
            return traverse(s, i + 1, ans, res + s[i]);
        else
        {
            traverse(s, i + 1, ans, res + s[i]);
            if (s[i] >= 'A' && s[i] <= 'Z')
                traverse(s, i + 1, ans, res + char(s[i] + 32));
            else
                traverse(s, i + 1, ans, res + char(s[i] - 32));
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        traverse(S, 0, ans);
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    vector<string> perm = Solution().letterCasePermutation(s);
    for (string word : perm)
        cout << word << " ";
}