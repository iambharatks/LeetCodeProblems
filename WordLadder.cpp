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
        return shortestChain(beginWord, endWord, words);
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
