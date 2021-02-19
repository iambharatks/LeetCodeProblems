#include <bits/stdc++.h>

using namespace std;

//   Minimum Remove to Make Valid Parentheses

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int constant = 0, cnt = 0;
        int n = s.size();
        vector<bool> ignore(n, false);
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '(')
                constant++;
            else if (c == ')' && constant == 0)
            {
                ignore[i] = true;
                cnt++;
                continue;
            }
            else if (c == ')')
                constant--;
        }
        constant = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (ignore[i])
                continue;
            char c = s[i];
            if (c == '(' && constant == 0)
            {
                ignore[i] = true;
                cnt++;
                continue;
            }
            if (c == '(')
                constant++;
            else if (c == ')')
                constant--;
        }
        string tmp = "";
        for (int i = 0; i < n; i++)
        {
            if (!ignore[i])
                tmp += s[i];
        }
        return tmp;
    }
};
int main()
{
    string s;
    cin >> s;
    cout << Solution().minRemoveToMakeValid(s);
}