#include <bits/stdc++.h>

using namespace std;

//  Minimum Number of Operations to Reinitialize a Permutation

//TLE
class BruteForce
{
public:
    bool equal(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    int reinitializePermutation(int n)
    {
        int ans = 0;
        vector<int> perm(n), arr(n);
        iota(perm.begin(), perm.end(), 0);
        while (perm != arr)
        {
            ans++;
            for (int i = 0; i < n; i++)
            {
                if (i & 1)
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                else
                    arr[i] = perm[i / 2];
                cout << arr[i];
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        int i = 1, cnt = 0;
        do
        {
            cnt++;
            if (i & 1)
                i = (n / 2) + ((i - 1) >> 1);
            else
                i >>= 1;
        } while (i != 1);
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().reinitializePermutation(n);
}