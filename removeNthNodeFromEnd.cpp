#include <bits/stdc++.h>

using namespace std;

//   Remove Nth Node From End of List

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *current = head, *prev = NULL;
        int sz = 0;
        while (current)
        {
            sz++;
            current = current->next;
        }
        current = head;
        n = sz - n;
        while (n--)
        {
            prev = current;
            current = current->next;
        }
        if (!prev)
            head = current->next;
        else
            prev->next = current->next;
        return head;
    }
}; 