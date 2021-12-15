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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *j = head->next;
        ListNode *cur = head;
        while (j)
        {
            ListNode *i = head;
            ListNode *prev = NULL;
            ListNode *next = j->next;
            while (i->val < j->val)
            {
                prev = i;
                i = i->next;
            }
            if (prev != NULL)
            {
                prev->next = j;
            }
            else
            {
                head = j;
            }
            if (i == j)
                cur = j;
            j->next = i;
            cur->next = next;
            j = next;
        }
        return head;
    }
};