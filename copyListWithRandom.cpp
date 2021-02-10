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
//recursive
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
//iterative
class Solution
{
    unordered_map<Node *, Node *> created;

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *current = head;
        Node *newHead = NULL, *prev;
        while (current)
        {
            Node *newNode = new Node(current->val);
            created[current] = newNode;
            current = current->next;
            if (!newHead)
                newHead = newNode;
            else
                prev->next = newNode;
            prev = newNode;
        }
        current = head;

        while (current)
        {
            if (current->random)
                created[current]->random = created[current->random];
            current = current->next;
        }
        return created[head];
    }
};