#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    long long n;

public:
    Solution(long long number)
    {
        n = number;
    }
    long long arrangeCoin()
    {
        //1.Method
        // int i = 1;
        // while (n - i >= 0)
        // {
        //     n -= i;
        //     i++;
        // }
        // return i-1;
        //Method 2. Formula
        return  (int)(sqrt(2*n + 0.25) - 0.5);
    }
};

int main()
{
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Solution a(n);
    cout<<a.arrangeCoin()<<"\n";
    return 0;
}