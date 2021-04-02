#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxFormUtil(vector<string> &strs, int m, int n, int idx, int mi, int ni, int cnt)
    {
        if (mi == m && ni == n)
            return cnt;
        if (idx <= 0)
            return 0;
        
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
    }
};

int main()
{
    int m, n, N;
    cin >> m >> n;
    vector<string> strs(N);
    for (string &s : strs)
        cin >> s;
    cout << Solution().findMaxForm(strs, m, n);
}