#include <bits/stdc++.h>

using namespace std;

//   Global and Local Inversions

class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (abs(i - A[i]) > 1)
                return false;
        }
        return true;
    }
};