#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 && i + 1 < n)
            {
                for (int j = n - 1; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                for (int i : arr)
                    cout << i << " ";
                cout << "\n";
                arr[i + 1] = arr[i];
                i++;
            }
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a;
        while (n--)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution s;
        s.duplicateZeros(a);
        for (int i : a)
            cout << i << " ";
        cout << "\n";
    }
}