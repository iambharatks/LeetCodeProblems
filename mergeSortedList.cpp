#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode **headref = &head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                *headref = new ListNode(l1->val);
                l1 = l1->next;
                headref = &((*headref)->next);
            }
            else
            {
                *headref = new ListNode(l2->val);
                l2 = l2->next;
                headref = &((*headref)->next);
            }
        }
        while (l1)
        {
            *headref = new ListNode(l1->val);
            l1 = l1->next;
            headref = &((*headref)->next);
        }
        while (l2)
        {
            *headref = new ListNode(l2->val);
            l2 = l2->next;
            headref = &((*headref)->next);
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode **headref = &head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                *headref = l1;
                l1 = l1->next;
                headref = &((*headref)->next);
            }
            else
            {
                *headref = l2;
                l2 = l2->next;
                headref = &((*headref)->next);
            }
        }
        while (l1)
        {
            *headref = l1;
            l1 = l1->next;
            headref = &((*headref)->next);
        }
        while (l2)
        {
            *headref = l2;
            l2 = l2->next;
            headref = &((*headref)->next);
        }
        return head;
    }
};