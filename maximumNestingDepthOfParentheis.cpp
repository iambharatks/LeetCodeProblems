#include <iostream>

using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0, _max = 0;
        for (char i : s)
        {
            if (i == '(')
            {
                count++;
                _max = max(_max, count);
            }
            else if (i == ')')
            {
                count--;
            }
        }
        return _max;
    }
};