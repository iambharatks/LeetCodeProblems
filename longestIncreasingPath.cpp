#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int i, j, n, m, ans = 0;
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (matrix[i][j] < matrix[i + 1][j])
                    dp[i + 1][j] = max(dp[i][j] + 1, dp[i + 1][j]);
                if (matrix[i][j] < matrix[i][j + 1])
                    dp[i][j + 1] = max(dp[i][j] + 1, dp[i][j + 1]);
                ans = max(ans, dp[i][j]);
            }
        }
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
                cout << dp[i][j] << " ";
            cout << '\n';
        }
        return ans;
    }
};

int main()
{
    unordered_set<int> s;
    int m, n;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (auto &v : matrix)
        for (auto &i : v)
            cin >> i;
    cout << Solution().longestIncreasingPath(matrix);
}