#include <bits/stdc++.h>

using namespace std;
//   Copy List with Random Pointer

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
    unordered_map<Node *, Node *> created;

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *newNode = new Node(head->val);
        created[head] = newNode;
        newNode->next = copyRandomList(head->next);
        if (head->random)
            newNode->random = created[head->random];
        return newNode;
    }
};