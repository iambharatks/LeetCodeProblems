#include <bits/stdc++.h>

using namespace std;

class Node
{
    Node *links[26];

public:
    bool end = false;

    bool containsKey(char &c)
    {
        return links[c - 'a'] != NULL;
    }
    void putKey(char &c)
    {
        links[c - 'a'] = new Node();
    }
    Node *getKey(char &c)
    {
        return links[c - 'a'];
    }
    void setEnd() { end = true; }
    bool isEnd() { return end; }
};

class StreamChecker
{
    Node *root;
    string suffix;
    size_t maxLength;
    void insert(string &word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
                node->putKey(c);
            node = node->getKey(c);
        }
        node->setEnd();
    }
    bool search(string &word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (node->containsKey(c))
            {
                node = node->getKey(c);
            }
            else
            {
                return false;
            }
            if (node->isEnd())
                return true;
        }
        return node->isEnd();
    }

public:
    StreamChecker(vector<string> &words)
    {
        root = new Node();
        suffix = "";
        maxLength = 0;
        for (string word : words)
        {
            reverse(word.begin(), word.end());
            insert(word);
            maxLength = max(maxLength, word.size());
        }
    }

    bool query(char letter)
    {
        suffix.push_back(letter);
        reverse(suffix.begin(), suffix.end());
        if (suffix.size() > maxLength)
            suffix.pop_back();
        bool res = search(suffix);
        reverse(suffix.begin(), suffix.end());
        return res;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */