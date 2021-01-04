#include <bits/stdc++.h>

using namespace std;

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l = NULL, *prev;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                if (l == NULL)
                    l = l1;
                else
                    prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
            else
            {
                if (l == NULL)
                    l = l2;
                else
                    prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }

        if (l1)
        {
            if (l == NULL)
                return l1;
            else
                prev->next = l1;
            return l;
        }
        if (l2)
        {
            if (l == NULL)
                return l2;
            else
                prev->next = l2;
            return l;
        }
        return l;
    }
};