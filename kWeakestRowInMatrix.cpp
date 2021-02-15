#include <bits/stdc++.h>

using namespace std;
//   The K Weakest Rows in a Matrix


class Solution
{
public:
    int numberOfSoldiers(vector<int> &row)
    {
        int low = 0, high = row.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (mid < high && row[mid] == 1 && row[mid + 1] == 0)
                return mid;
            else if (mid > low && row[mid] == 0 && row[mid - 1] == 1)
                return mid - 1;
            else if (row[mid] == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return (row[0] == 0) ? -1 : row.size() - 1;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        vector<pair<int, int>> rows(n);
        vector<int> ans(k);
        for (int i = 0; i < n; i++)
            rows[i] = {numberOfSoldiers(mat[i]), i};
        sort(rows.begin(), rows.end());
        for (int i = 0; i < k; i++)
            ans[i] = rows[i].second;
        return ans;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto &v : mat)
        for (int &i : v)
            cin >> i;
    cin >> k;
    vector<int> ans = Solution().kWeakestRows(mat, k);
    for (int i : ans)
        cout << i << " ";
}