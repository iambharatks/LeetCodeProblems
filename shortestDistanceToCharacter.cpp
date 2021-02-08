#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        queue<int> q;
        int left = -1;
        vector<int> ans;
        int right = 0;
        for (char ch : s)
        {
            if (ch == c)
            {
                while (!q.empty())
                {
                    if (left == -1)
                        ans.push_back(right - q.front());
                    else
                        ans.push_back(min(right - q.front(), q.front() - left));
                    q.pop();
                }
                left = right;
                ans.push_back(0);
            }
            else
                q.push(right);
            right++;
        }
        while (!q.empty())
        {
            ans.push_back(q.front() - left);
            q.pop();
        }
        return ans;                                                                    
    }
};

int main()
{
    char c;
    string s;
    cin >> s;
    cin >> c;
    vector<int> ans = Solution().shortestToChar(s, c);
    for (int i : ans)
        cout << i << " ";
}