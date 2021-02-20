#include <bits/stdc++.h>

using namespace std;

// Roman To Integer

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;

        if (s.find("IV") != string::npos)
            ans -= 2;
        if (s.find("IX") != string::npos)
            ans -= 2;
        if (s.find("XL") != string::npos)
            ans -= 20;
        if (s.find("XC") != string::npos)
            ans -= 20;
        if (s.find("CD") != string::npos)
            ans -= 200;
        if (s.find("CM") != string::npos)
            ans -= 200;

        for (int count = 0; count < s.length(); ++count)
        {
            if (s[count] == 'M')
                ans += 1000;
            if (s[count] == 'D')
                ans += 500;
            if (s[count] == 'C')
                ans += 100;
            if (s[count] == 'L')
                ans += 50;
            if (s[count] == 'X')
                ans += 10;
            if (s[count] == 'V')
                ans += 5;
            if (s[count] == 'I')
                ans += 1;
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().romanToInt(s);
}