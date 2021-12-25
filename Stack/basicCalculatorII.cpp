#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int eval(stack<int> &nums, stack<char> &op)
    {
        int n1 = nums.top();
        nums.pop();
        int n2 = nums.top();
        nums.pop();
        char c = op.top();
        op.pop();
        if (c == '+')
            return n1 + n2;
        else if (c == '-')
            return n2 - n1;
        else if (c == '*')
            return n2 * n1;
        return n2 / n1;
    }
    int calculate(string s)
    {
        stack<char> operators;
        stack<int> nums;
        int i = 0, n = s.size();
        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
            }
            else
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    while (!operators.empty())
                        nums.push(eval(nums, operators));
                    operators.push(s[i]);
                }
                else
                {
                    while (!operators.empty() && (operators.top() == '/' || operators.top() == '*'))
                        nums.push(eval(nums, operators));
                    operators.push(s[i]);
                }
                i++;
            }
        }
        while (!operators.empty())
            nums.push(eval(nums, operators));
        return nums.top();
    }
};