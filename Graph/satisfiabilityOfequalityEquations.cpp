#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char par[26];
    int size[26];

    char findSet(char c)
    {
        if (par[c - 'a'] == c)
            return c;
        return par[c - 'a'] = findSet(par[c - 'a']);
    }
    void unionSet(char u, char v)
    {
        u = findSet(u);
        v = findSet(v);
        if (u == v)
            return;
        if (size[u - 'a'] > size[v - 'a'])
            swap(u, v);
        par[v - 'a'] = u;
        size[u - 'a'] += size[v - 'a'];
    }
    bool inSameSet(char u, char v)
    {
        u = findSet(u);
        v = findSet(v);
        return u == v;
    }
    bool equationsPossible(vector<string> &equations)
    {
        vector<pair<vector<int>, vector<int>>> g(26);
        for (int i = 0; i < 26; i++)
        {
            par[i] = i + 'a';
            size[i] = 1;
        }
        for (string &equation : equations)
        {
            if (equation[1] == '=')
            {
                unionSet(equation[0], equation[3]);
            }
        }
        for (string &equation : equations)
        {
            if (equation[1] == '!')
            {
                if (inSameSet(equation[0], equation[3]))
                    return false;
            }
        }
        return true;
    }
};