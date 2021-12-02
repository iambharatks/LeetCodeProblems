#include <bits/stdc++.h>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !(head->next) || !(head->next->next))
        {
            return head;
        }
        ListNode *cur, *next;
        ListNode *h1 = head;
        ListNode *h2 = head->next;
        cur = h1, next = h2;
        bool isOdd = true;
        ListNode *lastOdd = cur;
        while (next)
        {
            cur->next = next->next;
            cur = next;
            next = next->next;
            isOdd = !isOdd;
            if (isOdd)
                lastOdd = cur;
        }
        lastOdd->next = h2;
        return h1;
    }
};