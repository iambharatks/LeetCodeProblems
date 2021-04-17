#include <bits/stdc++.h>

using namespace std;

//   Remove All Adjacent Duplicates in String II


//Time Complexity := O(n*n/k)
//Time Limit Exceeded
class Solution1
{
public:
    //recursive
    // string removeDuplicates(string s, int k)
    // {
    //     for (int i = 1, cnt = 1; i < s.size(); i++)
    //     {
    //         if (s[i] != s[i - 1])
    //             cnt = 1;
    //         else if (++cnt == k)
    //             return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
    //     }
    //     return s;
    // }

    //iterative
    string removeDuplicates(string s, int k, bool replaced = true)
    {
        while (replaced)
        {
            replaced = false;
            for (auto i = 1, cnt = 1; i < s.size() && !replaced; ++i)
            {
                if (s[i] != s[i - 1])
                    cnt = 1;
                else if (++cnt == k)
                {
                    s = s.substr(0, i - k + 1) + s.substr(i + 1);
                    replaced = true;
                }
            }
        }
        return s;
    }
};

//Time Complexity := O(n)
//Space Complexity := O(n)
//Best
class Solution2
{
public:
    string removeDuplicates(string s, int k)
    {
        int j = 0;
        vector<int> cnt(s.size(), 1);
        for (auto i = 0; i < s.size(); ++i, ++j)
        {
            s[j] = s[i];
            if (j > 0 && s[j] == s[j - 1])
                cnt[j] = cnt[j - 1] + 1;
            else
                cnt[j] = 1;
            if (cnt[j] == k)
                j -= k;
        }
        return s.substr(0, j);
    }
};

//Time Complexity := O(n)
//Space Complexity := O(n)
class Solution3
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        string res = "";
        for (char ch : s)
        {
            if (st.empty() || st.top().first != ch)
                st.push({ch, 0});
            if (++st.top().second == k)
                st.pop();
        }
        while (!st.empty())
        {
            res = string(st.top().second, st.top().first) + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    int k;
    string s;

    cin >> s >> k;
    cout << Solution1().removeDuplicates(s, k);
}