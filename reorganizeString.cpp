#include <bits/stdc++.h>

using namespace std;
// Reorganize String

//Important Solution
//Time Complexity := O(n*aloga)
//Space Complexity := O(a)
//In this question ,I learnt a new concept how to
//sort and store alphabet info in frequency array
class Solution1
{
public:
    string reorganizeString(string S)
    {
        int N = S.size();
        int *counts = new int[26]{0};
        for (char c : S)
            counts[c - 'a']++;
        //creating code
        for (int i = 0; i < 26; i++)
            counts[i] = 100 * counts[i] + i;
        sort(counts, counts + 26);
        int t = 1;
        for (int i = 0; i < 26; i++)
        {
            int code = counts[i];
            int cnt = code / 100;
            int a = code % 100;
            if (cnt > (N + 1) / 2)
                return "";
            for (int j = 0; j < cnt; j++)
            {
                if (t >= N)
                    t = 0;
                S[t] = char('a' + a);
                t += 2;
            }
        }
        return S;
    }
};
//Better Approach
//Time Complexity := O(n + aloga)
//Space Complexity := O(a)
//Method 2
//Using greedy + heap
class Solution2
{

    struct comparator
    {
        bool operator()(pair<int, char> x, pair<int, char> y) { return x.first < y.first; }
    };
    string reorganizeString(string S)
    {
        int N = S.size();
        int *counts = new int[26]{0};
        for (char c : S)
            counts[c - 'a']++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, comparator> pq;
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] > (N + 1) / 2)
                return "";
            if (counts[i])
                pq.push({counts[i], i + 'a'});
        }
        pair<int, char> prev = {-1, '#'};
        string ans = "";
        while (!pq.empty())
        {
            pair<int, char> current = pq.top();
            pq.pop();
            ans += current.second;
            current.first--;
            if (prev.first > 0)
                pq.push(prev);
            prev = current;
        }
        return ans;
    }
};