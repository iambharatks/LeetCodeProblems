#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countOnes(string s)
    {
        int cnt = 0;
        for (char i : s)
            if (i == '1')
                cnt++;
        return cnt;
    }
    static bool comparator(pair<int, int> a, pair<int, int> b)
    {
        
        return abs(a.first - a.second) < abs(b.first - b.second);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int cnt = 0;
        vector<pair<int, int>> bs(strs.size());
        for (int i = 0; i < strs.size(); i++)
        {
            cnt = countOnes(strs[i]);
            bs[i] = {strs[i].size() - cnt, cnt};
        }
        sort(bs.begin(), bs.end(), comparator);
        cnt = 0;
        for (auto p : bs)
            if (m >= p.first && n >= p.second)
            {
                m -= p.first;
                n -= p.second;
                cnt++;
            }
        return cnt;
    }
};

int main()
{
    int m, n, N;
    cin >> N;
    cin >> m >> n;
    vector<string> strs(N);
    for (string &s : strs)
        cin >> s;
    cout << Solution().findMaxForm(strs, m, n);
}