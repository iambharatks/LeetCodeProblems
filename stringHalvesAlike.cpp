#include <bits/stdc++.h>

using namespace std;

//   Determine if String Halves Are Alike

class Solution
{
public:
    bool isVowel(char c) { return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'); }
    bool halvesAreAlike(string s)
    {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
            if (isVowel(s[i]))
                if (i < (s.size() / 2))
                    left++;
                else
                    right++;
        return left == right;
    }
};
