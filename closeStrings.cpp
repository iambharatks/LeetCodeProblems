#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        const int l1 = word1.length();
        const int l2 = word2.length();
        if (l1 != l2)
            return false;
        vector<int> f1(26), f2(26);
        vector<int> s1(26), s2(26);
        for (char c : word1)
            ++f1[c-'a'], s1[c-'a'] = 1;
        for (char c : word2)
            ++f2[c-'a'], s2[c-'a'] = 1;
        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));
        for(int i : s1)
            cout<<i;
        cout<<'\n';
        for(int i : s2)
            cout<<i;
        cout<<'\n';
        return f1 == f2 && s1 == s2;
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    if (Solution().closeStrings(word1, word2))
        cout << "Close strings\n";
    else
        cout << "Not close strings\n";
}