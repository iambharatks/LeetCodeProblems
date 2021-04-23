#include <bits/stdc++.h>

using namespace std;

// Number of Different Integers in a String

class Solution
{
    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9');
    }

public:
    int numDifferentIntegers(string word)
    {
        string num = "";
        set<string> nums;
        for (int i = 0; i < word.size(); i++)
        {
            if (isDigit(word[i]))
            {
                if (num == "0")
                    num = "";
                num += word[i];
                // cout << num << " ";
            }
            else if (num != "")
            {
                nums.insert(num);
                // cout << num << " ";
                num = "";
            }
        }
        if (isDigit(word.back()))
            nums.insert(num);
        return nums.size();
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().numDifferentIntegers(s);
}