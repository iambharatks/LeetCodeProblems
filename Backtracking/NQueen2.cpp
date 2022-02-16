#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool col[10], diagonal1[20], diagonal2[20];
    int N;
    int cnt = 0;
    void dfs(int n)
    {
        if (n <= 0)
        {
            cnt++;
            return;
        }
        for (int c = 0; c < N; c++)
        {
            if (!col[c] && !diagonal1[c + n] && !diagonal2[N - n + c])
            {
                col[c] = diagonal1[c + n] = diagonal2[N - n + c] = true;
                dfs(n - 1);
                col[c] = diagonal1[c + n] = diagonal2[N - n + c] = false;
            }
        }
    }
    int totalNQueens(int n)
    {
        N = n;
        dfs(n);
        return cnt;
    }
};