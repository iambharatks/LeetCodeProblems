#include <bits/stdc++.h>

using namespace std;
//   Check If Two String Arrays are Equivalent
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string str1 = "", str2 = "";
        for (string s : word1)
            str1 += s;
        for (string s : word2)
            str2 += s;
        return (str1.compare(str2) == 0);
    }
};