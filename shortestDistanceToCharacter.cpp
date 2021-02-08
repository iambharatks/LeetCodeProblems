#include <bits/stdc++.h>

using namespace std;
//  Shortest Distance to a Character

class SolutionQueue
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
//100%
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int idx = 0;
        int N = s.size();
        int prev = INT_MIN / 2;
        // INT_MIN/2 to prevent integer overflow
        vector<int> ans(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (s[i] == c)
                prev = i;
            ans[i] = i - prev;
        }
        prev = INT_MAX / 2;
        // INT_MAX/2 to prevent integer overflow
        for (int i = N - 1; i >= 0; i--)
        {
            if (s[i] == c)
                prev = i;
            ans[i] = min(ans[i], prev - i);
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