#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> A, int low, int high)
    {
        cout << A[low] << "  " << A[high] << "\n";
        if (high < low)
            return -1;
        if (A[low] < 0)
            return low;
        if (A[high] > 0)
            return -1;
        int mid = low + (high - low) / 2;
        if (mid > 0 && A[mid] < 0 && A[mid - 1] >= 0)
            return mid;
        if (mid < A.size() - 1 && A[mid] >= 0 && A[mid + 1] < 0)
            return mid + 1;
        if (A[mid] >= 0 && mid < A.size() - 1)
            return binarySearch(A, mid + 1, high);
        else if (A[mid] < 0 && mid > 0)
            return binarySearch(A, low, mid - 1);
    }
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int pos = binarySearch(grid[i], 0, grid[i].size() - 1);
            if (pos != -1)
                count += (grid[i].size() - pos);
        }
        return count;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> A(n);
    for (vector<int> &v : A)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    Solution solve;
    int t = solve.countNegatives(A);
    cout << t << "\n";
    return 0;
}
// PS D:\Bharat\LeetCode> .\negativenosINmatrix.exe
// 5
// 10
// 10 1 -3 -4 -5 -6 -7 -8 -9 -100
// 10
// -1 -2 -3 -4 -5 -6 -7 -8 -9 -10
// 10
// 10
// -1 -1 -1 -1 5 -6 -7 -8 -9 -10
// 10
// 1 1 1 0 -1  -5 -6 -7 -8 -9
// 10
// 1 1 1 0 -1  -5 -6 -7 -8 -9