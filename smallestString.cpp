#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string s(n, 'a');
        while (n < k && k - (n - 1) > 26)
            k -= 26, s[--n] = 'z';
        if (n != k)
        {
            s[--n] = char('a' + (k - n) - 1);
            k = n;
        }
        return s;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    cout << Solution().getSmallestString(n, k);
}