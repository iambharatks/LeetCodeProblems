#include <bits/stdc++.h>

using namespace std;

//  Check if the Sentence Is Pangram

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<bool> f(26, false);
        for (char c : sentence)
        {
            if (f[c - 'a'])
                continue;
            f[c - 'a'] = true;
        }
        for (bool b : f)
            if (!b)
                return false;
        return true;
    }
};