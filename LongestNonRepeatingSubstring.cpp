#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, prev = 0;
        vector<int> lastPos(256, -1);
        for (int i = 0; i < s.size(); i++)
        {
            prev = max(prev, lastPos[s[i]] + 1);
            ans = max(ans, i - prev + 1);
            lastPos[s[i]] = i;
        }
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s) << " ";
}