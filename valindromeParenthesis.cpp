#include <bits/stdc++.h>

using namespace std;

//   Valid Parentheses
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                brackets.push(c);
                break;
            case ')':
                if (brackets.empty() || brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case '}':
                if (brackets.empty() || brackets.top() != '{')
                    return false;
                brackets.pop();
                break;
            case ']':
                if (brackets.empty() || brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
            }
        }
        return brackets.empty();
    }
};