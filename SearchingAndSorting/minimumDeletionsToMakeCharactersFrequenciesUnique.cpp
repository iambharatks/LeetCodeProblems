#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;
        int cost = 0;
        sort(freq, freq + 26);
        for (int i = 24; i >= 0; i--)
        {
            if (freq[i] != 0 && freq[i] >= freq[i + 1])
            {
                cost += min(freq[i], freq[i] - freq[i + 1] + 1);
                freq[i] = max(0, freq[i + 1] - 1);
            }
        }
        return cost;
    }
};
class Solution
{
public:
    int minDeletions(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        sort(freq, freq + 26);
        int cost = 0;
        for (int i = 24; i >= 0;)
        {
            if (freq[i] && freq[i] == freq[i + 1])
            {
                while (true)
                {
                    freq[i]--;
                    cost++;
                    int it = lower_bound(freq, freq + i, freq[i]) - freq;
                    if (it == i || freq[it] > freq[i] || freq[i] == 0)
                        break;
                }
                sort(freq, freq + i + 1);
            }
            else
            {
                i--;
            }
        }
        return cost;
    }
};