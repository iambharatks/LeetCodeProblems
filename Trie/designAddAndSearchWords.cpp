#include <bits/stdc++.h>

using namespace std;

class Node
{
    Node *links[26];
    bool end = false;

public:
    bool containsKey(char c) { return links[c - 'a'] != NULL; }
    void putKey(char c) { links[c - 'a'] = new Node(); }
    Node *getKey(char c) { return links[c - 'a']; }
    void setEnd() { end = true; }
    bool isEnd() { return end; }
};

class WordDictionary
{
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
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
    bool search(string word)
    {
        return search(word, root, 0);
    }
    bool search(string &word, Node *node, int i)
    {
        if (i == word.size())
            return node->isEnd();

        if (word[i] == '.')
        {
            for (int j = 0; j < 26; j++)
                if (node->containsKey(char(j + 'a')) && search(word, node->getKey(char(j + 'a')), i + 1))
                    return true;
            return false;
        }
        return node->containsKey(word[i]) && search(word, node->getKey(word[i]), i + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */