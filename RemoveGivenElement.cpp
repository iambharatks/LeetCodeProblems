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
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            head = head->next;
        }
        ListNode *current = head, *prev = head;
        while (current)
        {
            if (current->val == val)
            {
                prev->next = current->next;
                current = current->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode **prev = &head;
        while (*prev)
        {
            if ((*prev)->val == val)
            {
                *prev = (*prev)->next;
            }
            else if (*prev)
            {
                prev = &(*prev)->next;
            }
        }
        return head;
    }
};