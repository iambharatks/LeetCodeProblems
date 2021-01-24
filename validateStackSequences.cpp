#include <bits/stdc++.h>

using namespace std;

// Validate Stack Sequences

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        queue<int> inputQ, outputQ;
        for (int i : pushed)
            inputQ.push(i);
        for (int i : popped)
            outputQ.push(i);
        stack<int> tmpS;
        while (!inputQ.empty())
        {
            int ele = inputQ.front();
            inputQ.pop();
            if (ele == outputQ.front())
            {
                outputQ.pop();
                while (!tmpS.empty() && tmpS.top() == outputQ.front())
                {
                    tmpS.pop();
                    outputQ.pop();
                }
            }
            else
                tmpS.push(ele);
        }
        return tmpS.empty() && inputQ.empty();
    }
};