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
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *mid = head, *prev = NULL;
        if (!head)
        {
            return true;
        }
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = mid;
            mid = mid->next;
        }
        ListNode *next = NULL;
        ListNode *current = NULL, *p = NULL;
        if (!fast)
        {
            current = mid;
        }
        else
        {
            current = mid->next;
            prev = mid;
        }
        while (current)
        {
            next = current->next;
            current->next = p;
            p = current;
            current = next;
        }
        prev->next = p;
        while (p)
        {
            if (head->val != p->val)
            {
                return false;
            }
            head = head->next;
            p = p->next;
        }
        return true;
    }
};
