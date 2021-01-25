#include <bits/stdc++.h>

using namespace std;

//   Check If All 1's Are at Least Length K Places Away
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int lastPos = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (lastPos == -1 || i - lastPos > k)
                    lastPos = i;
                else
                    return false;
            }
        }
        return true;
    }
};