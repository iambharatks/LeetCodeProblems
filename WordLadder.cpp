#include <bits/stdc++.h>

using namespace std;
// Word Ladder
class Solution
{
public:
    int shortestChain(string beginWord, string endWord, unordered_set<string> &wordList)
    {
        if (wordList.find(endWord) == wordList.end())
            return 0;
        int level = 0, wordLength = beginWord.size();
        queue<string> Q;
        Q.push(beginWord);
        while (!Q.empty())
        {
            level++;
            int sizeQ = Q.size();
            for (int i = 0; i < sizeQ; ++i)
            {
                string word = Q.front();
                Q.pop();
                for (int pos = 0; pos < word.length(); ++pos)
                {
                    char orig_char = word[pos];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        word[pos] = c;
                        if (word == endWord)
                            return level + 1;
                        if (wordList.find(word) == wordList.end())
                            continue;
                        wordList.erase(word);
                        Q.push(word);
                    }
                    word[pos] = orig_char;
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words;
        for (string word : wordList)
            words.insert(word);
        int i = shortestChain(beginWord, endWord, words);
        for (string s : words)
            cout << s << " ";
        return i;
    }
};
//TLE Solution
class SolutionNaive
{
    bool isConnected(string u, string v)
    {
        int cnt = 0;
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] != v[i])
                cnt++;
        }
        return cnt == 1;
    }
    bool search(vector<string> &wordList, string word)
    {
        for (string s : wordList)
            if (s == word)
                return true;
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (!search(wordList, endWord))
            return 0;
        queue<string> q;
        unordered_map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord] = true;
        int nodes_left_in_layer = 1, nodes_in_next_layer = 0;
        int operations = 0;
        while (!q.empty())
        {
            string v = q.front();
            q.pop();
            for (string s : wordList)
            {
                if (!vis[s] && isConnected(v, s))
                {
                    if (s == endWord)
                        return operations + 2;
                    vis[s] = true;
                    q.push(s);
                    nodes_in_next_layer++;
                }
            }
            nodes_left_in_layer--;
            if (nodes_left_in_layer == 0)
            {
                swap(nodes_left_in_layer, nodes_in_next_layer);
                operations++;
            }
        }
        return -1;
    }
};

int main()
{
    vector<string> wordList;
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        wordList.push_back(s);
    }
    string start, target;
    cin >> start >> target;
    cout << Solution().ladderLength(start, target, wordList);
    return 0;
}
