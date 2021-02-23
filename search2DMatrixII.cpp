#include <bits/stdc++.h>

using namespace std;

//   Search a 2D Matrix II

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                j++;
            else
                i--;
        }
        return false;
    }
};

int main()
{
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto &v : matrix)
        for (int &i : v)
            cin >> i;
    cout << Solution().searchMatrix(matrix, target);
}