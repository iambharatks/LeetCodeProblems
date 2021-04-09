#include <bits/stdc++.h>

using namespace std;

// Verifying an Alien Dictionary

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int alph[26];
        for (int i = 0; i < 26; i++)
            alph[order[i] - 'a'] = 'a' + i;
        for (string &word : words)
            for (char &c : word)
                c = alph[c - 'a'];
        for (int i = 1; i < words.size(); i++)
        {
            if (words[i] < words[i - 1])
                return false;
        }
        return true;
    }
};
