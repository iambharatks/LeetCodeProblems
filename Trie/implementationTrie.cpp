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

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
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
        Node *node = root;
        for (char c : word)
        {
            if (node->containsKey(c))
                node = node->getKey(c);
            else
                return false;
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char c : prefix)
        {
            if (node->containsKey(c))
                node = node->getKey(c);
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */