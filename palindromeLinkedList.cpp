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
    ListNode *reverse(ListNode **head, ListNode *end)
    {
        ListNode *current, *prev, *next;
        prev = NULL;
        current = *head;
        while (current != end)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid, *current, *left, *right;
        mid = head, current = head;
        while (current && current->next)
        {
            mid = mid->next;
            current = current->next->next;
        }

        if (current)
            right = mid->next;
        else
            right = mid;

        left = reverse(&head, mid);

        //         while (left)
        //         {
        //             cout << left->val << " ";
        //             left = left->next;
        //         }

        //         while (right)
        //         {
        //             cout << right->val << " ";
        //             right = right->next;
        //         }

        while (left && right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
