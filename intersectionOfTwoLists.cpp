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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> h;
        while (headA)
        {
            h[headA] = true;
            headA = headA->next;
        }
        while (headB)
        {
            if (h[headB])
            {
                return headB;
            }
            h[headB] = true;
            headB = headB->next;
        }
        return NULL;
    }
};

//BETTER
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *head = headA;
        int a = 0, b = 0;
        while (head)
        {
            head = head->next;
            a++;
        }
        head = headB;
        while (head)
        {
            head = head->next;
            b++;
        }
        if (a > b)
        {
            int d = a - b;
            while (d--)
            {
                headA = headA->next;
            }
            while (headA && headB)
            {
                if (headA == headB && headA)
                {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        else
        {
            int d = b - a;
            while (d--)
            {
                headB = headB->next;
            }
            while (headA && headB)
            {
                if (headA == headB && headA)
                {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};