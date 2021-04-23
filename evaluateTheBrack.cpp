#include <bits/stdc++.h>

using namespace std;

// Evaluate the Bracket Pairs of a String

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        map<string, string> dict;
        for (vector<string> v : knowledge)
            dict[v[0]] = v[1];
        string tmp = "", ans = "";
        bool tgl = false;
        for (char ch : s)
        {
            if (ch == '(')
            {
                tgl = true;
                continue;
            }
            if (ch == ')' && tgl)
            {
                tgl = false;
                if (!(dict[tmp].empty()))
                    ans += dict[tmp];
                else
                    ans += '?';
                tmp = "";
                continue;
            }
            if (tgl)
                tmp += ch;
            else
                ans += ch;
        }
        return ans;
    }
};
