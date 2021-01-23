#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (n == 0)
            return {};
        int m = mat[0].size();
        if (m == 0)
            return {{}};
        vector<vector<int>> diagonals(n + m - 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diagonalId = i - j;
                diagonalId = n - 1 - diagonalId;
                diagonals[diagonalId].push_back(mat[i][j]);
            }
        }
        for (auto &diagonal : diagonals)
            sort(diagonal.begin(), diagonal.end());
        vector<vector<int>> sortedMat(n, vector<int>(m, 0));
        for (int d = 0; d < n + m - 1; d++)
        {
            int diagonalId = n - 1 - d;
            int j = diagonalId < 0 ? diagonalId * (-1) : 0;
            int i = (diagonalId <= 0) ? 0 : diagonalId - j;
            int x = 0;
            while (i < n && j < m)
                sortedMat[i++][j++] = diagonals[d][x++];
        }

        return sortedMat;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (auto &v : mat)
        for (int &i : v)
            cin >> i;
    vector<vector<int>> sortedMat;
    sortedMat = Solution().diagonalSort(mat);
    for (auto v : sortedMat)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
}