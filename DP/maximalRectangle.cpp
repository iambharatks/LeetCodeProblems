#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAreaRectangle(vector<int> &h)
    {
        int maxArea = 0;
        int n = h.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || h[st.top()] < h[i])
                st.push(i);
            else
            {
                int tp, lp;
                while ((!st.empty()) && h[st.top()] >= h[i])
                {
                    tp = st.top();
                    st.pop();
                    lp = st.empty() ? -1 : st.top();
                    maxArea = max(maxArea, (i - lp - 1) * h[tp]);
                }
                st.push(i);
            }
        }
        int lp, tp;
        while (!st.empty())
        {
            tp = st.top();
            st.pop();
            lp = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (n - lp - 1) * h[tp]);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i] - '0';
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;
                // cout<<dp[i][j]<<' ';
            }
            // cout<<endl;
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, maxAreaRectangle(dp[i]));
        }
        return maxArea;
    }
};