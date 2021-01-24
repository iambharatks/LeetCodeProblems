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
    ListNode *merge2Lists(ListNode *h1, ListNode *h2)
    {
        ListNode *newHead = NULL, *prev = NULL;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                ListNode *newNode = h1;
                if (!newHead)
                    newHead = newNode;
                else
                    prev->next = newNode;
                prev = newNode;
                h1 = h1->next;
            }
            else
            {
                ListNode *newNode = h2;
                if (!newHead)
                    newHead = newNode;
                else
                    prev->next = newNode;
                prev = newNode;
                h2 = h2->next;
            }
        }
        if (h1)
        {
            if (!newHead)
                newHead = h1;
            else
                prev->next = h1;
        }
        if (h2)
        {
            if (!newHead)
                newHead = h2;
            else
                prev->next = h2;
        }
        return newHead;
    }
    void print(ListNode *h)
    {
        while (h)
        {
            cout << h->val << " ";
            h = h->next;
        }
        cout << "\n";
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *mergedHead = NULL;
        for (int i = 0; i < lists.size(); ++i)
        {
            mergedHead = merge2Lists(mergedHead, lists[i]);
            // print(mergedHead);
        }
        return mergedHead;
    }
};