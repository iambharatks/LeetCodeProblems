#include <bits/stdc++.h>

using namespace std;
//   Check Array Formation Through Concatenation
class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]] = i + 1;
        for (int i = 0; i < pieces.size(); ++i)
        {
            if (pieces[i].size() == 1 && mp[pieces[i][0]])
                continue;
            if (pieces[i].size() > 1 && mp[pieces[i][0]])
            {
                int idx = mp[pieces[i][0]];
                for (int j = 1; j < pieces[i].size(); j++)
                {
                    if (idx >= arr.size())
                        return false;
                    if (arr[idx] == pieces[i][j])
                        idx++;  
                    else
                        return false;
                }
            }
            else
                return false;
        }
        return true;
    }
};
int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cin >> m;
    vector<vector<int>> pieces(m);
    for (auto &v : pieces)
    {
        int size;
        cin >> size;
        v.resize(size, 0);
        for (int &i : v)
            cin >> i;
    }
    cout << Solution().canFormArray(arr, pieces);
}