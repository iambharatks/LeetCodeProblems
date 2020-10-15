#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator start = s.begin();
        string::iterator end = s.end()-1;
        while (start < end) {
            if (*start >= 65 && *start <= 90) {
                *start += 32;
            }
            if (*end >= 65 && *end <= 90) {
                *end += 32;
            }
            if (*start < 48 || ( *start > 57 && *start < 97) || *start > 122) {
                start++;
                continue;
            }
            if (*end < 48 || ( *end > 57 && *end < 97) ||*end > 122) {
                end--;
                continue;
            }
            cout<<*start<<"  "<<*end<<"\n";
            if (*start != *end) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin, s);
    Solution solve;
    if (solve.isPalindrome(s))
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}