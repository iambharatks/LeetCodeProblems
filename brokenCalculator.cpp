#include <bits/stdc++.h>

using namespace std;

//   Broken Calculator

class Solution
{
public:
    int brokenCalc(int X, int Y)
    {
        int operations = 0;
        while (X != Y)
        {
            if (X > Y)
                return operations + (X - Y);
            if (Y & 1)
            {
                Y++;
                operations++;
            }
            Y /= 2;
            operations++;
        }
        return operations;
    }
};
int main()
{
    int x, y;
    cin >> x >> y;
    cout << Solution().brokenCalc(x, y);
}